/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:06:36 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 14:57:24 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"

void	ft_test(t_lst *target)
{
	t_lst	*data;

	while (target != NULL)
	{
		ft_putstr_fd("======= data =======\n", 1);
		data = target->data;
		while (data != NULL)
		{
			ft_putstr_fd(data->data, 1);
			ft_putstr_fd("\n", 1);
			data = data->nxt;
		}
		ft_putstr_fd("\n", 1);
		target = target->nxt;
	}
}

static int	is_rt_file(char *file_name)
{
	int	n;

	n = ft_strlen(file_name);
	if (file_name[n - 3] != '.' \
		|| file_name[n - 2] != 'r' \
		|| file_name[n - 1] != 't')
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_lst	*target;

	if (argc != 2 || !is_rt_file(argv[1]))
		ft_error();
	target = ft_parse(argv[1]);
	// ft_exe(target);
	ft_test(target);
	return (0);
}
