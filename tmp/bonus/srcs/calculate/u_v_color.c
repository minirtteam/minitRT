/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_v_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:17:26 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/08 19:51:37 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"
#include "utils_bonus.h"

static int	chk_color(double u, double v, double size)
{
	int	val;

	val = floor(u * size) + floor(v * size);
	return (val & 1);
}

static void	get_pl_color_help(t_vec3 o, double *u, double *v, int d)
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

t_color	get_pl_color(t_vec3 c, t_vec3 o, t_color rgb, t_color checker_rgb)
{
	double	cmp;
	double	u;
	double	v;

	if (checker_rgb.x < 0)
		return (rgb);
	cmp = ft_max(fabs(o.x), fabs(o.y), fabs(o.z));
	if (cmp == 0 && o.x > 0)
		get_pl_color_help(c, &u, &v, F_RIGHT);
	else if (cmp == 0 && o.x < 0)
		get_pl_color_help(c, &u, &v, F_LEFT);
	else if (cmp == 1 && o.y > 0)
		get_pl_color_help(c, &u, &v, F_UP);
	else if (cmp == 1 && o.y < 0)
		get_pl_color_help(c, &u, &v, F_DOWN);
	else if (cmp == 2 && o.z > 0)
		get_pl_color_help(c, &u, &v, F_FRONT);
	else
		get_pl_color_help(c, &u, &v, F_BACK);
	if (chk_color(u, v, 4.0))
		return (rgb);
	return (checker_rgb);
}

t_color	get_sp_color(t_rec *rec, t_sphere *sp)
{
	t_vec3	target;
	double	u;
	double	v;
	double	theta;
	double	phi;

	if (sp->checker_rgb.x < 0)
		return (sp->rgb);
	target = vec_minus(rec->p, sp->coord);
	theta = atan2(target.x, target.z);
	phi = acos(target.y / vec_length(target));
	u = 1 - (theta / (2.0 * M_PI) + 0.5);
	v = 1 - (phi / M_PI);
	if (chk_color(u * 2.0, v, 2.0 * sp->radius * M_PI))
		return (sp->rgb);
	return (sp->checker_rgb);
}

t_color	get_cy_cn_color(t_vec3 o, double v, t_cy_cn *c)
{
	int		cmp;
	double	theta;
	double	u;

	if (c->checker_rgb.x < 0)
		return (c->rgb);
	cmp = ft_max(fabs(c->axis.x), fabs(c->axis.y), fabs(c->axis.z));
	if (cmp == 0)
		theta = atan2(o.y, o.z);
	else if (cmp == 1)
		theta = atan2(o.x, o.z);
	else
		theta = atan2(o.x, o.y);
	u = 1 - (theta / (2.0 * M_PI) + 0.5);
	if (chk_color(u * 4.0, v, 2.0))
		return (c->rgb);
	return (c->checker_rgb);
}
