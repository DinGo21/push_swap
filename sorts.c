/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:33:49 by disantam          #+#    #+#             */
/*   Updated: 2024/01/19 16:30:57 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_mindistance(t_list *lst)
{
	int		i;
	t_list	*min;
	t_list	*head;

	min = lst;
	head = lst;
	lst = lst->next;
	while (lst != NULL)
	{
		if (min->in > lst->in)
		{
			min = lst;
		}
		lst = lst->next;
	}
	i = 0;
	while (head->in != min->in)
	{
		head = head->next;
		i++;
	}
	return (i);
}

static t_list	*sort_3(t_list *a)
{
	t_list	*node;

	node = a;
	a = a->next;
	while (a->next != NULL)
	{
		if (node->next->val > a->next->val)
		{
			a = rrotate_a(node);
			node = a;
		}
		if (node->val > a->val)
		{
			a = swap_a(node);
			node = a;
		}
		a = a->next;
	}
	return (node);
}

static t_list	*sort_4(t_list *a, t_list *b)
{
	int		dis;
	t_list	*node;

	node = a;
	dis = get_mindistance(a);
	while (dis != 0)
	{
		if (dis == 1)
		{
			a = swap_a(a);
		}
		if (dis > 1)
		{
			a = rrotate_a(a);
		}
		dis = get_mindistance(a);
	}
	if (issorted(a))
	{
		return (a);
	}
	push_b(&a, &b);
	a = sort_3(a);
	push_a(&b, &a);
	return (a);
}

static t_list	*sort_5(t_list *a, t_list *b)
{
	int		dis;
	t_list	*node;

	node = a;
	dis = get_mindistance(a);
	while (dis != 0)
	{
		if (dis <= 2)
		{
			a = rotate_a(a);
		}
		if (dis > 2)
		{
			a = rrotate_a(a);
		}
		dis = get_mindistance(a);
	}
	if (issorted(a))
	{
		return (a);
	}
	push_b(&a, &b);
	a = sort_4(a, b);
	push_a(&b, &a);
	return (a);
}

t_list	*small_sort(t_list *a, t_list *b)
{
	if (ft_lstsize(a) == 2)
	{
		a = swap_a(a);
	}
	if (ft_lstsize(a) == 3)
	{
		a = sort_3(a);
	}
	if (ft_lstsize(a) == 4)
	{
		a = sort_4(a, b);
	}
	if (ft_lstsize(a) == 5)
	{
		a = sort_5(a, b);
	}
	b = NULL;
	return (a);
}
