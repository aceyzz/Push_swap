/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:18:09 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/17 14:18:24 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  Vérifie si les arguments passés sont bien TOUS des nombres, positifs      */
/*  ou négatifs.                                                              */
/* -------------------------------------------------------------------------- */
int	error_syntax(char *arg)
{
	if (!(*arg == '+' || *arg == '-' || (*arg >= '0' && *arg <= '9')))
		return (1);
	if ((*arg == '+' || *arg == '-')
		&& !(arg[1] >= '0' && arg[1] <= '9'))
		return (1);
	while (*++arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (1);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
/*  Vérifie si les arguments passés n'ont pas de doublons                     */
/* -------------------------------------------------------------------------- */
int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/* -------------------------------------------------------------------------- */
/*  Libère la memoire de tout éléments de la stack                            */
/* -------------------------------------------------------------------------- */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/* -------------------------------------------------------------------------- */
/*  Libère la memoire de tout éléments de la stack, write Error\n et          */
/*  termine l'execution du programme.                                         */
/* -------------------------------------------------------------------------- */
void	free_errors(t_stack **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
