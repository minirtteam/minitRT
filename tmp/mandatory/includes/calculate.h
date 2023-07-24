/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:39:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/24 10:24:25 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_H
# define CALCULATE_H

# include "data_type.h"
# include "mlx.h"
# include "math.h"

# define F_KSN 64
# define F_KS 0.5

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_rec
{
	double	min;
	double	max;
	double	t;
	t_vec3	p;
	t_vec3	normal;
	t_vec3	color;
}	t_rec;

t_color	ft_calculate(t_info *info, double s, double t);
int		is_hit(t_ray *ray, t_lst *objs, t_rec *rec);
int		hit_chk_help(t_rec *rec, double sqrtd, double a, double half_b);
void	chk_face(t_ray *ray, t_rec *rec, t_vec3 outward_normal);

#endif
