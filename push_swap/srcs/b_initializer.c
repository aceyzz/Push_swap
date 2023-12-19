/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_initializer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:20:43 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/17 14:12:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* ------------------------------------------------------------------------- */
/*  Met à jour le nœud cible pour chaque élément de la pile B en trouvant    */
/*  le nœud correspondant dans la pile A.                                    */
/* ------------------------------------------------------------------------- */
static void	update_btarget(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/* -------------------------------------------------------------------------- */
/*  Utilise les fonctions précédentes pour initialiser les propriétés des     */
/*  éléments de la pile B, telles que les indices, les nœuds cibles.          */
/* -------------------------------------------------------------------------- */
void	bnode_initializer(t_stack *a, t_stack *b)
{
	update_index(a);
	update_index(b);
	update_btarget(a, b);
}
