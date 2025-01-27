/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:45:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/27 11:58:05 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

t_list *ft_lstnew(int content)
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	current = (*lst);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nbr * 10 + (nptr[i++] - '0');
	return (nbr * sign);
}

int ft_checker(char *str)
{
	int	i;
	int j;

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
		while ((str[i] && ((str[0] != '-' && str[i] <= "2147483647"[i] && "2147483647"[i])))
			|| (str[0] == '-' && str[i] <= "-2147483648"[i] && "-2147483648"[i]))
			i++;
		if (str[i])
			return (0);
	}
	return (1);
}

void ft_printlst(t_list *lst)
{
	while (lst)  
	{
		printf("%i\n", lst -> content);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
    t_list	*lstA;
	t_list	*lstB;
    int     i;

    if (argc < 3)
        return(0);
    i = 1;
	if (!(ft_checker(argv[i])))
			return(0);
	lstA = ft_lstnew(atoi(argv[i]));
    while (++i < argc)
    {
		if (!(ft_checker(argv[i])))
			return(0);
        ft_lstadd_last(&lstA, ft_lstnew(ft_atoi(argv[i])));
    }
	lstB = NULL;
	printf("%i\n", ft_lstindx(lstA, 5));
	ft_push(&lstA, &lstB);
	printf("%i\n", ft_lstindx(lstA, 5));
}
