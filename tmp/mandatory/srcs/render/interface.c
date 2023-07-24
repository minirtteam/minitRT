/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:40:07 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/24 10:31:02 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"
#include "vector.h"

static int	ft_esc_close(int keycode)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

static int	ft_close(int keycode)
{
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_initial_info(t_info *info, t_cam *cam)
{
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	info->cam = cam;
	info->aspect_ratio = (double)HEIGHT / (double)WIDTH;
	info->view_width = 2.0 * tan(cam->fov * M_PI / 360.0);
	info->view_height = info->aspect_ratio * info->view_width;
	w = vec_unit(vec_minus(cam->coord, cam->axis));
	u = vec_unit(vec_cross(initial_vec(0, 1, 0), w));
	v = vec_cross(w, u);
	info->origin = cam->coord;
	info->horizontal = vec_multi(u, info->view_width);
	info->vertical = vec_multi(v, info->view_height);
	info->low_left = vec_minus(info->origin, vec_devide(info->horizontal, 2));
	info->low_left = vec_minus(info->low_left, vec_devide(info->vertical, 2));
	info->low_left = vec_minus(info->low_left, w);
}

void	ft_render(t_amb *amb, t_cam *cam, t_lst *lights, t_lst *objs)
{
	t_data	data;
	t_info	info;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_error();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "miniRT");
	if (data.win == NULL)
		ft_error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (data.img == NULL)
		ft_error();
	data.addr = mlx_get_data_addr(data.img, &data.bpp, \
			&data.line_length, &data.endian);
	ft_initial_info(&info, cam);
	info.amb = amb;
	info.lights = lights;
	info.objs = objs;
	print_image(&data, &info);
	mlx_key_hook(data.win, ft_esc_close, NULL);
	mlx_hook(data.win, 17, 1L, ft_close, NULL);
	mlx_loop(data.mlx);
}
