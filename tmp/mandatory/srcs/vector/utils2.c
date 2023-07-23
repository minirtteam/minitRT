/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:39:35 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/23 16:09:11 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_dist(const t_vec3 v1, const t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3 vec_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = v1.y * v2.z - v1.z * v2.y;
	target.y = v1.z * v2.x - v1.x * v2.z;
	target.z = v1.x * v2.y - v1.y * v2.x;
	return (target);
}

t_vec3	vec_reflect(t_vec3 v1, t_vec3 v2)
{
	return (vec_plus(v1, vec_multi(v2, vec_dist(v1, v2) * -2)));
}

t_vec3	vec_multi_vec(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = v1.x * v2.x;
	target.y = v1.y * v2.y;
	target.z = v1.z * v2.z;
	return (target);
}

t_vec3	vec_min(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = fmin(v1.x, v2.x);
	target.y = fmin(v1.y, v2.y);
	target.z = fmin(v1.z, v2.z);
	return (target);
}
