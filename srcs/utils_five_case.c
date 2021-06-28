/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_five_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:56:01 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 18:23:06 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	smallest_on_top(t_dlist	*stack)
{
	int		min;
	t_node	*temp;

	temp = stack->begin;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	check_top(t_dlist *stack_a, int x)
{
	if (stack_a->begin->value == x)
		return (SUCCESS);
	return (FAILURE);
}

int	top_or_bottom(t_dlist *stack_a, int value)
{
	int		i;
	t_node	*top;
	t_node	*bottom;

	i = -1;
	top = stack_a->begin;
	bottom = stack_a->end;
	while (i++ <= stack_a->len / 2 && top->value != value)
	{
		top = top->next;
		if (top->value == value)
			return (1);
	}
	i = stack_a->len + 1;
	while (i-- > stack_a->len / 2 && bottom->value != value)
	{
		top = top->next;
		if (top->value == value)
			return (2);
	}
	return (0);
}

void	put_on_top(t_dlist *stack_a, int value)
{
	if (!stack_a)
		return ;
	if (check_top(stack_a, value))
		return ;
	if (top_or_bottom(stack_a, value) == 1)
	{
		while (!check_top(stack_a, value))
			command(rotate, 1, stack_a, "ra\n");
	}
	else
	{
		while (!check_top(stack_a, value))
			command(reverse_rotate, 1, stack_a, "rra\n");
	}
}
