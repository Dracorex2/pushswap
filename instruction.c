/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:15 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/06 11:37:29 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push(t_list **lstFROM, t_list **lstTO, char c)
{
	t_list *lstTMP;
	
	lstTMP = (*lstFROM);
	(*lstFROM) = (*lstFROM) -> next;
	if (lstTO)
		lstTMP->next = (*lstTO);
	(*lstTO) = lstTMP; 
	if (c == 'a' || c == 'b')
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_swap(t_list **lst, char c)
{
	t_list *lstTMP;
	
	lstTMP = (*lst)->next;
	(*lst)->next = lstTMP->next;
	lstTMP->next = (*lst);	
	(*lst) = lstTMP;
	if (c == 'a' || c == 'b')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rotate(t_list **lst, char c)
{
	t_list *lstTMP;
	t_list *lstCross;

	lstTMP = (*lst)->next;
	lstCross = (*lst);
	while (lstCross->next != NULL)
		lstCross = lstCross->next;
	(*lst)->next = NULL;
	lstCross->next = (*lst);
	(*lst) = lstTMP;
	if (c == 'a' || c == 'b')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_rrotate(t_list **lst, char c)
{
	t_list *lstCross;
	t_list *lstPreCross;

	lstCross = (*lst);
	while (lstCross->next != NULL)
	{
		lstPreCross = lstCross;
		lstCross = lstCross->next;
	}
	lstPreCross->next = NULL;
	lstCross->next = (*lst);
	(*lst) = lstCross;
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
