/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:40:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 19:35:25 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sequence_size(t_node *begin_sorted_part, t_dlist *stack, bool define)
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
			break;
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

int		check_true(t_dlist *stack)
{
	t_node	*begin_sorted_part;
	int 	size_sorted_part;

	begin_sorted_part = sorted_part(stack);
	size_sorted_part  = sequence_size(begin_sorted_part, stack, true); 
	return(size_sorted_part);
}