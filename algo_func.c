/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:38 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:03 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstmax(t_list *lst)
{
	int i;

	i = 0;
	i = lst -> content;
	while (lst)
	{
		if (i < lst -> content)
			i = lst -> content;
		lst = lst->next;
	}
	return (i);
}

int	ft_lstmin(t_list *lst)
{
	int i;

	i = 0;
	i = lst -> content;
	while (lst)
	{
		if (i > lst -> content)
			i = lst -> content;
		lst = lst->next;
	}
	return (i);
}

int	ft_lstindx(t_list *lst, int content)
{
	int i;

	i = 0;
	while (lst)
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
	int max;
	int min;

	i = 0;

	i = ft_lstindx(lstA, content);
	while (1)
	{
		max = ft_lstmax (lstB);
		min = ft_lstmin (lstB);
		if (content > max || content < min)
			while (lstB->content != max && lstB->content != min)
			{
				lstB = lstB->next;
				i++;
			}
		else
			while (lstB->content > content)
			{
				lstB = lstB->next;
				i++;
			}
		break;
	}
	return (i + 1);
}
