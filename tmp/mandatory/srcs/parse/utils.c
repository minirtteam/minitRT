/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:51:55 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:32:04 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_get_coord(double *x, double *y, double *z, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	(*x) = ft_atod(s);
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	(*y) = ft_atod(s);
	s += (i + 1);
	(*z) = ft_atod(s);
}

void	ft_get_axis(double *x, double *y, double *z, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	(*x) = ft_atod(s);
	if (*x < -1 || *x > 1)
		ft_error();
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	(*y) = ft_atod(s);
	if (*y < -1 || *y > 1)
		ft_error();
	s += (i + 1);
	(*z) = ft_atod(s);
	if (*z < -1 || *z > 1)
		ft_error();
}

void	ft_get_rgb(unsigned int *r, unsigned int *g, unsigned int *b, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	(*r) = ft_atou(s);
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	(*g) = ft_atou(s);
	s += (i + 1);
	(*b) = ft_atou(s);
}
