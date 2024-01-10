/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:35:33 by disantam          #+#    #+#             */
/*   Updated: 2023/12/27 13:03:53 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits(t_list *lst)
{
	int		max;
	int		bits;

	max = lst->in;
	lst = lst->next;
	while (lst != NULL)
	{
		if (max < lst->in)
		{
			max = lst->in;
		}
		lst = lst->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}

t_list	*radix_sort(t_list *a, t_list *b)
{
	int		i;
	int		j;
	int		size;
	int		bits;
	t_list	*head;

	head = a;
	size = ft_lstsize(head);
	bits = get_bits(head);
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			head = a;
			if (((head->in >> i) & 1) == 1)
				a = rotate_a(head);
			else
				push_b(&a, &b);
		}
		while (ft_lstsize(b) != 0)
			push_a(&b, &a);
	}
	return (a);
}
