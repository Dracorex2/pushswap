/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:07:13 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/10 11:54:53 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checksorted(t_list *lst)
{
	int	i;

	while (1)
	{
		i = lst ->content;
		lst = lst -> next;
		if (!lst)
			break ;
		if (i > lst ->content)
			return (0);
	}
	return (1);
}

void	ft_sort3(t_list **lst)
{
	if (ft_lstmax((*lst)) == (*lst)-> content)
		ft_rotate(lst, 'a');
	else if (ft_lstindx((*lst), ft_lstmax((*lst))) == 1)
		ft_rrotate(lst, 'a');
	if (!(ft_checksorted((*lst))))
		ft_swap(lst, 'a');
}
