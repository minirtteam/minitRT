/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:25 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 16:00:41 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "get_next_line.h"
#include "utils.h"

static t_lst	*ft_mk_node(char *s)
{
	t_lst	*data;
	t_lst	*ret;

	if (*s == '\0')
		return (NULL);
	ret = NULL;
	data = ft_split_lst(s);
	ret = mk_lst(data, F_DATA_LST);
	return (ret);
}

t_lst	*ft_parse(char *file_name)
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
