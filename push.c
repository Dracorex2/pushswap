/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:15 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/22 13:39:31 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push(t_list **lstFROM, t_list **lstTO)
{
	t_list *lstTMP;
	
	lstTMP = (*lstFROM);
	(*lstFROM) = (*lstFROM) -> next;
	lstTMP->next = (*lstTO);
	(*lstTO) = lstTMP; 
}

void	ft_swapA(t_list **lstA)
{
	t_list *lstTMP;
	
	lstTMP = (*lstA);
	(*lstA) = (*lstA) -> next;
	(*lstA)->next = lstTMP;
}