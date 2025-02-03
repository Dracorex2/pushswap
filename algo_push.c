/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:22:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/03 10:23:23 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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