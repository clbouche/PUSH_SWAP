/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_target_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:32:23 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 19:46:26 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_false_on_stack_b(t_dlist *stack_a, t_dlist *stack_b, int size_sorted_part)
{
	int 	future_size_stack_b;
	t_node	*temp;

	future_size_stack_b = stack_a->len - size_sorted_part;
	while (future_size_stack_b > 0)
	{
		temp = stack_a->begin;
		if (temp->keep == 0)
		{
			command_push(push, 1, stack_a, stack_b, "pb\n");
			future_size_stack_b--;
		}
		else
			command(rotate, 1, stack_a, "ra\n");
	}
}

void	put_index_on_stack(t_dlist *stack_a, t_dlist *cpy)
{
	t_node	*temp_stack;
	t_node	*temp_cpy;

	temp_stack = stack_a->begin;
	temp_cpy = cpy->begin;
	while (temp_stack != NULL)
	{
		temp_cpy = cpy->begin;
		while (temp_cpy != NULL)
		{
			if (temp_stack->value == temp_cpy->value)
			{
				temp_stack->index = temp_cpy->index;
			}
			temp_cpy =  temp_cpy->next;
		}
		temp_stack = temp_stack->next;
	}
}

void	put_index_to_copy(t_dlist *cpy)
{
	t_node	*temp;
	int		index;

	temp = cpy->begin;
	index = 0;
	while (temp != NULL)
	{
		temp->index = index;
		temp = temp->next;
		index++;
	}
}

void	swap_elements(t_node **element, t_node **temp, int *value)
{
	*value = (*element)->value;
	(*element)->value = (*temp)->value;
	(*temp)->value = (*value);
}

t_dlist	*bubble_sort_cpy(t_dlist *cpy)
{
	t_node	*element;
	t_node	*temp;
	int		value;

	element = cpy->begin;
	temp = cpy->begin;
	value = cpy->begin->value;
	while (element)
	{
		while (temp)
		{
			if (element->value > temp->value)
				swap_elements(&element, &temp, &value);
			temp = temp->next;
		}
		element = element->next;
		temp = element;
	}
	return (cpy);
}

t_dlist	*do_a_copy(t_dlist *stack_a)
{
	t_dlist	*cpy;
	t_node	*read;

	cpy = init_stack(cpy);
	read = stack_a->begin;
	cpy->begin = NULL;
	while (read != NULL)
	{
		ft_dlstadd_back(cpy, read->value, read->index);
		read = read->next;
	}
	return (cpy);
}
