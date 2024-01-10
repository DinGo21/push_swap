/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:21:48 by disantam          #+#    #+#             */
/*   Updated: 2024/01/10 16:11:55 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rrotate_a(t_list *a)
{
	t_list	*node;

	node = ft_lstlast(a);
	node->next = a;
	while (a->next != node)
	{
		a = a->next;
	}
	a->next = NULL;
	ft_printf("rra\n");
	return (node);
}

t_list	*rrotate_b(t_list *b)
{
	t_list	*node;

	node = ft_lstlast(b);
	node->next = b;
	while (b->next != node)
	{
		b = b->next;
	}
	b->next = NULL;
	ft_printf("rrb\n");
	return (node);
}

void	rrotate_r(t_list **a, t_list **b)
{
	*a = rrotate_a(*a);
	*b = rrotate_b(*b);
	ft_printf("rrr\n");
}
