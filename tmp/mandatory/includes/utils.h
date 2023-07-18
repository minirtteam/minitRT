/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:54 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/18 10:32:12 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // test code
# include "data_type.h"

void			*ft_calloc(int size);
unsigned int	ft_atou(char *s);
double			ft_atod(char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_error(void);
int				ft_strlen(char *s);
int				ft_strnlen(const char *s, int maxlen);
int				ft_strcmp(char *s1, char *s2);
char			*ft_trim(char *s);
int				ft_str_find(char *s, char to_find);
char			*ft_substr(char *s, int size);
t_lst			*ft_split_lst(char *s);
void			lst_push(t_lst **target, t_lst *to_push);
t_lst			*mk_lst(void *data, int data_type, int info);
void			*ft_lst_free(t_lst *target);

#endif
