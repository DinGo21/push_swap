/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:57:10 by disantam          #+#    #+#             */
/*   Updated: 2023/12/28 12:10:09 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate_a(t_list *a)
{
	t_list	*node;

	node = a->next;
	ft_lstlast(a)->next = a;
	a->next = NULL;
	ft_printf("ra\n");
	return (node);
}

t_list	*rotate_b(t_list *b)
{
	t_list	*node;

	node = b->next;
	ft_lstlast(b)->next = b;
	b->next = NULL;
	ft_printf("rb\n");
	return (node);
}

void	rotate_r(t_list **a, t_list **b)
{
	*a = rotate_a(*a);
	*b = rotate_b(*b);
	ft_printf("rr\n");
}
