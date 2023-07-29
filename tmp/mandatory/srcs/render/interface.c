/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:40:07 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/29 15:13:07 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"
#include "vector.h"

static void	ft_initial_info(t_info *info, t_cam *cam)
{
	double	focal_len;

	if (vec_length(vec_cross(cam->axis, initial_vec(0, 1, 0))))
		info->u_dir = vec_unit(vec_cross(cam->axis, initial_vec(0, 1, 0)));
	else
		info->u_dir = vec_unit(vec_cross(cam->axis, initial_vec(0, 0, 1)));
	info->v_dir = vec_unit(vec_cross(info->u_dir, cam->axis));
	info->origin = cam->coord;
	focal_len = (double)WIDTH / 2.0 / tan(cam->fov * M_PI / 360.0);
	info->low_left = vec_minus(\
			vec_plus(info->origin, vec_multi(cam->axis, focal_len)), \
			vec_plus(\
				vec_multi(info->u_dir, (double)(WIDTH - 1) / 2), \
				vec_multi(info->v_dir, (double)(HEIGHT - 1) / 2)));
}

static int	ft_close_esc(int keycode)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
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
	data.info = &info;
	print_image(&data);
	mlx_key_hook(data.win, ft_close_esc, NULL);
	mlx_hook(data.win, 17, 1L, ft_close, NULL);
	mlx_loop(data.mlx);
}
