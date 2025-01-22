/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:15 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/21 16:53:37 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pushB(t_list **lstA, t_list **lstB)
{
	t_list *lstTMP;
	
	lstTMP = lstA;
	lstA = (*lstA) -> next;
	lstTMP->next = lstB;
	lstB = lstTMP; 
}

void	ft_pushA(t_list **lstA, t_list **lstB)
{
	t_list *lstTMP;
	
	lstTMP = lstB;
	lstB = (*lstB) -> next;
	lstTMP->next = lstA;
	lstA = lstTMP; 
}