/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:21:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/07 13:10:05 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstcost_back(t_list *lstA, t_list *lstB, int nb)
{
	int	rA;
	int	rB;
	int need;

	rA = 0;
	rB = 0;
	need = ft_nbneed_back(lstA, nb);
	rB = ft_lstindx(lstA, nb);
	if (rB > ft_lstcount(lstB) / 2)
		rB = -(ft_lstrevindx(lstB, nb));
	rA = ft_lstindx(lstA, need);
	if (rA > ft_lstcount(lstA) / 2)
		rA = -(ft_lstrevindx(lstA, need));
	if (rA > 0 && rB > 0)
		return(ft_bigger(rA, rB));
	else if (rA < 0 && rB < 0)
		return(ft_bigger(ft_abs(rA), ft_abs(rB)));
	else
		return (ft_abs(rA) + ft_abs(rB));
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

	if (nb > ft_lstmax(lst) || nb < ft_lstmin(lst))
		return (ft_lstmax(lst));
	res = 0;
	while (lst)
	{
		if ((lst ->content > nb) && (lst ->content >= res))
			res = lst ->content;
		lst = lst->next;
	}
	return (res);
}

void ft_lstmove_back(t_list **lstA, t_list **lstB)
{
	int to_move;
	int need;

	need = ft_lsttomove_back((*lstA), (*lstB));
	to_move = ft_nbneed_back((*lstA), need);
	if ((ft_lstindx((*lstA), to_move) <= (ft_lstcount((*lstA)) / 2))
		&& (ft_lstindx((*lstB), need) <= (ft_lstcount((*lstB)) / 2)))
			while (((*lstA) -> content != to_move) && (*lstB) -> content != need)
				ft_drotate(lstA, lstB, 'n');
	else if ((ft_lstindx((*lstA), to_move) >= (ft_lstcount((*lstA)) / 2))
		&& (ft_lstindx((*lstB), need) >= (ft_lstcount((*lstB)) / 2)))
			while (((*lstA) -> content != to_move) && (*lstB) -> content != need)
				ft_drotate(lstA, lstB, 'r');
	if (ft_lstindx((*lstA), to_move) <= (ft_lstcount((*lstA)) / 2))
		while ((*lstA) -> content != to_move)
			ft_rotate(lstA, 'a');
	else if (ft_lstindx((*lstA), to_move) >= (ft_lstcount((*lstA)) / 2))
		while ((*lstA) -> content != to_move)
			ft_rrotate(lstA, 'a');
	if (ft_lstindx((*lstB), need) <= (ft_lstcount((*lstB)) / 2))
		while ((*lstB) -> content != need)
			ft_rotate(lstB, 'b');
	else if (ft_lstindx((*lstB), need) >= (ft_lstcount((*lstB)) / 2))
		while ((*lstB) -> content != need)
			ft_rrotate(lstB, 'b');
	ft_push(lstB, lstA, 'a');
}
