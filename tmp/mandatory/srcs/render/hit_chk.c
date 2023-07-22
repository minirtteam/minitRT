/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:15:46 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 17:58:48 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector.h"

int	hit_chk_sp(t_ray ray, t_sphere *sp, t_range cmp, t_rec *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_vec3	oc;

	oc = vec_plus(ray.origin, vec_multi(sp->coord, -1));
    a = vec_dist(ray.r, ray.r);
    half_b = vec_dist(oc, ray.r);
    c = vec_dist(oc, oc) - sp->diameter * sp->diameter / 4;
    discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
		return (0);
    double sqrtd = sqrt(discriminant);
    double root = (-half_b - sqrtd) / a;
    if (root < cmp.min || cmp.max < root)
	{
        root = (-half_b + sqrtd) / a;
        if (root < cmp.min || cmp.max < root)
            return (0);
    }
    rec->t = root;
    rec->p = vec_plus(ray.origin, vec_multi(ray.r, rec->t));
    rec->normal = \
		vec_multi(vec_plus(rec->p, vec_multi(sp->coord, -1)), 2 / sp->diameter);
	rec->color = sp->rgb;
    return (1);
}

int	hit_chk_pl(t_ray ray, t_plane *pl, t_range cmp, t_rec *rec)
{
	(void)ray;
	(void)pl;
	(void)cmp;
	(void)rec;
	return (0);
}

int	hit_chk_cy(t_ray ray, t_cylinder *cy, t_range cmp, t_rec *rec)
{
	(void)ray;
	(void)cy;
	(void)cmp;
	(void)rec;
	return (0);
}
