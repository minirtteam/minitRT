/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:15:46 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/23 16:12:51 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector.h"

static int	hit_chk_sp(t_ray ray, t_sphere *sp, t_rec *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_vec3	oc;

	oc = vec_plus(ray.origin, vec_multi(sp->coord, -1));
    a = vec_dist(ray.r, ray.r);
    half_b = vec_dist(oc, ray.r);
    c = vec_dist(oc, oc) - sp->radius * sp->radius;
    discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
		return (0);
    double sqrtd = sqrt(discriminant);
    double root = (-half_b - sqrtd) / a;
    if (root < rec->min || rec->max < root)
	{
        root = (-half_b + sqrtd) / a;
        if (root < rec->min || rec->max < root)
            return (0);
    }
    rec->t = root;
    rec->p = vec_plus(ray.origin, vec_multi(ray.r, rec->t));
    rec->normal = \
		vec_multi(vec_plus(rec->p, vec_multi(sp->coord, -1)), 1 / sp->radius);
	rec->color = sp->rgb;
    return (1);
}

static int	hit_chk_pl(t_ray ray, t_plane *pl, t_rec *rec)
{
	(void)ray;
	(void)pl;
	(void)rec;
	return (0);
}

static int	hit_chk_cy(t_ray ray, t_cylinder *cy, t_rec *rec)
{
	(void)ray;
	(void)cy;
	(void)rec;
	return (0);
}

int	is_hit(t_ray ray, t_lst *objs, t_rec *rec)
{
	int		is_hit;

	is_hit = 0;
	while (objs != NULL)
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
