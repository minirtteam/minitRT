/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:59:53 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/28 15:58:46 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector.h"
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

static void	get_ray(t_ray *ray, t_info *info, double s, double t)
{
	ray->origin = info->origin;
	ray->dir = info->low_left;
	ray->dir = vec_plus(ray->dir, vec_multi(info->horizontal, s));
	ray->dir = vec_plus(ray->dir, vec_multi(info->vertical, t));
	ray->dir = vec_minus(ray->dir, info->origin);
	ray->dir = vec_unit(ray->dir);
}

void	print_image(t_data *data)
{
	int			y;
	int			x;
	double		s;
	double		t;
	t_ray		ray;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			s = (double)(WIDTH - x) / (WIDTH - 1);
			t = (double)(HEIGHT - 1 - y) / (HEIGHT - 1);
			get_ray(&ray, data->info, s, t);
			ft_put_pixel(data, x, y, get_color(ft_calculate(&ray, data->info)));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
