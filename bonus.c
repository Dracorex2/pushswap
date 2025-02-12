/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:53:31 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/12 18:17:44 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_ex_action(t_list **lsta, t_list **lstb, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (ft_swap(lsta, 'n'), 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (ft_swap(lstb, 'n'), 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (ft_push(lsta, lstb, 'n'), 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (ft_push(lstb, lsta, 'n'), 1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ft_rotate(lsta, 'n'), 1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (ft_rotate(lstb, 'n'), 1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (ft_rrotate(lsta, 'n'), 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (ft_rrotate(lstb, 'n'), 1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (ft_drotate(lsta, lstb, "rrn"), 1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (ft_drotate(lsta, lstb, "rrrn"), 1);
	else
		return (0);
}

int	ft_read_action(t_list **lsta, t_list **lstb)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!ft_ex_action(lsta, lstb, str))
			return (0);
		free(str);
	}
	if (ft_checksorted((*lsta)) && !(*lstb))
		return (1);
	else
		return (0);
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
	if (ft_read_action(&lsta, &lstb))
		return (ft_lstclear(&lsta), write(1, "OK\n", 3), 0);
	else
		return (ft_lstclear(&lsta), write(1, "KO\n", 3), 0);
}
