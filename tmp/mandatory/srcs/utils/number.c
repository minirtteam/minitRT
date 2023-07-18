/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:38:10 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:32:39 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static double	get_num(char *s)
{
	double	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = -(s[i] == '-') + (s[i] != '-');
	i += (s[i] == '+' || s[i] == '-');
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			ft_error();
		res = res * 10 + s[i] - '0';
		i++;
	}
	if ((s[0] == '-' || s[0] == '+') && i == 1)
		ft_error();
	return (res * sign);
}

unsigned int	ft_atou(char *s)
{
	unsigned int	res;
	int				i;

	if (s == NULL)
		return (0);
	res = 0;
	i = (*s == '+');
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9' || (res == 25 && s[i] > '5'))
			ft_error();
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (s[0] == '+' && i == 1)
		ft_error();
	return (res);
}

double	ft_atod(char *s)
{
	double	ret;
	int		i;
	int		n;

	if (s == NULL)
		return (0);
	i = ft_str_find(s, '.');
	n = -1;
	while (i != -1 && s[i])
	{
		s[i] = s[i + 1];
		i++;
		n++;
	}
	ret = get_num(s);
	while (n-- > 0)
		ret /= 10;
	return (ret);
}
