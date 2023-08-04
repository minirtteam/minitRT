/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:39:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/04 16:50:49 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_BONUS_H
# define CALCULATE_BONUS_H

# include "data_type_bonus.h"
# include "mlx.h"
# include "math.h"

# define F_KSN 32
# define F_KS 0.7
# define F_IS_DOWN 256
# define CHECKER_SIZE 2.0

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
t_color	get_pl_color(t_rec *rec, t_color rgb, t_color checker_rgb);
t_color	get_cy_color(t_rec *rec, t_cylinder *cy);
t_color	get_cn_color(t_rec *rec, t_cone *cn);

#endif
