/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:08:16 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/07 16:40:19 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"
#include "utils_bonus.h"

void	set_normal(t_rec *rec, t_ray *ray, t_vec3 normal, int is_bump)
{
	(void)is_bump;
	if (vec_dot(ray->dir, normal) < 0)
		rec->normal = normal;
	else
		rec->normal = vec_multi(normal, -1);
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
	return (1);
}
