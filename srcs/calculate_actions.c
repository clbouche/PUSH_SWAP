/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:44:13 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/30 10:54:31 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	optimized_actions_calculation(int count_actions_stack_a,
		int count_actions_stack_b)
{
	if (count_actions_stack_a > 0 && count_actions_stack_b > 0)
		return (return_absolute_value(count_actions_stack_a)
			+ return_absolute_value(count_actions_stack_b)
			- compare_min(count_actions_stack_a, count_actions_stack_b));
	else if (count_actions_stack_a < 0 && count_actions_stack_b < 0)
		return (return_absolute_value(count_actions_stack_a)
			+ return_absolute_value(count_actions_stack_b)
			+ compare_max(count_actions_stack_a, count_actions_stack_b));
	else
		return (return_absolute_value(count_actions_stack_a)
			+ (return_absolute_value(count_actions_stack_b)));
	return (SUCCESS);
}

void	init_params_actions(int *i, int *position, bool *end)
{
	*i = 1;
	*position = 0;
	*end = false;
}

int	calculate_actions_for_node(t_dlist *stack_a, int index,
		t_node *temp, t_node *prev)
{
	int		i;
	int		position;
	bool	end;

	init_params_actions(&i, &position, &end);
	while (prev && !end)
	{
		if (temp == NULL)
		{
			temp = stack_a->begin;
			end = true;
		}
		if ((index > prev->index && index < temp->index)
			|| (prev->index > temp->index && (index < temp->index
					|| index > prev->index)))
			position = i;
		i++;
		prev = temp;
		temp = temp->next;
	}
	if (position > stack_a->len / 2)
		position -= stack_a->len;
	return (position);
}

void	recup_move(t_params *actions)
{
	actions->min_move = actions->total_moves;
	actions->best = actions->elem;
	actions->min_a = actions->count_actions_stack_a;
	actions->min_b = actions->count_actions_stack_b;
}

t_node	*calculate_best_actions(t_dlist *stack_a, t_dlist *stack_b,
			t_params *actions)
{
	t_node	*temp;
	t_node	*prev;

	actions->count_for_b = 0;
	actions->min_move = INT_MAX;
	while (actions->elem)
	{
		temp = stack_a->begin->next;
		prev = stack_a->begin;
		actions->count_actions_stack_a = calculate_actions_for_node(stack_a,
				actions->elem->index, temp, prev);
		actions->count_actions_stack_b = actions->count_for_b;
		if (actions->count_for_b > stack_b->len / 2)
			actions->count_actions_stack_b -= stack_b->len;
		actions->total_moves = optimized_actions_calculation
			(actions->count_actions_stack_a, actions->count_actions_stack_b);
		if (actions->total_moves < actions->min_move)
			recup_move(actions);
		actions->elem = actions->elem->next;
		actions->count_for_b ++;
	}
	return (actions->best);
}
