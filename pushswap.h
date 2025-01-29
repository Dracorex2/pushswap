/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:54 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/28 14:52:59 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
#include<stdio.h>

typedef struct s_list
{
int content;
struct s_list *next;
} t_list;

void	ft_push(t_list **lstFROM, t_list **lstTO);
void	ft_swap(t_list **lstA);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);


int	ft_lstcost(t_list *lstA, t_list *lstB, int content);
int	ft_lstindx(t_list *lst, int content);
int	ft_lstmin(t_list *lst);
int	ft_lstmax(t_list *lst);

#endif