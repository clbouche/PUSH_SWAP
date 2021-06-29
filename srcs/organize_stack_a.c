/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:40:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/29 15:48:30 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_false_on_stack_b(t_dlist *stack_a, t_dlist *stack_b,
			int size_sorted_part)
{
	int		future_size_stack_b;
	t_node	*temp;

	future_size_stack_b = stack_a->len - size_sorted_part;
	while (future_size_stack_b > 0)
	{
		temp = stack_a->begin;
		if (temp->keep == false)
		{
			command_push(push, 1, stack_a, stack_b, "pb\n");
			future_size_stack_b--;
		}
		else
			command(rotate, 1, stack_a, "ra\n");
	}
}

int	sequence_size(t_node *begin_sorted_part, t_dlist *stack, bool define)
{
	t_node	*temp;
	int		size_sorted_part;
	int		index_sorted_part;

	temp = begin_sorted_part;
	size_sorted_part = 0;
	index_sorted_part = 0;
	while (temp != NULL)
	{
		if (temp->index >= index_sorted_part)
		{
			if (define)
				temp->keep = true;
			index_sorted_part = temp->index;
			size_sorted_part += 1;
		}
		else if (define)
			temp->keep = false;
		temp = temp->next;
		if (temp == NULL)
			temp = stack->begin;
		if (temp == begin_sorted_part)
			break ;
	}
	return (size_sorted_part);
}

t_node	*sorted_part(t_dlist *stack)
{
	t_node	*temp;
	t_node	*begin_sorted_part;
	int		size_sorted_part;
	int		compare_size_sequence;

	temp = stack->begin;
	compare_size_sequence = 0;
	while (temp != NULL)
	{
		size_sorted_part = sequence_size(temp, stack, false);
		if (size_sorted_part > compare_size_sequence)
		{
			compare_size_sequence = size_sorted_part;
			begin_sorted_part = temp;
		}
		temp = temp->next;
	}
	return (begin_sorted_part);
}

int	check_true(t_dlist *stack)
{
	t_node	*begin_sorted_part;
	int		size_sorted_part;

	begin_sorted_part = sorted_part(stack);
	size_sorted_part = sequence_size(begin_sorted_part, stack, true);
	return (size_sorted_part);
}
