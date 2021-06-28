/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:19:36 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 16:49:16 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_of_two(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_a->begin->value > stack_a->end->value)
		command(swap, 1, stack_a, "sa\n");
	else
		return ;
}

void	case_of_one_first(t_dlist *stack_a, t_dlist *stack_b)
{
	if (check_max(stack_a, stack_a->len)
		== stack_a->begin->next->value)
	{
		command(swap, 1, stack_a, "sa\n");
		command(rotate, 1, stack_a, "ra\n");
	}
}

void	case_of_two_first(t_dlist *stack_a, t_dlist *stack_b)
{
	if (check_min(stack_a, stack_a->len)
		== stack_a->begin->next->value)
		command(swap, 1, stack_a, "sa\n");
	else
		command(reverse_rotate, 1, stack_a, "rra\n");
}

void	case_of_three_first(t_dlist *stack_a, t_dlist *stack_b)
{
	if (check_min(stack_a, stack_a->len)
		== stack_a->begin->next->value)
		command(rotate, 1, stack_a, "ra\n");
	else
	{
		command(swap, 1, stack_a, "sa\n");
		command(reverse_rotate, 1, stack_a, "rra\n");
	}
}

void	case_of_three(t_dlist *stack_a, t_dlist *stack_b)
{
	if (check_min(stack_a, stack_a->len) == stack_a->begin->value)
		case_of_one_first(stack_a, stack_b);
	else if (check_min(stack_a, stack_a->len)
		!= stack_a->begin->value
		&& check_max(stack_a, stack_a->len)
		!= stack_a->begin->value)
		case_of_two_first(stack_a, stack_b);
	else if (check_max(stack_a, stack_a->len)
		== stack_a->begin->value)
		case_of_three_first(stack_a, stack_b);
}
