/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:57:35 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:32:08 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "utils.h"

static void	ft_gnl_set_buffer(char *buf, int st, int en)
{
	int	i;

	i = -1;
	while (++i + st < en)
		buf[i] = buf[i + st];
	buf[i] = '\0';
}

int	ft_gnl_strncat(char **s1, char *s2, int s1_size, int s2_size)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = *s1;
	(*s1) = ft_calloc(s1_size + s2_size + 1);
	i = -1;
	while (++i < s1_size && tmp != NULL)
		(*s1)[i] = tmp[i];
	free(tmp);
	j = -1;
	while (s2[j] != '\n' && ++j < s2_size)
		(*s1)[i + j] = s2[j];
	if (s2[j] == '\n')
	{
		ft_gnl_set_buffer(s2, j + 1, s2_size);
		return (1);
	}
	return (0);
}
