/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/11 16:01:06 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checker(char *str)
{
	if (ft_strlen(str) > 15 || ft_atol(str) > 2147483647
		|| ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_checkdouble(t_list *lst, int nb)
{
	while (lst)
	{
		if (lst -> content == nb)
			return (0);
		lst = lst -> next;
	}
	return (1);
}

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

	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
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
