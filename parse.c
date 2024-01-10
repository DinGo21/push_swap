/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:50:30 by disantam          #+#    #+#             */
/*   Updated: 2024/01/09 15:41:28 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pushswap_atoi(const char *str, char **tmp, int e)
{
	long	result;
	int		sign;

	result = 0;
	sign = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	while ((*str == '-' || *str == '+') && (*str < '0' || *str > '9'))
	{
		if (*str != '-' && *str != '+')
			parse_error(tmp, e);
		if (*str == '-')
			sign += 1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str != '\0')
		parse_error(tmp, e);
	if (sign % 2 != 0)
		result = -result;
	if (result > 2147483647 || result < -2147483648)
		parse_error(tmp, e);
	return ((int)result);
}

t_list	*get_nextmin(t_list	**lst)
{
	t_list	*head;
	t_list	*node;
	int		min;

	head = *lst;
	node = NULL;
	min = 0;
	if (head != NULL)
	{
		while (head != NULL)
		{
			if (head->in == -1 && (!min || head->val < node->val))
			{
				node = head;
				min = 1;
			}
			head = head->next;
		}
	}
	return (node);
}

void	add_index(t_list **lst)
{
	int		in;
	t_list	*head;

	head = get_nextmin(lst);
	in = 0;
	while (head != NULL)
	{
		head->in = in++;
		head = get_nextmin(lst);
	}
}

void	add_nodes(t_list **lst, char **args, int e)
{
	int		i;
	t_list	*node;

	i = 0;
	while (args[++i])
	{
		node = ft_lstnew(pushswap_atoi(args[i], args, e));
		if (!node)
			list_error(lst, args, e);
		node->in = -1;
		ft_lstadd_back(lst, node);
	}
	if (e == 1)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
	}
}
