/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:38:32 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 14:39:55 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_lst	*mk_lst(void *data, int data_type)
{
	t_lst	*target;

	target = ft_calloc(sizeof(t_lst));
	target->data = data;
	target->data_type = data_type;
	return (target);
}

void	lst_push(t_lst **target, t_lst *to_push)
{
	t_lst	*tmp;

	tmp = *target;
	if (tmp == NULL)
	{
		*target = to_push;
		return ;
	}
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	tmp->nxt = to_push;
	if (to_push != NULL)
		to_push->prev = tmp;
}
