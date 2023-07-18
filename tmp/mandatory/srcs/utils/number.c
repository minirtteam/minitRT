/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:38:10 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:55:46 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// 평가지에 값이 null인 경우에도 rendering이 될 수 있게 구현하라고 나와있던게 생각나서
// data가 아무것도 없을때는 에러처리가 아닌 0을 리턴하게 했습니다.
// 다만 '-'나 '+'만 있는 경우에는 에러로 처리했습니다.

// double의 값의 경우 무한히 받을 수 있게 구현했습니다.
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

// atou함수의 경우 rgb값을 파싱할 때에만 사용됩니다.
// 그래서 범위를 0~255의 값만 받을 수 있게 했습니다.
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
