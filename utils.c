/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:51:47 by disantam          #+#    #+#             */
/*   Updated: 2024/01/09 16:22:38 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		lst = node->next;
		while (lst != NULL)
		{
			if (node->val == lst->val)
				return (1);
			lst = lst->next;
		}
		node = node->next;
	}
	return (0);
}

int	issorted(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		lst = node->next;
		while (lst != NULL)
		{
			if (node->in > lst->in)
				return (0);
			lst = lst->next;
		}
		node = node->next;
	}
	return (1);
}

void	parse_error(char **tmp, int e)
{
	int	i;

	if (e == 1)
	{
		i = -1;
		while (tmp[++i])
			free(tmp[i]);
		free(tmp);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	lstclean(t_list **lst)
{
	t_list	*node;

	while (*lst != NULL)
	{
		node = *lst;
		*lst = node -> next;
		free(node);
	}
	lst = NULL;
}

void	list_error(t_list **lst, char **tmp, int e)
{
	int	i;

	if (e == 1)
	{
		i = -1;
		while (tmp[++i])
			free(tmp[i]);
		free(tmp);
	}
	lstclean(lst);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
