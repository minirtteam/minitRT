/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_struct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:09:19 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:32:05 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

static t_sphere	*mk_sp(t_lst *target)
{
	t_sphere	*ret;

	ret = ft_calloc(sizeof(t_sphere));
	ft_get_coord(&ret->x, &ret->y, &ret->z, target->data);
	target = target->nxt;
	ret->diameter = ft_atod(target->data);
	target = target->nxt;
	ft_get_rgb(&ret->r, &ret->g, &ret->b, target->data);
	return (ret);
}

static t_plane	*mk_pl(t_lst *target)
{
	t_plane	*ret;

	ret = ft_calloc(sizeof(t_plane));
	ft_get_coord(&ret->x, &ret->y, &ret->z, target->data);
	target = target->nxt;
	ft_get_axis(&ret->x_axis, &ret->y_axis, &ret->z_axis, target->data);
	target = target->nxt;
	ft_get_rgb(&ret->r, &ret->g, &ret->b, target->data);
	return (ret);
}

static t_cylinder	*mk_cy(t_lst *target)
{
	t_cylinder	*ret;

	ret = ft_calloc(sizeof(t_cylinder));
	ft_get_coord(&ret->x, &ret->y, &ret->z, target->data);
	target = target->nxt;
	ft_get_axis(&ret->x_axis, &ret->y_axis, &ret->z_axis, target->data);
	target = target->nxt;
	ret->diameter = ft_atod(target->data);
	target = target->nxt;
	ret->height = ft_atod(target->data);
	target = target->nxt;
	ft_get_rgb(&ret->r, &ret->g, &ret->b, target->data);
	return (ret);
}

void	ft_parse_objs(t_lst **objs, t_lst *target)
{
	t_lst	*to_push;

	to_push = NULL;
	if (ft_strcmp(target->data, "sp") == 0 && target->size == 4)
		to_push = mk_lst(mk_sp(target->nxt), F_DATA_OBJS, F_SP);
	else if (ft_strcmp(target->data, "pl") == 0 && target->size == 4)
		to_push = mk_lst(mk_pl(target->nxt), F_DATA_OBJS, F_PL);
	else if (ft_strcmp(target->data, "cy") == 0 && target->size == 6)
		to_push = mk_lst(mk_cy(target->nxt), F_DATA_OBJS, F_CY);
	else
		ft_error();
	lst_push(objs, to_push);
}
