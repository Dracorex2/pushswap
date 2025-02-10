/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:21:19 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/10 11:54:39 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_nbneed_back(t_list *lst, int nb)
{
	int	res;

	if (nb > ft_lstmax(lst) || nb < ft_lstmin(lst))
		return (ft_lstmin(lst));
	res = __INT_MAX__;
	while (lst)
	{
		if ((lst ->content > nb) && (lst ->content <= res))
			res = lst ->content;
		lst = lst->next;
	}
	return (res);
}

void	ft_lstmove_back(t_list **lstA, t_list **lstB)
{
	int	to_move;
	int	need;

	to_move = (*lstB)-> content;
	need = ft_nbneed_back((*lstA), to_move);
	if (ft_lstindx((*lstA), need) <= (ft_lstcount((*lstA)) / 2))
		while ((*lstA)-> content != need)
			ft_rotate(lstA, 'a');
	else if (ft_lstindx((*lstA), need) >= (ft_lstcount((*lstA)) / 2))
		while ((*lstA)-> content != need)
			ft_rrotate(lstA, 'a');
	ft_push(lstB, lstA, 'a');
}
