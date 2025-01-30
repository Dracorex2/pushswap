/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:54 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/30 19:17:56 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
#include<stdio.h>
#include<unistd.h>

typedef struct s_list
{
int content;
struct s_list *next;
} t_list;

void	ft_push(t_list **lstFROM, t_list **lstTO, char c);
void	ft_swap(t_list **lstA, char c);
void	ft_rotate(t_list **lst, char c);
void	ft_rrotate(t_list **lst, char c);


int	ft_lstcost(t_list *lstA, t_list *lstB, int content);
int ft_lstcount(t_list *lst);
int	ft_lstindx(t_list *lst, int content);
int	ft_lstmin(t_list *lst);
int	ft_lstmax(t_list *lst);
int	ft_lsttomove(t_list *lstA, t_list *lstB);
void ft_lstmove(t_list **lstA, t_list **lstB);
int ft_nbneed(t_list *lst, int nb);
void ft_sort3(t_list **lst);
int ft_checksorted(t_list *lst);
void ft_pushback(t_list **lstA, t_list **lstB);

#endif