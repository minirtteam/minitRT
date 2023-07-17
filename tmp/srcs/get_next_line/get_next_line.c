/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:38:53 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 10:46:27 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "utils.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	int			bytes;
	char		*target;

	target = ft_gnl_strdup(buf, 0);
	*buf = '\0';
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			ft_error();
		if (bytes == 0)
		{
			*buf = '\0';
			if (*target != '\0')
				break ;
			free(target);
			return (NULL);
		}
		if (ft_gnl_strncat(&target, buf, ft_strlen(target), bytes) == 1)
			break ;
	}
	return (target);
}
