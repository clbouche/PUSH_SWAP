/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:26:28 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 19:52:53 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//FONCTION INTERDITE!!!!
void	print_index(t_dlist *stack_a)
{
	t_node	*temp;

	temp = stack_a->begin;
	while (temp != NULL)
	{
		printf("check index stack a  : %i\n", temp->index);
		temp = temp->next;
	}
}
//FONCTION INTERDIIIIIITE!!!!

//FONCTION INTERDIIIIITE
void	print_keep(t_dlist *stack_a)
{
	t_node	*temp;

	temp = stack_a->begin;
	while (temp != NULL)
	{
		printf("check keep stack a : %i\n", temp->keep);
		temp = temp->next;
	}
}
//FONCTION INTERDIIIIITE

void	optimize_mins(t_dlist *stack_a, t_dlist *stack_b, t_params *actions)
{
	while (actions->min_b > 0 && actions->min_a > 0)
	{
		command_both(rotate_both, 1, stack_a, stack_b);
		actions->min_b--;
		actions->min_a--;
	}
	while (actions->min_a < 0 && actions->min_b < 0)
	{
		command_both(reverse_rotate_both, 1, stack_a, stack_b);
		actions->min_b++;
		actions->min_a++;
	}
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
	print_dlist(cpy);
	bubble_sort_cpy(cpy);
	printf("voici la copie apres bubble sort\n");
	print_dlist(cpy);
	put_index_to_copy(cpy);
	put_index_on_stack(stack_a, cpy);
	free(cpy);
	size_sorted_part = check_true(stack_a);
	printf("check size sorted part : %i\n", size_sorted_part);
	printf("before put false on stack b\n");
	printf("keep stack a________________:\n");
	print_keep(stack_a);
	printf("keep stack b________________:\n");
	print_keep(stack_b);
	put_false_on_stack_b(stack_a, stack_b, size_sorted_part);
	/*while (stack_b->len > 0)
	{
		actions.elem = stack_b->begin;
		calculate_best_actions(stack_a, stack_b, &actions);
		do_actions(stack_a, stack_b, &actions);
	}
	if (!(check_top(stack_a, smallest_on_top(stack_a))))
		put_on_top(stack_a, smallest_on_top(stack_a));*/
	return (stack_a);
}
