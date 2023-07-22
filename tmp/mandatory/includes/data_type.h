/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:02:04 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 16:42:59 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:35:44 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 09:59:41 by hyunghki         ###   ########.fr       */
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

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef t_vec3	t_color;

typedef struct s_viewport
{
	double	aspect_ratio;
	double	focal_length;
	double	viewport_height;
	double	viewport_width;
	t_vec3	origin;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	lower_left_corner;
}	t_viewport;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	r;
}	t_ray;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_rec
{
	double	t;
	t_vec3	p;
	t_vec3	normal;
	t_vec3	color;
}	t_rec;

typedef struct s_amb
{
	double	ratio;
	t_color	rgb;
}	t_amb;

typedef struct s_cam
{
	t_vec3	coord;
	t_vec3	axis;
	double	fov;
}	t_cam;

typedef struct s_light
{
	t_vec3	coord;
	double	ratio;
	t_color	rgb;
}	t_light;

typedef struct s_sphere
{
	t_vec3	coord;
	double	diameter;
	t_color	rgb;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	coord;
	t_vec3	axis;
	t_color	rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	coord;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_color	rgb;
}	t_cylinder;

#endif
