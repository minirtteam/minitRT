/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:30:14 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/28 14:05:11 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec_multi_vec(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = v1.x * v2.x;
	target.y = v1.y * v2.y;
	target.z = v1.z * v2.z;
	return (target);
}

t_vec3	vec_max(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = fmax(v1.x, v2.x);
	target.y = fmax(v1.y, v2.y);
	target.z = fmax(v1.z, v2.z);
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
