/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:05:10 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/15 20:18:35 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* ----------------------------------------------------------------- ERRORS.C */
int				error_syntax(char *str_n);
int				error_duplicate(t_stack *a, int n);
void			free_stack(t_stack **stack);
void			free_errors(t_stack **a);
/* ------------------------------------------------------------- STACK_INIT.C */
void			stack_creator(t_stack **a, char **argv);
t_stack			*get_cheapest(t_stack *stack);
void			prep_for_push(t_stack **s, t_stack *n, char c);
/* --------------------------------------------------------------- FT_SPLIT.C */
char			**ft_split(char *s, char c);
void			free_args(char **argv);
/* ---------------------------------------------------------- A_INITIALIZER.C */
void			anode_initializer(t_stack *a, t_stack *b);
void			update_index(t_stack *stack);
void			set_cheapest(t_stack *stack);
/* ---------------------------------------------------------- B_INITIALIZER.C */
void			bnode_initializer(t_stack *a, t_stack *b);
/* ------------------------------------------------------------ STACK_UTILS.C */
int				stack_size(t_stack *stack);
bool			stack_is_sorted(t_stack *stack);
t_stack			*find_last(t_stack *stack);
t_stack			*find_min(t_stack *stack);
t_stack			*find_max(t_stack *stack);
/* ----------------------------------------------------------------- SORT_3.C */
void			sort_3(t_stack **a);
/* ------------------------------------------------------------ SORT_STACKS.C */
void			sort_turk(t_stack **a, t_stack **b);
/* -------------------------------------------------------------- MOVE_SWAP.C */
void			sa(t_stack **a, bool print);
void			sb(t_stack **b, bool print);
void			ss(t_stack **a, t_stack **b, bool print);
/* ------------------------------------------------------------ MOVE_ROTATE.C */
void			ra(t_stack **a, bool print);
void			rb(t_stack **b, bool print);
void			rr(t_stack **a, t_stack **b, bool print);
/* -------------------------------------------------------- MOVE_REV_ROTATE.C */
void			rra(t_stack **a, bool print);
void			rrb(t_stack **b, bool print);
void			rrr(t_stack **a, t_stack **b, bool print);
void			pa(t_stack **a, t_stack **b, bool print);
void			pb(t_stack **b, t_stack **a, bool print);

#endif
