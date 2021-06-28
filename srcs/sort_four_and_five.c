/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_and_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:51:35 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 18:29:50 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_on_stack_b(t_dlist *stack_a, t_dlist *stack_b)
{
	int	min;
	int	max;

	min = check_min(stack_a, stack_a->len);
	max = check_max(stack_a, stack_a->len);
	while (!check_top(stack_a, min))
		put_on_top(stack_a, min);
	command_push(push, 1, stack_a, stack_b, "pb\n");
	if (stack_a->len > 3)
	{
		while (!check_top(stack_a, max))
			put_on_top(stack_a, max);
		command_push(push, 1, stack_a, stack_b, "pb\n");
	}
}

void	case_of_four_and_five(t_dlist *stack_a, t_dlist *stack_b)
{
	put_on_stack_b(stack_a, stack_b);
	case_of_three(stack_a, stack_b);
	if (stack_b->len == 2)
	{
		command_push(push, 1, stack_b, stack_a, "pa\n");
		command(rotate, 1, stack_a, "ra\n");
	}
	command_push(push, 1, stack_b, stack_a, "pa\n");
}
