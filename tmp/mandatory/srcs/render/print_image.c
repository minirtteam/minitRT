/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:59:53 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/19 11:16:02 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_image(t_data *data)
{
	int	y;
	int	x;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_put_pixel(data, x, y, ft_calculate(data, x, y));
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
