/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:15:46 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/24 10:17:25 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"
#include "vector.h"

static int	hit_chk_sp(t_ray *ray, t_sphere *sp, t_rec *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	cmp;
	t_vec3	oc;

	oc = vec_minus(ray->origin, sp->coord);
    a = vec_length_squared(ray->dir);
    half_b = vec_dot(oc, ray->dir);
    c = vec_length_squared(oc) - sp->radius * sp->radius;
    cmp = half_b * half_b - a * c;
    if (cmp < 0)
		return (0);
	if (hit_chk_help(rec, sqrt(cmp), a, half_b))
		return (0);
    rec->p = vec_plus(ray->origin, vec_multi(ray->dir, rec->t));
    chk_face(ray, rec, vec_devide(vec_minus(rec->p, sp->coord), sp->radius));
	rec->color = sp->rgb;
    return (1);
}

static int	hit_chk_pl(t_ray *ray, t_plane *pl, t_rec *rec)
{
	double	numrator;
	double	denominator;
	double	root;

	denominator = vec_dot(ray->dir, pl->dir);
	if (fabs(denominator) < 0.001)
		return (0);
	numrator = vec_dot(vec_minus(pl->coord, ray->origin), pl->axis);
	root = numrator / denominator;
	if (root < rec->min || rec->max < root)
		return (0);
	rec->t = root;
    rec->p = vec_plus(ray->origin, vec_multi(ray->dir, rec->t));
	rec->normal = pl->dir;
	//chk_face(ray, rec, vec_devide(vec_minus(rec->p, sp->coord)))
	rec->color = pl->rgb;
	return (1);
}

static int	hit_chk_cy(t_ray *ray, t_cylinder *cy, t_rec *rec)
{
    double  a;
		double  half_b;
    double  c;
    t_vec3  u;
    t_vec3  o;
    t_vec3  delta_P;
    double r;

    double discriminant; // 판별식
    double sqrtd;
    double root;
    double hit_height;
    
    cy = cy_obj->element;
    u = ray->dir;
    o = cy->dir;
    r = cy->diameter / 2;
    delta_P = vminus(ray->origin, cy->center);
    a = vlength2(vcross(u, o));
    half_b = vdot(vcross(u, o), vcross(delta_P, o));
    c = vlength2(vcross(delta_P, o)) - pow(r, 2);
    discriminant = half_b * half_b - a * c;
    if (discriminant < 0) 
        return (FALSE);
    // 이 시점에서 판별식이 참이 나왔기에 근이 존재한다고 판단한다.
    sqrtd = sqrt(discriminant); 
    root = (-half_b - sqrtd) / a;  // 근의 공식 해, 작은 근부터 고려.
    if (root < rec->tmin || rec->tmax < root)
    {
    root = (-half_b + sqrtd) / a; 
        if (root < rec->tmin || rec->tmax < root)
        return (FALSE);
    }
    if (!(hit_height = cy_boundary(cy, ray_at(ray, root))))
        return (FALSE);

    rec->t = root; // 광선의 원점과 교점까지의 거리를 rec에 저장한다.
    rec->p = ray_at(ray, root); // 교점의 좌표를 rec에 저장한다.
    rec->normal = get_cylinder_normal(cy, rec->p, hit_height); // vmult(ray->dir, root)하면 안돼!!!
    set_face_normal(ray, rec);
    rec->albedo = cy_obj->albedo;
    return (TRUE);
}

int	is_hit(t_ray *ray, t_lst *objs, t_rec *rec)
{
	int		is_hit;

	is_hit = 0;
	while (objs)
	{
		if ((objs->info == F_SP && hit_chk_sp(ray, objs->data, rec)) \
			|| (objs->info == F_PL && hit_chk_pl(ray, objs->data, rec)) \
			|| (objs->info == F_CY && hit_chk_cy(ray, objs->data, rec)))
		{
			is_hit = 1;
			rec->max = rec->t;
		}
		objs = objs->nxt;
	}
    return (is_hit);
}
