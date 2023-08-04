/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:08:16 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/04 16:20:50 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"

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
