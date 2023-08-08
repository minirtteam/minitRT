/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:39:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/08 14:08:11 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_BONUS_H
# define CALCULATE_BONUS_H

# include "data_type_bonus.h"
# include "mlx.h"
# include "math.h"

# define F_KSN 32
# define F_KS 0.8
# define F_IS_UP 256
# define F_RIGHT 1
# define F_LEFT 2
# define F_UP 3
# define F_DOWN 4
# define F_FRONT 5
# define F_BACK 6

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
void	set_normal(t_rec *rec, t_ray *ray, t_vec3 normal, int is_bump);
int		is_intersect(t_rec *rec, double a, double half_b, double c);
t_color	phong_light(t_ray *ray, t_rec *rec, t_info *info);
int		cy_side(t_ray *ray, t_cylinder *cy, t_rec *rec, int info);
int		cn_side(t_ray *ray, t_cone *cn, t_rec *rec, int info);
int		cy_cn_up_down(t_ray *ray, t_cy_cn *target, t_rec *rec, int info);
t_color	get_sp_color(t_rec *rec, t_sphere *sp);
t_color	get_pl_color(t_vec3 c, t_vec3 o, t_color rgb, t_color checker_rgb);
t_color	get_cy_cn_color(t_vec3 o, double v, t_cy_cn *c);

#endif
