/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:38:10 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 12:39:35 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long long	ft_atoi(char *s)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	i = 0;
	sign = -(s[i] == '-') + (s[i] != '-');
	i += (s[i] == '+' || s[i] == '-');
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') \
			|| (res == 922337203685477580 && s[i] > ('7' + (sign == -1))))
			ft_error();
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (((s[0] == '-' || s[0] == '+') && i == 1) || i == 0)
		ft_error();
	return (res * sign);
}

double	ft_atod(char *s)
{
	int		sign;
	double	ret;
	int		i;
	int		n;

	i = ft_str_find(s, '.');
	n = -1;
	while (i != -1 && s[i])
	{
		s[i] = s[i + 1];
		i++;
		n++;
	}
	ret = ft_atoi(s);
	while (n-- > 0)
		ret /= 10;
	return (ret);
}
