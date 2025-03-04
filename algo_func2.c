/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:07:13 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/04 16:08:59 by lucmansa         ###   ########.fr       */
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

int	ft_checker(char *str)
{
	int	i;

	i = -1;
	if (str[++i] != '-')
		--i;
	if (!str[i + 1])
		return (0);
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 15 || ft_atol(str) > INT_MAX
		|| ft_atol(str) < INT_MIN)
		return (0);
	return (1);
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
