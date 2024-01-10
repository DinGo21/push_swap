/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:38:39 by disantam          #+#    #+#             */
/*   Updated: 2024/01/10 16:10:50 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*create_list(int argc, char **argv)
{
	int		e;
	char	**args;
	t_list	*lst;

	e = 0;
	args = argv + 1;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			exit(EXIT_FAILURE);
		args = ft_split(argv[1], ' ');
		if (!args)
			parse_error(args, 0);
		e = 1;
	}
	lst = ft_lstnew(pushswap_atoi(args[0], args, e));
	if (!lst)
		list_error(&lst, args, e);
	add_nodes(&lst, args, e);
	if (check_list(lst))
		list_error(&lst, NULL, 0);
	add_index(&lst);
	return (lst);
}

int	main(int argc, char *argv[])
{
	t_list	*alst;
	t_list	*blst;

	if (argc < 2)
	{
		exit(EXIT_FAILURE);
	}
	alst = create_list(argc, argv);
	blst = NULL;
	if (issorted(alst))
	{
		lstclean(&alst);
		return (EXIT_SUCCESS);
	}
	if (ft_lstsize(alst) <= 5)
	{
		alst = small_sort(alst, blst);
	}
	else
	{
		alst = radix_sort(alst, blst);
	}
	lstclean(&alst);
	return (EXIT_SUCCESS);
}
