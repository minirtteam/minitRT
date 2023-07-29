/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:15:46 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/29 12:09:17 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"
#include "vector.h"

static int	hit_chk_sp(t_ray *ray, t_sphere *sp, t_rec *rec)
{
	double	a;
	double	half_b;
	double	denom;
	double	root;
	t_vec3	oc;

	oc = vec_minus(ray->origin, sp->coord);
    a = vec_length_squared(ray->dir);
    half_b = vec_dot(oc, ray->dir);
    denom = pow(half_b, 2) - a * (vec_length_squared(oc) - pow(sp->radius, 2));
    if (denom < 0)
		return (0);
	denom = sqrt(denom);
	root = (-half_b - denom) / a;
	if (root < rec->min || rec->max < root)
	{
		root = (-half_b + denom) / a;
		if (root < rec->min || rec->max < root)
			 return (0);
	}
	rec->t = root;
	rec->p = ray_at(ray, rec->t);
	set_normal(rec, ray, vec_devide(vec_minus(rec->p, sp->coord), sp->radius));
	rec->color = sp->rgb;
    return (1);
}

static int	hit_chk_pl(t_ray *ray, t_plane *pl, t_rec *rec)
{
	double	t;
	double	denom;

	denom = vec_dot(ray->dir, pl->axis);
	if (fabs(denom) < EPSILON)
		return (0);
	t = vec_dot(vec_minus(pl->coord, ray->origin), pl->axis) / denom;
	if (t < rec->min || rec->max < t)
		return (0);
	rec->t = t;
    rec->p = ray_at(ray, rec->t);
	// not yet
    set_normal(rec, ray, pl->axis);
	rec->color = pl->rgb;
	return (1);
}

// not yet
static int	hit_chk_cy(t_ray *ray, t_cylinder *cy, t_rec *rec)
{
	double	root;
	double	denom;
	t_vec3	t;

	denom = vec_dot(ray->dir, cy->axis);
	root = vec_dot(vec_minus(cy->coord, ray->origin), cy->axis) / denom;
	if (root < rec->min || rec->max < root)
		return (0);
	t = ray_at(ray, root);
	if (t.y < -cy->height / 2 || t.y > cy->height / 2)
		return (0);
	if (vec_length(vec_minus(t, cy->coord)) > cy->radius)
		return (0);
	rec->t = root;
	rec->p = t;
	set_normal(rec, ray, cy->axis);
	rec->color = cy->rgb;
	return (1);
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
