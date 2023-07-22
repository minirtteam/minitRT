/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:32:29 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 15:29:46 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "data_type.h"

void	initial_vec(t_vec3 *v, double x, double y, double z);
t_vec3	vec_plus(t_vec3 v1, const t_vec3 v2);
t_vec3	vec_devide(t_vec3 v, double to_devide);
t_vec3	vec_multi(t_vec3 v, double to_multi);
double	vec_dist(const t_vec3 v1, const t_vec3 v2);

#endif
