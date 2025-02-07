/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:38 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/07 11:17:59 by lucmansa         ###   ########.fr       */
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

int	ft_lstcount(t_list *lst)
{
	int	i;

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
	int	i;

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


int	ft_lstrevindx(t_list *lst, int content)
{
	int	i;

	i = 0;
	while (lst -> content != content)
		lst = lst -> next;
	while (lst -> next)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

int ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}


/////////////////////////////////
int ft_checksorted(t_list *lst)
{
	int i;

	while (1)
	{
		i = lst ->content;
		lst = lst -> next;
		if (!lst)
			break;
		if (i > lst ->content)
			return (0);
	}
	return (1);
}

void ft_sort3(t_list **lst)
{
	if (ft_lstmax((*lst)) == (*lst)-> content)
		ft_rotate(lst, 'a');
	else if (ft_lstindx((*lst), ft_lstmax((*lst))) == 1)
		ft_rrotate(lst, 'a');
	if (!(ft_checksorted((*lst))))
		ft_swap(lst, 'a');
	return ;
}

//90 24 39 53 59 71 69 9 46 30