/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:51:32 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 15:29:31 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	initial_vec(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

t_vec3	vec_plus(t_vec3 v1, const t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3	vec_devide(t_vec3 v, double to_devide)
{
	v.x /= to_devide;
	v.y /= to_devide;
	v.z /= to_devide;
	return (v);
}

t_vec3	vec_multi(t_vec3 v, double to_multi)
{
	v.x *= to_multi;
	v.y *= to_multi;
	v.z *= to_multi;
	return (v);
}

double	vec_dist(const t_vec3 v1, const t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
