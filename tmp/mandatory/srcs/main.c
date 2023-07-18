/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:06:36 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:43:53 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

static void	ft_test(t_amb *amb, t_cam *cam, t_lst *lights, t_lst *objs)
{
	ft_putstr_fd("\n\n\e[95m======= OBJS TEST =======\e[0m\n\n", 1);
	printf("\e[32mtype: amb\e[0m\n");
	if (amb == NULL)
		ft_putstr_fd("data is NULL\n", 1);
	else
	{
		printf("ratio: %lf\n", amb->ratio);
		printf("r: %u\n", amb->r);
		printf("g: %u\n", amb->g);
		printf("b: %u\n", amb->b);
	}
	printf("\n\n");
	printf("\e[32mtype: cam\e[0m\n");
	printf("x: %lf\n", cam->x);
	printf("y: %lf\n", cam->y);
	printf("z: %lf\n", cam->z);
	printf("x_axis: %lf\n", cam->x_axis);
	printf("y_axis: %lf\n", cam->y_axis);
	printf("z_axis: %lf\n", cam->z_axis);
	printf("fov: %lf\n", cam->fov);
	printf("\n\n");
	printf("\e[32mtype: lights\e[0m\n");
	if (lights == NULL)
		ft_putstr_fd("data is NULL\n", 1);
	else
	{
		t_light *data = lights->data;
		printf("x: %lf\n", data->x);
		printf("y: %lf\n", data->y);
		printf("z: %lf\n", data->z);
		printf("ratio: %lf\n", data->ratio);
		printf("r: %u\n", data->r);
		printf("g: %u\n", data->g);
		printf("b: %u\n", data->b);
	}
	printf("\n\n");
	for (int i=1; objs != NULL; i++)
	{
		printf("\e[96m======= obj - %d =======\e[0m\n\n", i);
		if (objs->info == F_SP)
		{
			t_sphere *data = objs->data;
			printf("\e[32mtype: sphere\e[0m\n");
			printf("x: %lf\n", data->x);
			printf("y: %lf\n", data->y);
			printf("z: %lf\n", data->z);
			printf("diameter: %lf\n", data->diameter);
			printf("r: %u\n", data->r);
			printf("g: %u\n", data->g);
			printf("b: %u\n", data->b);
		}
		else if (objs->info == F_PL)
		{
			t_plane *data = objs->data;
			printf("\e[32mtype: plane\e[0m\n");
			printf("x: %lf\n", data->x);
			printf("y: %lf\n", data->y);
			printf("z: %lf\n", data->z);
			printf("x_axis: %lf\n", data->x_axis);
			printf("y_axis: %lf\n", data->y_axis);
			printf("z_axis: %lf\n", data->z_axis);
			printf("r: %u\n", data->r);
			printf("g: %u\n", data->g);
			printf("b: %u\n", data->b);
		}
		else if (objs->info == F_CY)
		{
			t_cylinder *data = objs->data;
			printf("\e[32mtype: cylinder\e[0m\n");
			printf("x: %lf\n", data->x);
			printf("y: %lf\n", data->y);
			printf("z: %lf\n", data->z);
			printf("x_axis: %lf\n", data->x_axis);
			printf("y_axis: %lf\n", data->y_axis);
			printf("z_axis: %lf\n", data->z_axis);
			printf("diameter: %lf\n", data->diameter);
			printf("height: %lf\n", data->height);
			printf("r: %u\n", data->r);
			printf("g: %u\n", data->g);
			printf("b: %u\n", data->b);
		}
		printf("\n\n");
		objs = objs->nxt;
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

int	main(int argc, char **argv)
{
	t_amb	*amb;
	t_cam	*cam;
	t_lst	*lights;
	t_lst	*objs;

	if (argc != 2 || !is_rt_file(argv[1]))
		ft_error();
	amb = NULL;
	cam = NULL;
	lights = NULL;
	objs = ft_parse(argv[1], &amb, &cam, &lights);
	// ft_exe(amb, cam, lights, objs);
	ft_test(amb, cam, lights, objs);
	free(amb);
	free(cam);
	ft_lst_free(lights);
	ft_lst_free(objs);
	return (0);
}
