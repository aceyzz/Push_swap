/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:05:52 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/17 14:34:23 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  Déplace le premier élément de la pile source 'src' vers la pile           */
/*  destination 'dst'.                                                        */
/*    -> pa pour push le 1er element de b vers a                              */
/*    -> pb pour push le 1er element de a vers b                              */
/* -------------------------------------------------------------------------- */
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
