/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:41:38 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 18:37:34 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_swap(t_dlist *stack_a, t_dlist *stack_b, int ac)
{
	int	numbers;

	numbers = ac - 1;
	if (!stack_a)
		ft_error(ERR_EMPTY);
	if (check_order(stack_a))
		return ;
	if (numbers <= 5)
	{
		if (stack_a->len == 2)
			case_of_two(stack_a, stack_b);
		if (stack_a->len == 3)
			case_of_three(stack_a, stack_b);
		else
			case_of_four_and_five(stack_a, stack_b);
	}
	else
		case_of_more(stack_a, stack_b);
}

t_dlist	*init_stack(t_dlist *stack)
{
	stack = malloc(sizeof(t_dlist));
	stack->begin = NULL;
	stack->end = NULL;
	stack->len = 0;
	return (stack);
}

int	main(int ac, char **av)
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;

	if (ac < 2)
		ft_error(ERR_ARG);
	stack_a = init_stack(stack_a);
	check_input(ac, av, stack_a);
	stack_b = init_stack(stack_b);
	ft_push_swap(stack_a, stack_b, ac);
	printf("voici la liste a :\n");
	print_dlist(stack_a);
	printf("_________\n");
	if (stack_b)
	{
		printf("voici la liste b :\n");
		print_dlist(stack_b);
		printf("_________\n");
	}
	free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}
