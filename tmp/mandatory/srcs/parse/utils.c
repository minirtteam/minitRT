/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:51:55 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/23 15:16:59 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "parse.h"
#include "utils.h"
#include "get_next_line.h"

static t_lst	*ft_mk_node(char *s)
{
	t_lst	*data;
	t_lst	*ret;

	if (*s == '\0')
		return (NULL);
	ret = NULL;
	data = ft_split_lst(s);
	ret = mk_lst(data, F_DATA_LST, 0);
	return (ret);
}

t_lst	*get_data(char *file_name)
{
	t_lst	*ret;
	t_lst	*to_push;
	char	*line;
	int		fd;

	ret = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		to_push = ft_mk_node(ft_trim(line));
		if (to_push != NULL)
			lst_push(&ret, to_push);
		free(line);
	}
	close(fd);
	return (ret);
}

void	ft_get_coord(t_vec3 *coord, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	coord->x = ft_atod(s);
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	coord->y = ft_atod(s);
	s += (i + 1);
	coord->z = ft_atod(s);
}

void	ft_get_axis(t_vec3 *axis, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	axis->x = ft_atod(s);
	if (axis->x < -1 || axis->x > 1)
		ft_error();
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	axis->y = ft_atod(s);
	if (axis->y < -1 || axis->y > 1)
		ft_error();
	s += (i + 1);
	axis->z = ft_atod(s);
	if (axis->z < -1 || axis->z > 1)
		ft_error();
}

void	ft_get_rgb(t_color *rgb, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	rgb->x = ft_atod(s);
	if (rgb->x < 0 || rgb->x > 255)
		ft_error();
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	rgb->y = ft_atod(s);
	if (rgb->y < 0 || rgb->y > 255)
		ft_error();
	s += (i + 1);
	rgb->z = ft_atod(s);
	if (rgb->z < 0 || rgb->z > 255)
		ft_error();
	*rgb = vec_multi(*rgb, (1.0 / 255));
}
