/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_initializer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:19:59 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/17 14:11:30 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  Assigne des indices aux éléments d'une pile et détermine s'ils            */
/*  se trouvent au-dessus ou en dessous de la médiane de la pile              */
/* -------------------------------------------------------------------------- */
void	update_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/* -------------------------------------------------------------------------- */
/*  Met à jour le nœud cible pour chaque élément de la pile A en trouvant     */
/*  le nœud correspondant dans la pile B.                                     */
/* -------------------------------------------------------------------------- */
static void	update_atarget(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/* -------------------------------------------------------------------------- */
/*  Calcule le coût de poussée pour chaque élément de la pile A en fonction   */
/*  de sa position, de la position de son nœud cible et de la taille des      */
/*  piles A et B.                                                             */
/* -------------------------------------------------------------------------- */
static void	update_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/* -------------------------------------------------------------------------- */
/*  Cherche le nœud de coût minimum dans la pile A.                           */
/* -------------------------------------------------------------------------- */
void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

/* -------------------------------------------------------------------------- */
/*  Utilise les fonctions précédentes pour initialiser les propriétés des     */
/*  éléments de la pile A, telles que les indices, les nœuds cibles, les      */
/*  coûts de poussée et le nœud le moins cher.                                */
/* -------------------------------------------------------------------------- */
void	anode_initializer(t_stack *a, t_stack *b)
{
	update_index(a);
	update_index(b);
	update_atarget(a, b);
	update_cost(a, b);
	set_cheapest(a);
}
