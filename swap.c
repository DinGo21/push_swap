/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:50:16 by disantam          #+#    #+#             */
/*   Updated: 2023/12/28 12:10:56 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_a(t_list *a)
{
	t_list	*node;

	node = a->next;
	a->next = node->next;
	node->next = a;
	ft_printf("sa\n");
	return (node);
}

t_list	*swap_b(t_list *b)
{
	t_list	*node;

	node = b->next;
	b->next = node->next;
	node->next = b;
	ft_printf("sb\n");
	return (node);
}

void	swap_s(t_list **a, t_list **b)
{
	*a = swap_a(*a);
	*b = swap_b(*b);
	ft_printf("ss\n");
}
