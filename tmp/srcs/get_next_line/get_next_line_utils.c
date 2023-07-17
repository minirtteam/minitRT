/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:57:35 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 11:53:19 by hyunghki         ###   ########.fr       */
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

char	*ft_gnl_strdup(const char *s)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strnlen(s, BUFFER_SIZE);
	ret = ft_calloc(len + 1);
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	return (ret);
}

int	ft_gnl_strncat(char **s1, char *s2, int s1_size, int s2_size)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = *s1;
	(*s1) = ft_calloc(s1_size + s2_size + 1);
	i = -1;
	while (++i < s1_size)
		(*s1)[i] = tmp[i];
	free(tmp);
	j = -1;
	while (s2[j] != '\n' && ++j < s2_size)
		(*s1)[i + j] = s2[j];
	if (s2[j] == '\n')
		ft_gnl_set_buffer(s2, j, s2_size);
	return (s2[j] == '\n');
}
