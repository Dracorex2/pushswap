/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:38 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/03 10:46:11 by lucmansa         ###   ########.fr       */
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

int ft_lstcount(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++; 
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

/////////////////////////////////
int ft_checksorted(t_list *lst)
{
	int i;

	while (lst)
	{
		i = lst ->content;
		if (i > lst ->content)
			return (0);
		lst = lst -> next;
	}
	return (1);
}

void ft_sort3(t_list **lst)
{
	if (!(ft_checksorted((*lst))))
	{
		if (ft_lstmin((*lst)) == (*lst) ->content)
		{
			ft_rrotate(lst, 'a');
			ft_swap(lst, 'a');
		}
		else if (ft_lstmax((*lst)) == (*lst)-> content)
		{
			ft_rotate(lst, 'a');
			if (!(ft_checksorted(*lst)))
				ft_swap(lst, 'a');
		}
		else
		{
			if (ft_lstindx((*lst), ft_lstmax((*lst)) == 1))
				ft_rrotate(lst, 'a');
			else
				ft_swap(lst, 'a');
		}
	}
}

//90 24 39 53 59 71 69 9 46 30