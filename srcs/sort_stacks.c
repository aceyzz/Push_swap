/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:14:47 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:59 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  Effectue une rotation simultanée des piles 'a' et 'b' jusqu'à ce que le   */
/*  nœud le moins cher atteigne sa position cible.                            */
/* -------------------------------------------------------------------------- */
static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	update_index(*a);
	update_index(*b);
}

/* -------------------------------------------------------------------------- */
/*  Effectue une rotation inverse simultanée des piles 'a' et 'b' jusqu'à     */
/*  ce que le nœud le moins cher atteigne sa position cible.                  */
/* -------------------------------------------------------------------------- */
static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	update_index(*a);
	update_index(*b);
}

/* -------------------------------------------------------------------------- */
/*  Déplace les éléments nécessaires entre les piles 'a' et 'b' pour          */
/*  effectuer une opération de poussée ou de tirage.                          */
/* -------------------------------------------------------------------------- */
static void	mover(t_stack **a, t_stack **b, bool side)
{
	t_stack	*cheapest_node;

	if (side == false)
	{
		cheapest_node = get_cheapest(*a);
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			rev_rotate_both(a, b, cheapest_node);
		prep_for_push(a, cheapest_node, 'a');
		prep_for_push(b, cheapest_node->target_node, 'b');
		pb(b, a, false);
	}
	else
	{
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b, false);
	}
}

/* -------------------------------------------------------------------------- */
/*  Place le nœud minimum au sommet de la pile 'a'.                           */
/* -------------------------------------------------------------------------- */
static void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

/* -------------------------------------------------------------------------- */
/*  ALGORITHME PRINCIPAL                                                      */
/*  Trie les piles 'a' et 'b' en utilisant l'algorithme Turkey Sort.          */
/* -------------------------------------------------------------------------- */
void	sort_turk(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_is_sorted(*a))
	{
		anode_initializer(*a, *b);
		mover(a, b, false);
	}
	sort_3(a);
	while (*b)
	{
		bnode_initializer(*a, *b);
		mover(a, b, true);
	}
	update_index(*a);
	min_on_top(a);
}
