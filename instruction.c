/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:15 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/23 16:54:38 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push(t_list **lstFROM, t_list **lstTO)
{
	t_list *lstTMP;
	
	lstTMP = (*lstFROM);
	(*lstFROM) = (*lstFROM) -> next;
	if (lstTO)
		lstTMP->next = (*lstTO);
	(*lstTO) = lstTMP; 
}

void	ft_swap(t_list **lst)
{
	t_list *lstTMP;
	
	lstTMP = (*lst)->next;
	(*lst)->next = lstTMP->next;
	lstTMP->next = (*lst);	
	(*lst) = lstTMP;

}

void	ft_rotate(t_list **lst)
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
}

void	ft_rrotate(t_list **lst)
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
}
