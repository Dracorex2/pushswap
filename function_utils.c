/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:08:12 by lucmansa          #+#    #+#             */
/*   Updated: 2025/02/11 15:57:32 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	ft_bigger(int A, int B)
{
	if (A > B)
		return (A);
	return (B);
}

int	ft_lower(int A, int B)
{
	if (A < B)
		return (A);
	return (B);
}

long int	ft_atol(const char *nptr)
{
	long int	nbr;
	int			i;
	int			sign;

	nbr = 0;
	i = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nbr * 10 + (nptr[i++] - '0');
	return (nbr * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
