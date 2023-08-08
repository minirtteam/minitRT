/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:15:46 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/08 12:59:22 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"

static int	hit_chk_sp(t_ray *ray, t_sphere *sp, t_rec *rec, int info)
{
	t_vec3	oc;
	t_vec3	normal;

	oc = vec_minus(ray->origin, sp->coord);
	if (!is_intersect(rec, \
		vec_length_squared(ray->dir), \
		vec_dot(oc, ray->dir), \
		vec_length_squared(oc) - pow(sp->radius, 2)))
		return (0);
	rec->p = ray_at(ray, rec->t);
	normal = vec_devide(vec_minus(rec->p, sp->coord), sp->radius);
	set_normal(rec, ray, normal, info & F_BUMP);
	rec->color = get_sp_color(rec, sp);
	return (1);
}

static int	hit_chk_pl(t_ray *ray, t_plane *pl, t_rec *rec, int info)
{
	double	root;
	double	denom;

	denom = vec_dot(ray->dir, pl->axis);
	if (fabs(denom) < 0.001)
		return (0);
	root = vec_dot(vec_minus(pl->coord, ray->origin), pl->axis) / denom;
	if (root < rec->min || rec->max < root)
		return (0);
	rec->t = root;
	rec->p = ray_at(ray, rec->t);
	set_normal(rec, ray, pl->axis, info & F_BUMP);
	rec->color = get_pl_color(rec->p, pl->axis, pl->rgb, pl->checker_rgb);
	return (1);
}

static int	hit_chk_cy_cn(t_ray *ray, t_cy_cn *target, t_rec *rec, int info)
{
	if (info & F_CY)
		return (cy_side(ray, target, rec, info) \
				|| cy_cn_up_down(ray, target, rec, info) \
				|| cy_cn_up_down(ray, target, rec, info | F_IS_UP));
	return (cn_side(ray, target, rec, info) \
			|| cy_cn_up_down(ray, target, rec, info));
}

int	is_hit(t_ray *ray, t_lst *objs, t_rec *rec)
{
	int		is_hit;
	int		info;

	is_hit = 0;
	while (objs)
	{
		info = objs->info;
		if (((info & F_SP) && hit_chk_sp(ray, objs->data, rec, info)) \
			|| ((info & F_PL) && hit_chk_pl(ray, objs->data, rec, info)) \
			|| ((info & F_CY) && hit_chk_cy_cn(ray, objs->data, rec, info)) \
			|| ((info & F_CN) && hit_chk_cy_cn(ray, objs->data, rec, info)))
		{
			is_hit = 1;
			rec->max = rec->t;
		}
		objs = objs->nxt;
	}
	return (is_hit);
}
