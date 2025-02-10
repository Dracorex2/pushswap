/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/10 12:23:43 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_checker(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '-')
		i++;
	j = i;
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (0);
		j++;
	}
	if (ft_strlen(&str[i]) >= 10)
	{
		while ((str[i] && ((str[0] != '-' && str[i] <= "2147483647"[i]
						&& "2147483647"[i])))
			|| (str[0] == '-' && str[i] <= "-2147483648"[i]
				&& "-2147483648"[i]))
			i++;
		if (str[i])
			return (0);
	}
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

int	ft_checkdouble(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = i;
		while (str[++j])
		{
			if (ft_strcmp(str[j], str[i]) == 0)
				return (0);
		}
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

	if (argc < 3 || !ft_checkdouble(argv))
		return (write(2, "Error\n", 6), 0);
	i = 1;
	if (!(ft_checker(argv[i])))
		return (write(2, "Error\n", 6), 0);
	lsta = ft_lstnew(atoi(argv[i]));
	while (++i < argc)
	{
		if (!(ft_checker(argv[i])))
			return (write(2, "Error\n", 6), 0);
		ft_lstadd_last(&lsta, ft_lstnew(ft_atoi(argv[i])));
	}
	lstb = NULL;
	ft_sort(&lsta, &lstb);
	return (ft_lstclear(&lsta), 1);
}
