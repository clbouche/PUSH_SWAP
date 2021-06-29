/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:26:28 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/29 15:12:54 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	optimize_mins(t_dlist *stack_a, t_dlist *stack_b, t_params *actions)
{
	while (actions->min_b > 0 && actions->min_a > 0)
	{
		rotate_both(stack_a, stack_b, "rr\n");
		actions->min_b--;
		actions->min_a--;
	}
	while (actions->min_a < 0 && actions->min_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b, "rrr\n");
		actions->min_b++;
		actions->min_a++;
	}
}

void	do_actions(t_dlist *stack_a, t_dlist *stack_b, t_params *actions)
{
	if ((actions->min_b > 0 && actions->min_a > 0)
		|| (actions->min_b < 0 && actions->min_a < 0))
		optimize_mins(stack_a, stack_b, actions);
	while (actions->min_b > 0)
	{
		command(rotate, 1, stack_b, "rb\n");
		(actions->min_b)--;
	}
	while (actions->min_b < 0)
	{
		command(reverse_rotate, 1, stack_b, "rrb\n");
		actions->min_b++;
	}
	while (actions->min_a > 0)
	{
		command(rotate, 1, stack_a, "ra\n");
		(actions->min_a)--;
	}
	while (actions->min_a < 0)
	{
		command(reverse_rotate, 1, stack_a, "rra\n");
		actions->min_a++;
	}
	push(stack_b, stack_a, "pa\n");
}

int	return_absolute_value(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_params	init_params(t_params actions, t_dlist *stack_b)
{
	actions.elem = stack_b->begin;
	actions.best = NULL;
	actions.count_actions_stack_a = 0;
	actions.count_actions_stack_b = 0;
	actions.min_move = 0xFFFFFFF;
	actions.total_moves = 0;
	actions.min_a = 0;
	actions.min_b = 0;
	actions.count_for_b = 0;
	return (actions);
}

t_dlist	*case_of_more(t_dlist *stack_a, t_dlist *stack_b)
{
	t_dlist		*cpy;
	t_params	actions;
	int			size_sorted_part;

	actions = init_params(actions, stack_b);
	cpy = do_a_copy(stack_a);
	bubble_sort_cpy(cpy);
	put_index_to_copy(cpy);
	put_index_on_stack(stack_a, cpy);
	free(cpy);
	size_sorted_part = check_true(stack_a);
	put_false_on_stack_b(stack_a, stack_b, size_sorted_part);
	while (stack_b->begin != NULL)
	{
		actions.elem = stack_b->begin;
		calculate_best_actions(stack_a, stack_b, &actions);
		do_actions(stack_a, stack_b, &actions);
	}
	if (!(check_top(stack_a, smallest_on_top(stack_a))))
		put_on_top(stack_a, smallest_on_top(stack_a));
	return (stack_a);
}
