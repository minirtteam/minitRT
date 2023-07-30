/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:08:16 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:31:53 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"

void	set_normal(t_rec *rec, t_ray *ray, t_vec3 normal)
{
	if (vec_dot(ray->dir, normal) < 0)
		rec->normal = normal;
	else
		rec->normal = vec_multi(normal, -1);
}

int	is_intersect(t_rec *rec, double a, double half_b, double c)
{
	double	denom;
	double	sqrtd;
	double	root;

	denom = pow(half_b, 2) - a * c;
	if (denom < 0)
		return (0);
	sqrtd = sqrt(denom);
	root = (-half_b - sqrtd) / a;
	if (root < rec->min || rec->max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->min || rec->max < root)
			return (0);
	}
	rec->t = root;
	return (1);
}

int	cy_up_down(t_ray *ray, t_cylinder *cy, t_rec *rec, double height)
{
	double	denom;
	double	root;
	t_vec3	circle_coord;
	t_vec3	p;

	circle_coord = vec_plus(cy->coord, vec_multi(cy->axis, height));
	denom = vec_dot(ray->dir, cy->axis);
	root = vec_dot(vec_minus(circle_coord, ray->origin), cy->axis) / denom;
	if (root < rec->min || rec->max < root)
		return (0);
	p = ray_at(ray, root);
	if (fabs(vec_length(vec_minus(circle_coord, p))) > cy->radius)
		return (0);
	rec->t = root;
	rec->p = p;
	if (height > 0)
		set_normal(rec, ray, cy->axis);
	else
		set_normal(rec, ray, vec_multi(cy->axis, -1));
	rec->color = cy->rgb;
	return (1);
}

int	cy_side(t_ray *ray, t_cylinder *cy, t_rec *rec)
{
	t_vec3	d;
	t_vec3	normal;
	t_rec	tmp_rec;
	double	v;

	d = vec_minus(ray->origin, cy->coord);
	tmp_rec = *rec;
	if (!is_intersect(&tmp_rec, \
		vec_length_squared(vec_cross(ray->dir, cy->axis)), \
		vec_dot(vec_cross(ray->dir, cy->axis), vec_cross(d, cy->axis)), \
		vec_length_squared(vec_cross(d, cy->axis)) - pow(cy->radius, 2)))
		return (0);
	tmp_rec.p = ray_at(ray, tmp_rec.t);
	v = vec_dot(vec_minus(tmp_rec.p, cy->coord), cy->axis);
	if (fabs(v) > cy->height / 2.0)
		return (0);
	*rec = tmp_rec;
	normal = vec_minus(rec->p, vec_plus(cy->coord, vec_multi(cy->axis, v)));
	set_normal(rec, ray, vec_unit(normal));
	rec->color = cy->rgb;
	return (1);
}
