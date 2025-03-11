/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:15 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/10 17:23:31 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push(t_list **lstFROM, t_list **lstTO, char c)
{
	t_list	*lsttmp;

	if (!(*lstFROM) || !(*lstFROM)-> next)
		return ;
	lsttmp = (*lstFROM);
	(*lstFROM) = (*lstFROM)-> next;
	if (lstTO)
		lsttmp -> next = (*lstTO);
	(*lstTO) = lsttmp;
	if (c == 'a' || c == 'b')
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_swap(t_list **lst, char c)
{
	t_list	*lsttmp;

	if (!(*lst) || !(*lst)-> next)
		return ;
	lsttmp = (*lst)-> next;
	(*lst)-> next = lsttmp -> next;
	lsttmp -> next = (*lst);
	(*lst) = lsttmp;
	if (c == 'a' || c == 'b')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(t_list **lst, char c)
{
	t_list	*lsttmp;
	t_list	*lstcross;

	if (!(*lst) || !(*lst)-> next)
		return ;
	lsttmp = (*lst)-> next;
	lstcross = (*lst);
	while (lstcross -> next != NULL)
		lstcross = lstcross -> next;
	(*lst)-> next = NULL;
	lstcross->next = (*lst);
	(*lst) = lsttmp;
	if (c == 'a' || c == 'b')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rrotate(t_list **lst, char c)
{
	t_list	*lstcross;
	t_list	*lstprecross;

	if (!(*lst) || !(*lst)-> next)
		return ;
	lstcross = (*lst);
	while (lstcross -> next != NULL)
	{
		lstprecross = lstcross;
		lstcross = lstcross -> next;
	}
	lstprecross -> next = NULL;
	lstcross -> next = (*lst);
	(*lst) = lstcross;
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_drotate(t_list **lstA, t_list **lstB, char *str)
{
	if (ft_strncmp(str, "rrrn", 4))
	{
		ft_rrotate(lstA, 'n');
		ft_rrotate(lstB, 'n');
	}
	else if (ft_strncmp(str, "rrn", 3))
	{
		ft_rotate(lstA, 'n');
		ft_rotate(lstB, 'n');
	}
	else if (ft_strncmp(str, "rrr", 3))
	{
		ft_rrotate(lstA, 'n');
		ft_rrotate(lstB, 'n');
		write(1, "rrr\n", 4);
	}
	else if (ft_strncmp(str, "rr", 2))
	{
		ft_rotate(lstA, 'n');
		ft_rotate(lstB, 'n');
		write(1, "rr\n", 3);
	}
}
