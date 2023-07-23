/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:45:52 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/23 15:39:07 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec_unit(t_vec3 v)
{
	double	len;

	len = sqrt(vec_dist(v, v));
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}

t_vec3	vec_max(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = fmax(v1.x, v2.x);
	target.y = fmax(v1.y, v2.y);
	target.z = fmax(v1.z, v2.z);
	return (target);
}
