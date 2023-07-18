/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:25 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:32:06 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

void	ft_test(t_lst *target)
{
	t_lst	*data;

	ft_putstr_fd("\n\n\e[95m======= PARSING TEST =======\e[0m\n\n", 1);
	for (int i=1; target != NULL; i++)
	{
		printf("\e[96m======= data - %d =======\e[0m\n\n", i);
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

t_lst	*ft_parse(char *file_name, t_amb **amb, t_cam **cam, t_lst **lights)
{
	char	*data;
	t_lst	*target;
	t_lst	*tmp;
	t_lst	*objs;

	target = get_data(file_name);
	if (target == NULL)
		ft_error();
	objs = NULL;
	ft_test(target); // test code
	tmp = target;
	while (target != NULL)
	{
		data = ((t_lst *)target->data)->data;
		if (*data >= 'A' && *data <= 'Z')
			ft_parse_acl(amb, cam, lights, target->data);
		else
			ft_parse_objs(&objs, target->data);
		target = target->nxt;
	}
	ft_lst_free(tmp);
	if (*cam == NULL)
		ft_error();
	return (objs);
}
