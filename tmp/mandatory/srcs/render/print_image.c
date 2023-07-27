/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:59:53 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/24 09:40:56 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "calculate.h"

static unsigned int	get_color(t_color rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb.x * 255;
	g = rgb.y * 255;
	b = rgb.z * 255;
	return ((r << 16) + (g << 8) + b);
}

static void	ft_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	get_ray(t_world *world, t_ray *ray, int s, int t)
{
	ray->origin = world->origin;
	ray->dir = vec_unit(\
				vec_minus(\
					vec_plus(\
						vec_plus(\
							vec_multi(world->u, s), \
							vec_multi(world->v, t)), \
							world->low_left),
					world->origin));
}

void	print_image(t_data *data, t_world *world)
{
	int			y;
	int			x;
	t_ray		ray;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			get_ray(world, &ray, x, HEIGHT - 1 - y)
			ft_put_pixel(data, x, y, get_color(ft_calculate(world, &ray)));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
