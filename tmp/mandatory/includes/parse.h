/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:48:31 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/29 16:55:16 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <stdlib.h>
# include "data_type.h"

t_lst	*ft_parse(char *file_name, t_amb **amb, t_cam **cam, t_lst **lights);
t_lst	*get_data(char *file_name);
void	ft_get_coord(t_vec3 *coord, char *s);
void	ft_get_axis(t_vec3 *axis, char *s);
void	ft_get_rgb(t_color *rgb, char *s);
void	ft_parse_acl(t_amb **amb, t_cam **cam, t_lst **lights, t_lst *target);
void	ft_parse_objs(t_lst **objs, t_lst *target);

#endif
