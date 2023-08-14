/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:08:16 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/14 16:09:30 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"
#include "utils_bonus.h"

static t_vec3	get_bump_data(unsigned int val)
{
	t_vec3	target;

	target.x = (double)((val >> 16) & 0xFF) / 255.999;
	target.y = (double)((val >> 8) & 0xFF) / 255.999;
	target.z = (double)(val & 0xFF) / 255.999;
	target = vec_unit(vec_minus(vec_multi(target, 2.0), initial_vec(1, 1, 1)));
	return (target);
}

static t_vec3	get_new_normal(t_vec3 old, t_vec3 data)
{
	t_vec3	new_normal;
	t_vec3	tan_dir;
	t_vec3	bi_dir;

	if (vec_length(vec_cross(old, initial_vec(0, 1, 0))))
		tan_dir = vec_unit(vec_cross(old, initial_vec(0, 1, 0)));
	else if (old.y < 0)
		tan_dir = vec_unit(vec_cross(old, initial_vec(0, 0, -1)));
	else
		tan_dir = vec_unit(vec_cross(old, initial_vec(0, 0, 1)));
	bi_dir = vec_unit(vec_cross(tan_dir, old));
	new_normal = vec_plus(\
			vec_multi(tan_dir, data.x), \
			vec_plus(vec_multi(bi_dir, data.y), \
			vec_multi(old, data.z)));
	return (vec_unit(new_normal));
}

void	set_normal(t_rec *rec, t_ray *ray, t_bump *bump, int is_bump)
{
	unsigned int	val;
	int				s;
	int				t;

	if (vec_dot(ray->dir, rec->normal) > 0)
		rec->normal = vec_multi(rec->normal, -1);
	else if (is_bump)
	{
		s = floor(rec->u * (bump->width - 1));
		t = floor(rec->v * (bump->height - 1));
		val = bump->val[s][bump->height - 1 - t];
		rec->normal = get_new_normal(rec->normal, get_bump_data(val));
	}
}

int	is_intersect(t_rec *rec, double a, double half_b, double c)
{
	double	denom;
	double	sqrtd;
	double	root_1;
	double	root_2;

	denom = pow(half_b, 2) - a * c;
	if (denom < 0)
		return (0);
	sqrtd = sqrt(denom);
	root_1 = (-half_b - sqrtd) / a;
	root_2 = (-half_b + sqrtd) / a;
	if (root_1 < rec->min || rec->max < root_1)
		root_1 = INFINITY;
	if (root_2 < rec->min || rec->max < root_2)
		root_2 = INFINITY;
	if (root_1 == INFINITY && root_2 == INFINITY)
		return (0);
	rec->t = ft_min(root_1, root_2);
	rec->max = rec->t;
	return (1);
}
