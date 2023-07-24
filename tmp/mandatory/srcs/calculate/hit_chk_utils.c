/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:08:16 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/24 10:18:20 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"
#include "vector.h"

int	hit_chk_help(t_rec *rec, double sqrtd, double a, double half_b)
{
	double	root;

	root = (-half_b - sqrtd) / a;
	if (root < rec->min || rec->max < root)
	{
        root = (-half_b + sqrtd) / a;
        if (root < rec->min || rec->max < root)
            return (1);
    }
    rec->t = root;
	return (0);
}

void	chk_face(t_ray *ray, t_rec *rec, t_vec3 outward_normal)
{
	double	front_face;

	front_face = vec_dot(ray->dir, outward_normal);
	if (front_face < 0)
		rec->normal = outward_normal;
	else
		rec->normal = vec_multi(outward_normal, -1);
}
