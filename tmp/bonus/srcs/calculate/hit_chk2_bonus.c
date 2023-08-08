/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:44:28 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/08 19:32:31 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"

static t_vec3	get_cn_normal(t_rec *rec, t_cone *cn)
{
	t_vec3	cp;
	t_vec3	target;
	double	v;

	cp = vec_minus(cn->coord, vec_multi(cn->axis, cn->height / 2.0));
	cp = vec_minus(rec->p, cp);
	v = vec_length_squared(cp) / vec_dot(cp, cn->axis);
	target = vec_minus(cp, vec_multi(cn->axis, v));
	return (vec_unit(target));
}

int	cy_cn_up_down(t_ray *ray, t_cy_cn *target, t_rec *rec, int info)
{
	double	height;
	double	denom;
	double	root;
	t_vec3	circle;
	t_vec3	p;

	height = target->height / 2.0;
	if ((info & F_IS_UP) != 0)
		height *= -1;
	circle = vec_plus(target->coord, vec_multi(target->axis, height));
	denom = vec_dot(ray->dir, target->axis);
	root = vec_dot(vec_minus(circle, ray->origin), target->axis) / denom;
	if (root < rec->min || rec->max < root)
		return (0);
	p = ray_at(ray, root);
	if (fabs(vec_length(vec_minus(circle, p))) > target->radius)
		return (0);
	rec->t = root;
	rec->p = p;
	set_normal(rec, ray, target->axis, info & F_BUMP);
	if (height > 0)
		set_normal(rec, ray, vec_multi(target->axis, -1), info & F_BUMP);
	rec->color = get_pl_color(vec_minus(rec->p, circle), \
			vec_minus(circle, target->coord), target->rgb, target->checker_rgb);
	return (1);
}

int	cy_side(t_ray *ray, t_cylinder *cy, t_rec *rec, int info)
{
	t_vec3	oc;
	t_vec3	normal;
	t_rec	tmp_rec;
	double	v;

	oc = vec_minus(ray->origin, cy->coord);
	tmp_rec = *rec;
	if (!is_intersect(&tmp_rec, \
		vec_length_squared(vec_cross(ray->dir, cy->axis)), \
		vec_dot(vec_cross(ray->dir, cy->axis), vec_cross(oc, cy->axis)), \
		vec_length_squared(vec_cross(oc, cy->axis)) - pow(cy->radius, 2)))
		return (0);
	tmp_rec.p = ray_at(ray, tmp_rec.t);
	v = vec_dot(vec_minus(tmp_rec.p, cy->coord), cy->axis);
	if (fabs(v) > cy->height / 2.0)
		return (0);
	*rec = tmp_rec;
	normal = vec_minus(rec->p, vec_plus(cy->coord, vec_multi(cy->axis, v)));
	set_normal(rec, ray, vec_unit(normal), info & F_BUMP);
	rec->color = get_cy_cn_color(normal, v, cy);
	return (1);
}

int	cn_side(t_ray *ray, t_cone *cn, t_rec *rec, int info)
{
	t_vec3	oc;
	t_vec3	point;
	t_rec	tmp_rec;
	double	angle;
	double	v;

	point = vec_minus(cn->coord, vec_multi(cn->axis, cn->height / 2.0));
	oc = vec_minus(ray->origin, point);
	angle = atan(cn->radius / cn->height);
	tmp_rec = *rec;
	if (!is_intersect(&tmp_rec, \
		pow(vec_dot(ray->dir, cn->axis), 2) - pow(cos(angle), 2), \
		vec_dot(ray->dir, cn->axis) * vec_dot(oc, cn->axis) \
		- vec_dot(oc, ray->dir) * pow(cos(angle), 2), \
		pow(vec_dot(oc, cn->axis), 2) - vec_dot(oc, oc) * pow(cos(angle), 2)))
		return (0);
	tmp_rec.p = ray_at(ray, tmp_rec.t);
	v = vec_dot(vec_minus(tmp_rec.p, point), cn->axis);
	if (v < 0 || v > cn->height)
		return (0);
	*rec = tmp_rec;
	set_normal(rec, ray, get_cn_normal(rec, cn), info & F_BUMP);
	rec->color = get_cy_cn_color(vec_minus(rec->p, vec_plus(point, \
				vec_multi(cn->axis, v))), v, cn);
	return (1);
}