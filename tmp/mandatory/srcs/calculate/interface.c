/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/28 11:45:04 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"
#include "vector.h"

static int	is_shadow(t_ray *ray, t_lst *objs, double light_len)
{
	t_rec	rec;

	rec.min = 0.001;
	rec.max = light_len;
	return (is_hit(ray, objs, &rec));
}

static t_color	ft_light(t_ray *ray, t_light *light, t_rec *rec, t_world *world)
{
	t_ray	light_ray;
	t_vec3	light_dir;
	t_vec3	view_dir;
	t_vec3	reflect_dir;

	light_dir = vec_minus(light->coord, rec->p);
	light_ray.origin = vec_plus(rec->p, vec_multi(rec->normal, rec->min));
	light_ray.dir = light_dir;
	if (is_shadow(&light_ray, info->objs, vec_length(light_dir)))
		return (initial_vec(0, 0, 0));
	light_dir = vec_unit(light_dir);
	view_dir = vec_unit(vec_multi(ray->dir, -1));
	diffuse = vec_multi(light->rgb, fmax(vec_dot(rec->normal, light_dir), 0.0));
	view_dir = vec_unit(vec_multi(ray->dir, -1));
	reflect_dir = vec_reflect(vec_multi(light_dir, -1), rec->normal);
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), F_KSN);
	specular = vec_multi(vec_multi(light->rgb, F_KS), spec);
	return (vec_multi(vec_plus(vec_plus(diffuse, info->amb->rgb), specular), light->ratio));
}

static t_color	phong_light(t_ray *ray, t_rec *rec, t_world *world)
{
	t_color	ret;
	t_lst	*lights;

	ret = initial_vec(0.0, 0.0, 0.0);
	lights = info->lights;
	while (lights)
	{
		ret = vec_plus(ret, ft_light(ray, lights->data, rec, world));
		lights = lights->nxt;
	}
	ret = vec_plus(ret, world->amb->rgb);
	return (vec_min(vec_multi_vec(ret, rec->color), initial_vec(1, 1, 1)));
}

t_color	ft_calculate(t_world *world, t_ray *ray)
{
	t_rec	rec;
	double	t;

	rec.min = 0.001;
	rec.max = INFINITY;
	if (is_hit(ray, info->objs, &rec))
		return (phong_light(ray, &rec, info));
	t = 0.5 * (ray->dir.y + 1.0);
	return (vec_plus(\
			vec_multi(initial_vec(1.0, 1.0, 1.0), (1.0 - t)), \
			vec_multi(initial_vec(0.5, 0.7, 1.0), t)));
}

t_color	ft_calculate(t_info *info, double s, double t)
{
	t_ray	ray;

	ray.origin = info->origin;
	ray.dir = info->low_left;
	ray.dir = vec_plus(ray.dir, vec_multi(info->horizontal, s));
	ray.dir = vec_plus(ray.dir, vec_multi(info->vertical, t));
	ray.dir = vec_minus(ray.dir, info->origin);
	ray.dir = vec_unit(ray.dir);
	return (ray_color(&ray, info));
}
