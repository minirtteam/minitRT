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

static void	ft_initial_world(t_world *world, t_cam *cam)
{
	double	focal_len;
	double	dir;

	world->origin = cam->coord;
	dir = cam->axis;
	if (vec_len(vec_cross(initial_vec(0, 1, 0), dir)) != 0)
		world->u = vec_unit(vec_cross(initial_vec(0, 1, 0), dir));
	else
		world->u = vec_unit(vec_cross(initial_vec(0, 0, -1), dir));
	world->v = vec_cross(dir, world->u);
	focal_len = (double)WIDTH / (2.0 * tan(cam->fov * M_PI / 360.0));
	world->origin = cam->coord;
	world->low_left = vec_minus( \
			vec_plus(world->origin, vec_multi(world->w, focal_len)), \
			vec_plus( \
			vec_multi(world->u, -(double)WIDTH / 2), \
			vec_multi(world->v, -(double)HEIGHT / 2)));
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
	ft_initial_world(&world, cam);
	world.amb = amb;
	wolrd.lights = lights;
	wolrd.objs = objs;
	print_image(&data, &world);
	mlx_key_hook(data.win, ft_esc_close, NULL);
	mlx_hook(data.win, 17, 1L, ft_close, NULL);
	mlx_loop(data.mlx);
}
