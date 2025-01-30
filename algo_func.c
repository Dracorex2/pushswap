/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:38 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/30 19:20:06 by lucmansa         ###   ########.fr       */
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

int	ft_lstcost(t_list *lstA, t_list *lstB, int content)
{
	int i;

	i = 0;
	i = ft_lstindx(lstA, content);
	if (i > ft_lstcount(lstA) / 2)
		i = ft_lstcount(lstA) - i;
	if (content > ft_lstmax (lstB) || content < ft_lstmin (lstB))
	{
		if (ft_lstindx((lstB), ft_lstmax (lstB)) < ft_lstcount(lstB) / 2)
			i += ft_lstindx((lstB), ft_lstmax (lstB));
		else
			i += ft_lstcount(lstB) - ft_lstindx((lstB), ft_lstmax (lstB));
	}
	else
	{
		content = ft_nbneed(lstB, content);
		if (ft_lstindx((lstB), content) < ft_lstcount(lstB) / 2)
			i += ft_lstindx((lstB), content);
		else
			i += ft_lstcount(lstB) - ft_lstindx((lstB), content);
	}
	return (i + 1);
}

int	ft_lsttomove(t_list *lstA, t_list *lstB)
{
	int i;
	int	res;
	t_list *lstTMP;

	lstTMP = lstA;
	i = ft_lstcost(lstA, lstB, lstTMP->content);
	while (lstTMP)
	{
		if (i >= ft_lstcost(lstA, lstB, lstTMP->content))
		{
			i = ft_lstcost(lstA, lstB, lstTMP->content);
			res = lstTMP->content;
		}
		lstTMP = lstTMP->next;	
	}
	return (res);
}
int ft_nbneed(t_list *lst, int nb)
{
	int res;

	res = 0;
	while (lst)
	{
		if ((lst ->content < nb) && (lst ->content >= res))
			res = lst ->content;
		lst = lst->next;
	}
	return (res);
}

void ft_lstmove(t_list **lstA, t_list **lstB)
{
	int move;

	move = ft_lsttomove((*lstA), (*lstB));
	if (ft_lstindx((*lstA), move) < ft_lstcount((*lstA)) / 2)
		while ((*lstA) -> content != move)
			ft_rotate(lstA, 'a');
	else
		while ((*lstA) -> content != move)
			ft_rrotate(lstA, 'a');
	if (move > ft_lstmax((*lstB)) || move < ft_lstmin((*lstB)))
	{
		if (ft_lstindx((*lstB), ft_lstmax((*lstB))) < ft_lstcount((*lstB)) / 2)
			while ((*lstB) -> content != ft_lstmax((*lstB)))
				ft_rotate(lstB, 'b');
		else
			while ((*lstB) -> content != ft_lstmax((*lstB)))
				ft_rrotate(lstB, 'b');
	}
	else
	{
		move = ft_nbneed((*lstB), move);
		if (ft_lstindx((*lstB), move) < ft_lstcount((*lstB)) / 2)
			while ((*lstB) -> content != move)
				ft_rotate(lstB, 'b');
		else
			while ((*lstB) -> content != move)
				ft_rrotate(lstB, 'b');
	}
	ft_push(lstA, lstB, 'b');
}
/////////////////////////////////
int ft_checksorted(t_list *lst)
{
	int i;

	i = lst ->content;
	while (lst)
	{
		lst = lst -> next;
		if (i > lst ->content)
			return (0);
		i = lst ->content;
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
//////////////////////////////////////////////////////////

void ft_pushback(t_list **lstA, t_list **lstB)
{
	if (ft_lstmax((*lstB)) > ft_lstmax((*lstA)))
		ft_push(lstB, lstA, 'a');
	while ((*lstB))
	{
		while ((*lstB) -> content > (*lstA) -> content)
			ft_rotate(lstA, 'a');
		ft_push(lstB, lstA, 'a');
	}
}

//90 24 39 53 59 71 69 9 46 30