/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:00:18 by disantam          #+#    #+#             */
/*   Updated: 2024/01/09 15:39:57 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

/* utils.c */
int		check_list(t_list *lst);
void	lstclean(t_list **lst);
void	parse_error(char **tmp, int e);
void	list_error(t_list **lst, char **tmp, int e);
int		issorted(t_list *lst);

/* parse.c */
int		pushswap_atoi(const char *str, char **tmp, int e);
void	add_nodes(t_list **lst, char **args, int e);
void	add_index(t_list **lst);

/* swap.c */
t_list	*swap_a(t_list *a);
t_list	*swap_b(t_list *b);
void	swap_s(t_list **a, t_list **b);

/* rotate.c */
t_list	*rotate_a(t_list *a);
t_list	*rotate_b(t_list *b);
void	rotate_r(t_list **a, t_list **b);

/* rrotate.c */
t_list	*rrotate_a(t_list *a);
t_list	*rrotate_b(t_list *b);
void	rrotate_r(t_list **a, t_list **b);

/* push.c */
void	push_a(t_list **b, t_list **a);
void	push_b(t_list **a, t_list **b);

/* sorts.c */
t_list	*small_sort(t_list *a, t_list *b);

/*radix.c*/
t_list	*radix_sort(t_list *a, t_list *b);

#endif
