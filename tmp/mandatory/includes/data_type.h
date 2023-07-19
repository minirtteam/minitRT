/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:35:44 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 13:05:04 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

# define F_DATA_CHAR 1
# define F_DATA_LST 2
# define F_DATA_OBJS 3
# define F_LIGHTS 1
# define F_SP 2
# define F_PL 3
# define F_CY 4

typedef struct s_lst
{
	void			*data;
	int				data_type;
	int				info;
	int				size;
	struct s_lst	*nxt;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_amb
{
	double	ratio;
	double	r;
	double	g;
	double	b;
}	t_amb;

typedef struct s_cam
{
	double	x;
	double	y;
	double	z;
	double	x_axis;
	double	y_axis;
	double	z_axis;
	double	fov;
}	t_cam;

typedef struct s_light
{
	double	x;
	double	y;
	double	z;
	double	ratio;
	double	r;
	double	g;
	double	b;
}	t_light;

typedef struct s_sphere
{
	double	x;
	double	y;
	double	z;
	double	diameter;
	double	r;
	double	g;
	double	b;
}	t_sphere;

typedef struct s_plane
{
	double	x;
	double	y;
	double	z;
	double	x_axis;
	double	y_axis;
	double	z_axis;
	double	r;
	double	g;
	double	b;
}	t_plane;

typedef struct s_cylinder
{
	double	x;
	double	y;
	double	z;
	double	x_axis;
	double	y_axis;
	double	z_axis;
	double	diameter;
	double	height;
	double	r;
	double	g;
	double	b;
}	t_cylinder;

#endif
