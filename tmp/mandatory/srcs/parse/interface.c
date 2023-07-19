/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:25 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/19 10:24:53 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

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
	if (*amb == NULL || *cam == NULL || *lights == NULL)
		ft_error();
	return (objs);
}
