/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:22:44 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/10 12:04:28 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstcost(t_list *lstA, t_list *lstB, int nb)
{
	int	ra;
	int	rb;
	int	need;

	ra = 0;
	rb = 0;
	need = ft_nbneed(lstB, nb);
	ra = ft_lstindx(lstA, nb);
	if (ra > ft_lstcount(lstA) / 2)
		ra = -(ft_lstrevindx(lstA, nb));
	rb = ft_lstindx(lstB, need);
	if (rb > ft_lstcount(lstB) / 2)
		rb = -(ft_lstrevindx(lstB, need));
	if (ra > 0 && rb > 0)
		return (ft_bigger(ra, rb));
	else if (ra < 0 && rb < 0)
		return (ft_bigger(ft_abs(ra), ft_abs(rb)));
	else
		return (ft_abs(ra) + ft_abs(rb));
}

int	ft_lsttomove(t_list *lstA, t_list *lstB)
{
	int		i;
	int		res;
	t_list	*lsttmp;

	lsttmp = lstA;
	i = ft_lstcost(lstA, lstB, lsttmp -> content);
	while (lsttmp)
	{
		if (i >= ft_lstcost(lstA, lstB, lsttmp->content))
		{
			i = ft_lstcost(lstA, lstB, lsttmp->content);
			res = lsttmp->content;
		}
		lsttmp = lsttmp->next;
	}
	return (res);
}

int	ft_nbneed(t_list *lst, int nb)
{
	int	res;

	if (nb > ft_lstmax(lst) || nb < ft_lstmin(lst))
		return (ft_lstmax(lst));
	res = 0;
	while (lst)
	{
		if ((lst ->content < nb) && (lst ->content >= res))
			res = lst ->content;
		lst = lst->next;
	}
	return (res);
}

void	ft_lstmove(t_list **lstA, t_list **lstB)
{
	int	to_move;
	int	need;

	to_move = ft_lsttomove((*lstA), (*lstB));
	need = ft_nbneed((*lstB), to_move);
	if ((ft_lstindx((*lstA), to_move) <= (ft_lstcount((*lstA)) / 2))
		&& (ft_lstindx((*lstB), need) <= (ft_lstcount((*lstB)) / 2)))
		while (((*lstA)-> content != to_move) && (*lstB)-> content != need)
			ft_drotate(lstA, lstB, 'n');
	else if ((ft_lstindx((*lstA), to_move) >= (ft_lstcount((*lstA)) / 2))
		&& (ft_lstindx((*lstB), need) >= (ft_lstcount((*lstB)) / 2)))
		while (((*lstA)-> content != to_move) && (*lstB)-> content != need)
			ft_drotate(lstA, lstB, 'r');
	if (ft_lstindx((*lstA), to_move) <= (ft_lstcount((*lstA)) / 2))
		while ((*lstA)-> content != to_move)
			ft_rotate(lstA, 'a');
	else if (ft_lstindx((*lstA), to_move) >= (ft_lstcount((*lstA)) / 2))
		while ((*lstA)-> content != to_move)
			ft_rrotate(lstA, 'a');
	if (ft_lstindx((*lstB), need) <= (ft_lstcount((*lstB)) / 2))
		while ((*lstB)-> content != need)
			ft_rotate(lstB, 'b');
	else if (ft_lstindx((*lstB), need) >= (ft_lstcount((*lstB)) / 2))
		while ((*lstB)-> content != need)
			ft_rrotate(lstB, 'b');
}
