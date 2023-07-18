/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:25 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 11:01:12 by hyunghki         ###   ########.fr       */
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

// light의 경우 보너스 부분의 빛을 여러개 파싱하도록 구현하는 문항을 염두에 두고
// lst로 받아주고 있습니다.

t_lst	*ft_parse(char *file_name, t_amb **amb, t_cam **cam, t_lst **lights)
{
	char	*data;
	t_lst	*target;
	t_lst	*tmp;
	t_lst	*objs;

	// file에 있는 데이터를 lst로 파싱해줍니다.
	// 비어있는 줄은 무시하고 넘어갑니다.
	// 자세한 내용은 ft_test함수를 통해 나오는 값으로 확인해볼 수 있습니다.
	target = get_data(file_name);
	// 빈 파일인 경우 error
	if (target == NULL)
		ft_error();
	objs = NULL;
	ft_test(target); // test code
	tmp = target;
	while (target != NULL)
	{
		data = ((t_lst *)target->data)->data;
		// subject에 camera, ambient, lights에 경우 identifier가 대문자라는 말이 있어서
		// 대문자를 기준으로 일반 오브젝트를 만들지 cam,amb,light를 만들지를 구분해주었습니다.
		if (*data >= 'A' && *data <= 'Z')
			ft_parse_acl(amb, cam, lights, target->data);
		else
			ft_parse_objs(&objs, target->data);
		target = target->nxt;
	}
	ft_lst_free(tmp);
	// camera의 값이 없을 경우 error
	if (*cam == NULL)
		ft_error();
	return (objs);
}
