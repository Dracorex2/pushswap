/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:38 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/27 11:53:02 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstmax(t_list **lst)
{
	int i;

	i = 0;
	i = (*lst) -> content;
	while ((*lst)->next != NULL)
	{
		if (i < (*lst) -> content)
			i = (*lst) -> content;
		(*lst) = (*lst)->next;
	}
	return (i);
}

int	ft_lstmin(t_list **lst)
{
	int i;

	i = 0;
	i = (*lst) -> content;
	while ((*lst)->next != NULL)
	{
		if (i > (*lst) -> content)
			i = (*lst) -> content;
		(*lst) = (*lst)->next;
	}
	return (i);
}

int	ft_lstindx(t_list *lst, int content)
{
	int i;

	i = 0;
	while (lst  -> next != NULL)
	{
		if (lst -> content == content)
			return (i);
		lst = lst -> next;
		i++;
	}
	return (i);
}

int	ft_lstcost(t_list *lstA, t_list *lstB, int content)
{
	int i;

	i = 0;

	i = ft_lstindx(lstA, content);
	while (lstB  -> next != NULL && lstB -> content > content)
	{
		lstB = lstB->next;
		i++;
	}
	return (i + 1);
}