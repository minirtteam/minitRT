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

void	print_image(t_data *data, t_info *info)
{
	int			y;
	int			x;
	double		s;
	double		t;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			s = (double)x / (WIDTH - 1);
			t = (double)(HEIGHT - y) / (HEIGHT - 1);
			ft_put_pixel(data, x, y, get_color(ft_calculate(info, s, t)));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
