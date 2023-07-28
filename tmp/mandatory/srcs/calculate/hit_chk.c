/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:15:46 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/28 14:02:32 by hyunghki         ###   ########.fr       */
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
	double	t;
	double	denom;

	denom = vec_dot(ray->dir, pl->axis);
	if (fabs(denom) < 0.001)
		return (0);
	t = vec_dot(vec_minus(pl->coord, ray->origin), pl->axis) / denom;
	if (t < rec->min || rec->max < t)
		return (0);
	rec->t = t;
    rec->p = vec_plus(ray->origin, vec_multi(ray->dir, rec->t));
    chk_face(ray, rec, pl->axis);
	rec->color = pl->rgb;
	return (1);
}

static int	hit_chk_cy(t_ray *ray, t_cylinder *cy, t_rec *rec)
{
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
