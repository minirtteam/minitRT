/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_v_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:17:26 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/14 18:40:21 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"
#include "utils_bonus.h"

t_vec3	get_uv_color(t_rec *rec, t_color rgb, t_color checker_rgb, double size)
{
	int	val;

	val = floor(rec->u * size) + floor(rec->v * size);
	if ((val & 1) && checker_rgb.x >= 0)
		return (checker_rgb);
	return (rgb);
}

static void	get_pl_uv_help(t_vec3 o, double *u, double *v, int d)
{
	if (d == F_UP || d == F_DOWN || d == F_BACK)
		*u = fmod(1.0 - o.x, 2.0) / 2.0;
	else if (d == F_FRONT)
		*u = fmod(o.x + 1.0, 2.0) / 2.0;
	else if (d == F_LEFT)
		*u = fmod(o.z + 1.0, 2.0) / 2.0;
	else if (d == F_RIGHT)
		*u = fmod(1.0 - o.z, 2.0) / 2.0;
	if (d == F_RIGHT || d == F_LEFT || d == F_FRONT || d == F_BACK)
		*v = fmod(o.y + 1.0, 2.0) / 2.0;
	else if (d == F_UP)
		*v = fmod(1.0 - o.z, 2.0) / 2.0;
	else if (d == F_DOWN)
		*v = fmod(o.z + 1.0, 2.0) / 2.0;
}

void	get_pl_uv(t_rec *rec, t_vec3 c, t_vec3 o)
{
	double	cmp;
	double	u;
	double	v;

	cmp = ft_max(fabs(o.x), fabs(o.y), fabs(o.z));
	if (cmp == 0 && o.x > 0)
		get_pl_uv_help(c, &u, &v, F_RIGHT);
	else if (cmp == 0 && o.x < 0)
		get_pl_uv_help(c, &u, &v, F_LEFT);
	else if (cmp == 1 && o.y > 0)
		get_pl_uv_help(c, &u, &v, F_UP);
	else if (cmp == 1 && o.y < 0)
		get_pl_uv_help(c, &u, &v, F_DOWN);
	else if (cmp == 2 && o.z > 0)
		get_pl_uv_help(c, &u, &v, F_FRONT);
	else
		get_pl_uv_help(c, &u, &v, F_BACK);
	rec->u = (u + 1.0) / 2.0;
	rec->v = (v + 1.0) / 2.0;
}

void	get_sp_uv(t_rec *rec, t_sphere *sp)
{
	t_vec3	target;
	double	theta;
	double	phi;

	target = vec_minus(rec->p, sp->coord);
	theta = atan2(target.x, target.z);
	phi = acos(target.y / sp->radius);
	rec->u = 1 - (theta / (2.0 * M_PI) + 0.5);
	rec->v = 1 - (phi / M_PI);
}

void	get_c_uv(t_rec *rec, t_vec3 o, double v, t_cy_cn *c)
{
	int		cmp;
	double	theta;

	o = vec_minus(rec->p, vec_plus(o, vec_multi(c->axis, v)));
	cmp = ft_max(fabs(c->axis.x), fabs(c->axis.y), fabs(c->axis.z));
	if (cmp == 0)
		theta = atan2(o.y, o.z);
	else if (cmp == 1)
		theta = atan2(o.x, o.z);
	else
		theta = atan2(o.x, o.y);
	rec->u = 1 - (theta / (2.0 * M_PI) + 0.5);
	rec->v = v / c->height;
}
