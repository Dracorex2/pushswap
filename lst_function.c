/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:09:26 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/10 13:40:28 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (0);
	res->content = content;
	res->next = 0;
	return (res);
}

void	ft_lstadd_last(t_list **lst, t_list *new)
{
	t_list	*res;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	res = (*lst);
	while (res-> next != 0)
		res = res-> next;
	res->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	while ((*lst))
	{
		next = (*lst)-> next;
		free((*lst));
		(*lst) = next;
	}
}
