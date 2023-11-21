/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:17:30 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/17 14:25:23 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  - Initialise deux piles 'a' et 'b' a NULL.                                */
/*  - Parse les arguments (entre "" ou séparements !!).                       */
/*  - Si 'a' n'est pas triée, applique un algorithme et ecris chaque          */
/*    mouvements selon les commandes autorisées.                              */
/*  - Libère la mémoire allouée pour la pile 'a'.                             */
/* -------------------------------------------------------------------------- */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_creator(&a, argv + 1);
	if (argc == 2)
		free_args(argv);
	if (!stack_is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			sort_3(&a);
		else
			sort_turk(&a, &b);
	}
	free_stack(&a);
	return (0);
}
