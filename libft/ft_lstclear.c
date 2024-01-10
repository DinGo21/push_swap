/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:53:00 by disantam          #+#    #+#             */
/*   Updated: 2023/12/05 16:23:28 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*node;

	while (*lst != NULL)
	{
		node = *lst;
		*lst = node -> next;
		del(node -> val);
		free(node);
	}
	lst = NULL;
}
