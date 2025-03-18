/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:53:31 by lucmansa          #+#    #+#             */
/*   Updated: 2025/03/18 15:39:15 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sswap(t_list **lsta, t_list **lstb)
{
	ft_swap(lsta, 'n');
	ft_swap(lstb, 'n');
}

int	ft_ex_action(t_list **lsta, t_list **lstb, char *str)
{
	if (ft_strncmp(str, "sa\n", 3))
		return (ft_swap(lsta, 'n'), 1);
	else if (ft_strncmp(str, "sb\n", 3))
		return (ft_swap(lstb, 'n'), 1);
	else if (ft_strncmp(str, "ss\n", 3))
		return (ft_sswap(lsta, lstb), 1);
	else if (ft_strncmp(str, "pb\n", 3))
		return (ft_push(lsta, lstb, 'n'), 1);
	else if (ft_strncmp(str, "pa\n", 3))
		return (ft_push(lstb, lsta, 'n'), 1);
	else if (ft_strncmp(str, "ra\n", 3))
		return (ft_rotate(lsta, 'n'), 1);
	else if (ft_strncmp(str, "rb\n", 3))
		return (ft_rotate(lstb, 'n'), 1);
	else if (ft_strncmp(str, "rra\n", 4))
		return (ft_rrotate(lsta, 'n'), 1);
	else if (ft_strncmp(str, "rrb\n", 4))
		return (ft_rrotate(lstb, 'n'), 1);
	else if (ft_strncmp(str, "rr\n", 3))
		return (ft_drotate(lsta, lstb, "rrn"), 1);
	else if (ft_strncmp(str, "rrr\n", 4))
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
		{
			write(2, "Error\n", 6);
			get_next_line(0);
			free(str);
			ft_lstclear(lsta);
			ft_lstclear(lstb);
			exit(1);
		}
		free(str);
	}
	if (!(*lstb))
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
		return (ft_lstclear(&lsta), ft_lstclear(&lstb)
			, write(1, "KO\n", 3), 0);
}
