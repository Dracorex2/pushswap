/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:21:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/06 11:00:37 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstcost_back(t_list *lstA, t_list *lstB, int content)
{
	int i;

	i = 0;
	i = ft_lstindx(lstB, content);
	if (i > ft_lstcount(lstB) / 2)
		i = ft_lstcount(lstB) - i;
	if (content > ft_lstmax (lstA) || content < ft_lstmin (lstA))
	{
		if (ft_lstindx((lstA), ft_lstmin (lstA)) < ft_lstcount(lstA) / 2)
			i += ft_lstindx((lstA), ft_lstmax (lstA));
		else
			i += ft_lstcount(lstA) - ft_lstindx((lstA), ft_lstmin (lstA));
	}
	else
	{
		content = ft_nbneed_back(lstA, content);
		if (ft_lstindx((lstA), content) < ft_lstcount(lstA) / 2)
			i += ft_lstindx((lstA), content);
		else
			i += ft_lstcount(lstA) - ft_lstindx((lstA), content);
	}
	return (i + 1);
}

int	ft_lsttomove_back(t_list *lstA, t_list *lstB)
{
	int i;
	int	res;
	t_list *lstTMP;

	lstTMP = lstB;
	i = ft_lstcost_back(lstA, lstB, lstTMP->content);
	while (lstTMP)
	{
		if (i >= ft_lstcost_back(lstA, lstB, lstTMP->content))
		{
			i = ft_lstcost_back(lstA, lstB, lstTMP->content);
			res = lstTMP->content;
		}
		lstTMP = lstTMP->next;	
	}
	return (res);
}

int ft_nbneed_back(t_list *lst, int nb)
{
	int res;

	res = __INT_MAX__;
	while (lst)
	{
		if ((lst ->content > nb) && (lst ->content <= res))
			res = lst ->content;
		lst = lst->next;
	}
	return (res);
}

void ft_lstmove_back(t_list **lstA, t_list **lstB)
{
	int move;

	move = ft_lsttomove_back((*lstA), (*lstB));
	if (ft_lstindx((*lstB), move) < ft_lstcount((*lstB)) / 2)
		while ((*lstB) -> content != move)
			ft_rotate(lstB, 'b');
	else
		while ((*lstB) -> content != move)
			ft_rrotate(lstB, 'b');
	if (move > ft_lstmax((*lstA)) || move < ft_lstmin((*lstA)))
	{
		if (ft_lstindx((*lstA), ft_lstmin((*lstA))) < ft_lstcount((*lstA)) / 2)
			while ((*lstA) -> content != ft_lstmin((*lstA)))
				ft_rotate(lstA, 'a');
		else
			while ((*lstA) -> content != ft_lstmin((*lstA)))
				ft_rrotate(lstA, 'a');
	}
	else
	{
		move = ft_nbneed_back((*lstA), move);
		if (ft_lstindx((*lstA), move) < ft_lstcount((*lstA)) / 2)
			while ((*lstA) -> content != move)
				ft_rotate(lstA, 'a');
		else
			while ((*lstA) -> content != move)
				ft_rrotate(lstA, 'a');
	}
	ft_push(lstB, lstA, 'a');
}
