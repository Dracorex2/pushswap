/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmansa <lucmansa@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:46:54 by lucmansa          #+#    #+#             */
/*   Updated: 2025/01/22 13:38:27 by lucmansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
#include<stdio.h>

typedef struct s_list
{
int content;
struct s_list *next;
} t_list;

void	ft_push(t_list **lstFROM, t_list **lstTO);
void	ft_swapA(t_list **lstA);

#endif