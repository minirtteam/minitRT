/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:39:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/29 14:43:55 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_H
# define CALCULATE_H

# include "data_type.h"
# include "mlx.h"
# include "math.h"

# define F_KSN 64
# define F_KS 0.5

typedef struct s_rec
{
	double	min;
	double	max;
	double	t;
	t_vec3	p;
	t_vec3	normal;
	t_vec3	color;
}	t_rec;

t_color	ft_calculate(t_ray *ray, t_info *info);
int		is_hit(t_ray *ray, t_lst *objs, t_rec *rec);
void	set_normal(t_rec *rec, t_ray *ray, t_vec3 normal);
int		is_intersect(t_rec *rec, double a, double half_b, double c);
t_color	phong_light(t_ray *ray, t_rec *rec, t_info *info);

#endif
