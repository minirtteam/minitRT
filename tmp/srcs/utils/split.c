/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:26:38 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 16:05:17 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char *s, int size)
{
	char	*ret;
	int		i;

	ret = ft_calloc(size + 1);
	i = -1;
	while (++i < size)
		ret[i] = s[i];
	return (ret);
}

t_lst	*ft_split_lst(char *s)
{
	int		i;
	char	*data;
	t_lst	*to_push;
	t_lst	*ret;

	ret = NULL;
	while (*s)
	{
		while (ft_str_find(" \t\n\v\f\r", *s) != -1)
			s++;
		i = 0;
		while (s[i] && ft_str_find(" \t\n\v\f\r", s[i]) == -1)
			i++;
		data = ft_substr(s, i);
		to_push = mk_lst(data, F_DATA_CHAR);
		lst_push(&ret, to_push);
		s += i;
		while (ft_str_find(" \t\n\v\f\r", *s) != -1)
			s++;
	}
	return (ret);
}
