/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:38:32 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:52:39 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// lst로 데이터를 저장하는 경우
// 1. 처음 파일에서 데이터를 파싱할 때 한 줄.
// 2. light에 대한 정보 (보너스가 여러 light를 받는거로 구현하라고 되있어서)
// 3. sphere / plane / cylinder에 대한 정보
// 3번의 경우 전부 다 하나의 list에 연결해줄거라서
// info에 각각의 node가 어떤 object에 대한 데이터를 가지고 있는지 표시해줌.
// ex) list가 각각 순서대로 sphere, sphere, plane, cylinder, ... 의 데이터를 저장하고 있는 경우
// 각각의 node의 info 안에는 F_SP, F_SP, F_PL, F_CY의 값이 저장됨. (data_type.h 참고)

t_lst	*mk_lst(void *data, int data_type, int info)
{
	t_lst	*target;

	// malloc 실패의 경우 ft_calloc 함수 안에서 exit을 해줌.
	target = ft_calloc(sizeof(t_lst));
	target->data = data;
	target->data_type = data_type;
	target->info = info;
	return (target);
}

void	lst_push(t_lst **target, t_lst *to_push)
{
	t_lst	*tmp;

	tmp = *target;
	// push하려는 lst의 값이 아직 아무것도 없을 때
	if (tmp == NULL)
	{
		*target = to_push;
		(*target)->size = 1;
		return ;
	}
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	tmp->nxt = to_push;
	if (to_push != NULL)
		to_push->prev = tmp;
	(*target)->size++;
}
