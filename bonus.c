/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:53:31 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/11 19:02:49 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, void **argv)
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
}