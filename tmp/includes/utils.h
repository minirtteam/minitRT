/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:51:54 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/17 14:56:30 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

# define F_DATA_CHAR 1
# define F_DATA_LST 2

typedef struct s_lst
{
	void			*data;
	int				data_type;
	struct s_lst	*nxt;
	struct s_lst	*prev;
}	t_lst;

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
char		*ft_substr(char *s, int size);
t_lst		*ft_split_lst(char *s);
void		lst_push(t_lst **target, t_lst *to_push);
t_lst		*mk_lst(void *data, int data_type);
void		*ft_lst_free(t_lst *target);

#endif
