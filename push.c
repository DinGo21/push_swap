/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:59:35 by disantam          #+#    #+#             */
/*   Updated: 2023/11/27 12:31:14 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*node;

	node = *a;
	*a = (*a)->next;
	if (*b == NULL)
	{
		node->next = NULL;
		*b = node;
	}
	else
	{
		node->next = *b;
		*b = node;
	}
	ft_printf("pb\n");
}

void	push_a(t_list **b, t_list **a)
{
	t_list	*node;

	node = *b;
	*b = (*b)->next;
	if (*a == NULL)
	{
		node->next = NULL;
		*a = node;
	}
	else
	{
		node->next = *a;
		*a = node;
	}
	ft_printf("pa\n");
}
