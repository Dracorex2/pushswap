/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/12 16:51:50 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(t_list	**lstA, t_list	**lstB)
{
	if (ft_lstcount((*lstA)) > 3)
	{
		ft_push(lstA, lstB, 'b');
		ft_push(lstA, lstB, 'b');
	}
	while (ft_lstcount((*lstA)) > 3)
	{
		ft_lstmove(lstA, lstB);
		ft_push(lstA, lstB, 'b');
	}
	ft_sort3(lstA);
	while ((*lstB))
		ft_lstmove_back(lstA, lstB);
	if (ft_lstindx((*lstA), ft_lstmin((*lstA))) < ft_lstcount((*lstA)) / 2)
		while ((*lstA)-> content != ft_lstmin((*lstA)))
			ft_rotate(lstA, 'a');
	else
		while ((*lstA)-> content != ft_lstmin((*lstA)))
			ft_rrotate(lstA, 'a');
}

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	int		i;

	if (argc == 1)
		return (0);
	i = 1;
	if (!(ft_checker(argv[i])))
		return (write(2, "Error\n", 6), 1);
	lsta = ft_lstnew(atoi(argv[i]));
	while (++i < argc)
	{
		if (!ft_checker(argv[i]) || !ft_checkdouble(lsta, ft_atol(argv[i])))
			return (ft_lstclear(&lsta), write(2, "Error\n", 6), 1);
		ft_lstadd_last(&lsta, ft_lstnew(ft_atol(argv[i])));
	}
	lstb = NULL;
	if (!ft_checksorted(lsta))
		ft_sort(&lsta, &lstb);
	return (ft_lstclear(&lsta), 0);
}
