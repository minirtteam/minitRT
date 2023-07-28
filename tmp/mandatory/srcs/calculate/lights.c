/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:02 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/28 14:52:16 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "calculate.h"

static int	is_shadow(t_ray *ray, t_lst *objs, double light_len)
{
	t_rec	rec;

	rec.min = 0.001;
	rec.max = light_len;
	return (is_hit(ray, objs, &rec));
}

static t_color	get_light(t_ray *ray, t_light *light, t_rec *rec, t_info *info)
{
	t_color	diffuse;
	t_color	specular;
	t_ray	light_ray;
	t_vec3	light_dir;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;

	light_dir = vec_minus(light->coord, rec->p);
	light_ray.origin = vec_plus(rec->p, vec_multi(rec->normal, 0.001));
	light_ray.dir = light_dir;
	if (is_shadow(&light_ray, info->objs, vec_length(light_dir)))
		return (initial_vec(0, 0, 0));
	light_dir = vec_unit(light_dir);
	diffuse = vec_multi(light->rgb, fmax(vec_dot(rec->normal, light_dir), 0.0));
	view_dir = vec_unit(vec_multi(ray->dir, -1));
	reflect_dir = vec_reflect(vec_multi(light_dir, -1), rec->normal);
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), F_KSN);
	specular = vec_multi(vec_multi(light->rgb, F_KS), spec);
	return (vec_multi(vec_plus(vec_plus(diffuse, info->amb->rgb), specular), light->ratio));
}

t_color	phong_light(t_ray *ray, t_rec *rec, t_info *info)
{
	t_color	ret;
	t_lst	*lights;

	ret = initial_vec(0.0, 0.0, 0.0);
	lights = info->lights;
	while (lights)
	{
		ret = vec_plus(ret, get_light(ray, lights->data, rec, info));
		lights = lights->nxt;
	}
	ret = vec_plus(ret, info->amb->rgb);
	return (vec_min(vec_multi_vec(ret, rec->color), initial_vec(1, 1, 1)));
}
