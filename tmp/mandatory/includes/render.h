/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:41:10 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/22 17:22:41 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "utils.h"
# include "mlx.h"
# include "data_type.h"
# include "math.h"

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_amb		*amb;
	t_cam		*cam;
	t_lst		*lights;
	t_lst		*objs;
}		t_data;

void	ft_render(t_amb *amb, t_cam *cam, t_lst *lights, t_lst *objs);
void	print_image(t_data *data);
void	ft_initial_vp(t_viewport *vp, t_data *data);
t_color	ft_calculate(t_viewport *vp, t_data *data, double u, double v);
int		hit_chk_sp(t_ray ray, t_sphere *sp, t_range cmp, t_rec *rec);
int		hit_chk_pl(t_ray ray, t_plane *pl, t_range cmp, t_rec *rec);
int		hit_chk_cy(t_ray ray, t_cylinder *cy, t_range cmp, t_rec *rec);


#endif
