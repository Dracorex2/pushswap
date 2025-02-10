/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:54 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/10 11:40:14 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_abs(int nb);
int		ft_bigger(int A, int B);
int		ft_lower(int A, int B);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);

void	ft_push(t_list **lstFROM, t_list **lstTO, char c);
void	ft_swap(t_list **lstA, char c);
void	ft_rotate(t_list **lst, char c);
void	ft_rrotate(t_list **lst, char c);
void	ft_drotate(t_list **lstA, t_list **lstB, char c);

int		ft_lstcost(t_list *lstA, t_list *lstB, int content);
int		ft_lstcount(t_list *lst);
int		ft_lstindx(t_list *lst, int content);
int		ft_lstmin(t_list *lst);
int		ft_lstmax(t_list *lst);
int		ft_lsttomove(t_list *lstA, t_list *lstB);
void	ft_lstmove(t_list **lstA, t_list **lstB);
int		ft_nbneed(t_list *lst, int nb);
void	ft_sort3(t_list **lst);
int		ft_checksorted(t_list *lst);
void	ft_pushback(t_list **lstA, t_list **lstB);
int		ft_lstrevindx(t_list *lst, int content);

int		ft_lstcost_back(t_list *lstA, t_list *lstB, int content);
int		ft_lsttomove_back(t_list *lstA, t_list *lstB);
int		ft_nbneed_back(t_list *lst, int nb);
void	ft_lstmove_back(t_list **lstA, t_list **lstB);

t_list	*ft_lstnew(int content);
void	ft_lstadd_last(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

#endif
