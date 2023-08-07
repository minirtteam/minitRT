/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_v_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:17:26 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/07 19:29:45 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"
#include "utils_bonus.h"

static int	chk_color(double u, double v, double col_size, double row_size)
{
	int	val;

	val = floor(u * col_size) + floor(v * row_size);
	return (val & 1);
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
	if (chk_color(u, v, 6.0 * sp->radius * M_PI, 4.0 * sp->radius * M_PI))
		return (sp->rgb);
	return (sp->checker_rgb);
}

t_color	get_pl_color(t_rec *rec, t_vec3 o, t_color rgb, t_color checker_rgb)
{
	t_vec3	target;
	double	u;
	double	v;

	if (checker_rgb.x < 0)
		return (rgb);
	target = vec_minus(rec->p, o);
	u = fmod(target.x, 1.0);
	v = fmod(target.z, 1.0);
	if (chk_color(u, v, 2.0, 2.0))
		return (rgb);
	return (checker_rgb);
}

t_color	get_cy_cn_color(t_rec *rec, t_cy_cn *c, t_vec3 o)
{
	t_vec3	target;
	double	theta;
	double	u;
	double	v;

	(void)o;
	if (c->checker_rgb.x < 0)
		return (c->rgb);
	target = vec_minus(rec->p, c->coord);
	theta = atan2(target.x, target.z);
	u = 1 - (theta / (2.0 * M_PI) + 0.5);
	v = target.y - floor(target.y);
	if (chk_color(u, v, c->height, c->radius * 2.0 * M_PI))
		return (c->rgb);
	return (c->checker_rgb);
}

t_color	get_cy_color(t_rec *rec, t_cylinder *cy)
{
	t_vec3	target;
	double	theta;
	double	u;
	double	v;

	if (cy->checker_rgb.x < 0)
		return (cy->rgb);
	target = vec_minus(rec->p, cy->coord);
	theta = atan2(target.x, target.z);
	u = 1 - (theta / (2.0 * M_PI) + 0.5);
	v = target.y - floor(target.y);
	if (chk_color(u, v, cy->height, cy->radius * 2.0 * M_PI))
		return (cy->rgb);
	return (cy->checker_rgb);
}
