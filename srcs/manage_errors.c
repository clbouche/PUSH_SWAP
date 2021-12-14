/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:39:33 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/30 12:38:59 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_dlist *stack)
{
	t_node	*element;

	element = stack->begin;
	while (element)
	{
		stack->begin = stack->begin->next;
		free(element);
		element = NULL;
		element = stack->begin;
	}
	free(stack);
	stack = NULL;
}

void	ft_error_pswap(t_dlist *stack)
{
	write(2, "Error\n", 6);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

void	ft_success_pswap(t_dlist *stack)
{
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
