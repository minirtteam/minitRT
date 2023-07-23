/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:14:56 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/23 16:11:03 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector.h"

static int	is_shadow(t_ray ray, t_lst *objs, double light_len)
{
	t_rec	rec;

	rec.min = 0.001;
	rec.max = light_len;
	if (is_hit(ray, objs, &rec))
		return (1);
	return (0);
}

static t_color	phong_light_help(t_ray ray, t_light *light, t_rec rec, t_amb *amb, t_lst *objs)
{
	t_color	diffuse;
	t_vec3	light_dir;
	double	light_len;
	t_ray	light_ray;
	double	kd;
	t_color	specular;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;
	double	ksn;
	double	ks;

	light_dir = vec_plus(light->coord, vec_multi(rec.p, -1));
	light_len = sqrt(vec_dist(light_dir, light_dir));
	light_ray.origin = vec_plus(rec.p, vec_multi(rec.normal, 0.001));
	light_ray.r = light_dir;
	if (is_shadow(light_ray, objs, light_len))
		return (initial_vec(0, 0, 0));
	light_dir = vec_unit(light_dir);
	kd = fmax(vec_dist(rec.normal, light_dir), 0.0);
	diffuse = vec_multi(light->rgb, kd);
	view_dir = vec_unit(vec_multi(ray.r, -1));
	reflect_dir = vec_reflect(vec_multi(light_dir, -1), rec.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(vec_dist(view_dir, reflect_dir), 0.0), ksn);
	specular = vec_multi(vec_multi(light->rgb, ks), spec);
	return (vec_multi(vec_plus(vec_plus(diffuse, amb->rgb), specular), light->ratio));
}

static t_color	phong_light(t_ray ray, t_lst *lights, t_rec rec, t_amb *amb, t_lst *objs)
{
	t_color	ret;

	ret = initial_vec(0, 0, 0);
	while (lights != NULL)
	{
		ret = vec_plus(ret, phong_light_help(ray, lights->data, rec, amb, objs));
		lights = lights->nxt;
	}
	ret = vec_plus(ret, amb->rgb);
	return (vec_min(vec_multi_vec(ret, rec.color), initial_vec(1, 1, 1)));

}

static t_color	ray_color(t_ray ray, t_lst *objs, t_amb *amb, t_lst *lights)
{
	t_vec3	unit_dir;
	t_rec	rec;
	double	t;

	rec.min = 0.000001;
	rec.max = INFINITY;
	if (is_hit(ray, objs, &rec))
		return (phong_light(ray, lights, rec, amb, objs));
	unit_dir = vec_unit(ray.r);
	t = 0.5 * (unit_dir.y + 1.0);
	return (vec_plus(\
			vec_multi(vec_multi(amb->rgb, amb->ratio), (1.0 - t)), \
			vec_multi(amb->rgb, t)));
}

void	ft_initial_vp(t_viewport *vp, t_data *data)
{
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	vp->aspect_ratio = (double)HEIGHT / (double)WIDTH;
	vp->viewport_width = 2.0 * tan(data->cam->fov * M_PI / 360.0);
	vp->viewport_height = vp->aspect_ratio * vp->viewport_width;
	w = vec_unit(vec_plus(data->cam->coord, vec_multi(data->cam->axis, -1)));
	u = vec_unit(vec_cross(initial_vec(0, 1, 0), w));
	v = vec_cross(w, u);
	vp->origin = data->cam->coord;
	vp->horizontal = vec_multi(u, vp->viewport_width);
	vp->vertical = vec_multi(v, vp->viewport_height);
	vp->lower_left_corner = vec_plus(vp->origin, \
							vec_plus(vec_multi(vp->horizontal, -0.5), \
							vec_plus(vec_multi(vp->vertical, -0.5), \
							vec_multi(w, -1))));
}

t_color	ft_calculate(t_viewport *vp, t_data *data, double u, double v)
{
	t_ray	ray;
	t_vec3	r;

	ray.origin = vp->origin;
	r = vp->lower_left_corner;
	r = vec_plus(r, vec_multi(vp->horizontal, u));
	r = vec_plus(r, vec_multi(vp->vertical, v));
	r = vec_plus(r, vec_multi(vp->origin, -1));
	ray.r = r;
	return (ray_color(ray, data->objs, data->amb, data->lights));
}
