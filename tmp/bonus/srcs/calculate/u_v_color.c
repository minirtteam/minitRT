/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_v_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:17:26 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/04 17:50:46 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"

static int	chk_color(double u, double v)
{
	double	val;

	val = floor(u * CHECKER_SIZE) + floor(v * CHECKER_SIZE);
	return (fmod(val, 2.0));
}

t_color	get_sp_color(t_rec *rec, t_sphere *sp)
{
	double	u;
	double	v;
	double	theta;
	double	phi;

	theta = atan2(rec->p.x, rec->p.z);
	phi = atan2(rec->p.y, rec->p.x);
	u = 1 - (theta / (2.0 * M_PI) + 0.5);
	v = 1 - phi / M_PI;
	if (chk_color(u, v))
		return (sp->rgb);
	return (sp->checker_rgb);
}

t_color	get_pl_color(t_rec *rec, t_color rgb, t_color checker_rgb)
{
	double	u;
	double	v;

	u = fmod(rec->p.x, 1.0);
	v = fmod(rec->p.z, 1.0);
	if (chk_color(u, v))
		return (rgb);
	return (checker_rgb);
}

t_color	get_cy_color(t_rec *rec, t_cylinder *cy)
{
	double	theta;
	double	u;
	double	v;

	theta = atan2(rec->p.x, rec->p.z);
	u = 1 - (theta / (2.0 * M_PI) + 0.5);
	v = fmod(rec->p.y, 1.0);
	if (chk_color(u, v))
		return (cy->rgb);
	return (cy->checker_rgb);
}

t_color	get_cn_color(t_rec *rec, t_cone *cn)
{
	(void)rec;
	return (cn->rgb);
}
