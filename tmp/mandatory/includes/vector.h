/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:32:29 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/23 15:49:37 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "data_type.h"
# include "math.h"

t_vec3	initial_vec(double x, double y, double z);
t_vec3	vec_plus(t_vec3 v1, const t_vec3 v2);
t_vec3	vec_devide(t_vec3 v, double to_devide);
t_vec3	vec_multi(t_vec3 v, double to_multi);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
double	vec_dist(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec_reflect(t_vec3 v1, t_vec3 v2);
t_vec3	vec_multi_vec(t_vec3 v1, t_vec3 v2);
t_vec3	vec_min(t_vec3 v1, t_vec3 v2);
t_vec3	vec_max(t_vec3 v1, t_vec3 v2);
t_vec3	vec_unit(t_vec3 v);

#endif
