/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:40:07 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/28 11:09:40 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"
#include "vector.h"

static void	ft_initial_info(t_info *info, t_cam *cam)
{
	double	focal_len;
	double	dir;

	info->cam = cam;
	info->aspect_ratio = (double)HEIGHT / (double)WIDTH;
	info->view_width = 2.0 * tan(cam->fov * M_PI / 360.0);
	info->view_height = info->aspect_ratio * info->view_width;
	w = cam->axis;
	if (vec_length(vec_cross(initial_vec(0, 1, 0), w)) != 0)
		u = vec_unit(vec_cross(initial_vec(0, 1, 0), w));
	else
		u = vec_unit(vec_cross(initial_vec(0, 0, -1), w));
	v = vec_cross(w, u);
	info->origin = cam->coord;
	info->horizontal = vec_multi(u, info->view_width);
	info->vertical = vec_multi(v, info->view_height);
	info->low_left = vec_minus(info->origin, vec_devide(info->horizontal, 2));
	info->low_left = vec_minus(info->low_left, vec_devide(info->vertical, 2));
	info->low_left = vec_minus(info->low_left, w);
}

static int	ft_mouse_hook(int keycode, int x, int y, t_data *data)
{
	t_info	*info;

	(void)x;
	(void)y;
	info = data->info;
	if (keycode == M_LEFT && info->cam->axis.y + 0.3 <= 1.0)
		info->cam->axis.y += 0.3;
	else if (keycode == M_RIGHT && info->cam->axis.y - 0.3 >= -1.0)
		info->cam->axis.y -= 0.3;
	else if (keycode == M_UP)
		info->cam->coord.y += 3.0;
	else if (keycode == M_DOWN)
		info->cam->coord.y -= 3.0;
	else
		return (0);
	ft_initial_info(info, info->cam);
	print_image(data);
		return (0);
}

static int	handle_key(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == K_A)
		data->info->cam->coord.x += 3.0;
	else if (keycode == K_W)
		data->info->cam->coord.z += 3.0;
	else if (keycode == K_D)
		data->info->cam->coord.x -= 3.0;
	else if	(keycode == K_S)
		data->info->cam->coord.z -= 3.0;
	else if (keycode == K_LEFT && data->info->cam->axis.x - 0.1 >= -1.0)
		data->info->cam->axis.x -= 0.1;
	else if (keycode == K_UP && data->info->cam->axis.z + 0.1 <= 1.0)
		data->info->cam->axis.z += 0.1;
	else if (keycode == K_RIGHT && data->info->cam->axis.x + 0.1 <= 1.0)
		data->info->cam->axis.x += 0.1;
	else if	(keycode == K_DOWN && data->info->cam->axis.z - 0.1 >= -1.0)
		data->info->cam->axis.z -= 0.1;
	else
		return (0);
	ft_initial_info(data->info, data->info->cam);
	print_image(data);
	return (0);
}

static int	ft_close(int keycode)
{
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_render(t_amb *amb, t_cam *cam, t_lst *lights, t_lst *objs)
{
	t_data	data;
	t_world	world;

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
	data.info = &info;
	print_image(&data);
	mlx_mouse_hook(data.win, ft_mouse_hook, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 1L, ft_close, NULL);
	mlx_loop(data.mlx);
}
