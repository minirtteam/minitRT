/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:54 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 12:39:29 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

void		*ft_calloc(int size);
long long	ft_atoi(char *s);
double		ft_atod(char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_error(void);
int			ft_strlen(char *s);
int			ft_strnlen(const char *s, int maxlen);
int			ft_strcmp(char *s1, char *s2);
char		*ft_trim(char *s);
int			ft_str_find(char *s, char to_find);

#endif
