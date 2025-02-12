/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:54 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/12 16:59:32 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "./get_net_line/get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int				ft_strcmp(char *s1, char *s2);

int				ft_abs(int nb);
int				ft_bigger(int A, int B);
int				ft_lower(int A, int B);
long int		ft_atol(const char *nptr);
size_t			ft_strlen(const char *str);

void			ft_push(t_list **lstFROM, t_list **lstTO, char c);
void			ft_swap(t_list **lstA, char c);
void			ft_rotate(t_list **lst, char c);
void			ft_rrotate(t_list **lst, char c);
void			ft_drotate(t_list **lstA, t_list **lstB, char *str);

int				ft_lstcost(t_list *lstA, t_list *lstB, int content);
int				ft_lstcount(t_list *lst);
int				ft_lstindx(t_list *lst, int content);
int				ft_lstmin(t_list *lst);
int				ft_lstmax(t_list *lst);
int				ft_lsttomove(t_list *lstA, t_list *lstB);
void			ft_lstmove(t_list **lstA, t_list **lstB);
int				ft_nbneed(t_list *lst, int nb);
void			ft_sort3(t_list **lst);
int				ft_checksorted(t_list *lst);
void			ft_pushback(t_list **lstA, t_list **lstB);
int				ft_lstrevindx(t_list *lst, int content);

int				ft_lstcost_back(t_list *lstA, t_list *lstB, int content);
int				ft_lsttomove_back(t_list *lstA, t_list *lstB);
int				ft_nbneed_back(t_list *lst, int nb);
void			ft_lstmove_back(t_list **lstA, t_list **lstB);

t_list			*ft_lstnew(int content);
void			ft_lstadd_last(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);

int				ft_checker(char *str);
int				ft_checkdouble(t_list *lst, int nb);

#endif
