/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:14:56 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 17:34:17 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector.h"

static int	is_hit(t_ray ray, t_lst *objs, t_rec *rec)
{
	int		is_hit;
	t_range	cmp;

	cmp.min = 0;
	cmp.max = INFINITY;
	is_hit = 0;
	while (objs != NULL)
	{
		if ((objs->info == F_SP && hit_chk_sp(ray, objs->data, cmp, rec)) \
			|| (objs->info == F_PL && hit_chk_pl(ray, objs->data, cmp, rec)) \
			|| (objs->info == F_CY && hit_chk_cy(ray, objs->data, cmp, rec)))
		{
			is_hit = 1;
			cmp.max = rec->t;
		}
		objs = objs->nxt;
	}
    return (is_hit);
}

static t_color	ray_color(t_ray ray, t_lst *objs, t_amb *amb)
{
	t_rec			rec;
	const t_color	tmp = {1, 1, 1};
	double			t;

	if (is_hit(ray, objs, &rec))
		return (vec_multi(vec_plus(rec.normal, tmp), 0.5));
	t = 0.5 * (ray.r.y + 1.0);
	return (vec_plus(\
			vec_multi(vec_multi(amb->rgb, amb->ratio), (1.0 - t)), \
			vec_multi(amb->rgb, t)));
}

void	ft_initial_vp(t_viewport *vp, t_data *data)
{
	vp->aspect_ratio = (double)WIDTH / (double)HEIGHT;
	vp->viewport_height = 2.0;
	vp->viewport_width = vp->aspect_ratio * vp->viewport_height;
	vp->focal_length = 1.0;
	vp->origin = data->cam->coord;
	initial_vec(&vp->horizontal, vp->viewport_width, 0, 0);
	initial_vec(&vp->vertical, 0, vp->viewport_height, 0);
	vp->lower_left_corner = vec_plus(vp->origin, \
							vec_plus(vec_multi(vp->horizontal, -0.5) \
							, vec_multi(vp->vertical, -0.5)));
	vp->lower_left_corner.z -= vp->focal_length;
}

t_color	ft_calculate(t_viewport *vp, t_data *data, double u, double v)
{
	t_ray	ray;
	t_vec3	r;

	ray.origin = vp->origin;
	initial_vec(&r, 0, 0, 0);
	r = vec_plus(r, vp->lower_left_corner);
	r = vec_plus(r, vec_multi(vp->horizontal, u));
	r = vec_plus(r, vec_multi(vp->vertical, v));
	r = vec_plus(r, vec_multi(vp->origin, -1));
	ray.r = r;
	return (ray_color(ray, data->objs, data->amb));
}
