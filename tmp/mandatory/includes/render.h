/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:10 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/03 18:18:15 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "data_type.h"

# define WIDTH 1280
# define HEIGHT 720
# define K_ESC 53
# define K_SCROLL_CLICK 3
# define K_SCROLL_UP 4
# define K_SCROLL_DOWN 5
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

void	ft_render(t_amb *amb, t_cam *cam, t_lst *lights, t_lst *objs);
void	print_image(t_data *data);

#endif
