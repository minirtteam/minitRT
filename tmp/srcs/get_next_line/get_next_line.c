/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:38:53 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 15:55:56 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "utils.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	int			bytes;
	char		*target;

	target = NULL;
	if (*buf != '\0' && \
	ft_gnl_strncat(&target, buf, 0, ft_strnlen(buf, BUFFER_SIZE)) != 0)
		return (target);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			ft_error();
		if (bytes == 0)
		{
			*buf = '\0';
			break ;
		}
		if (ft_gnl_strncat(&target, buf, ft_strlen(target), bytes) != 0)
			break ;
	}
	return (target);
}
