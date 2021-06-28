/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:32:43 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 17:03:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	check_min(t_dlist *stack, int len)
{
	t_node	*node;
	int		min_value;

	node = stack->begin;
	min_value = node->value;
	while (node)
	{
		min_value = compare_min(node->value, min_value);
		node = node->next;
	}
	return (min_value);
}

int	compare_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	check_max(t_dlist *stack, int len)
{
	t_node	*node;
	int		max_value;

	node = stack->begin;
	max_value = node->value;
	while (node)
	{
		max_value = compare_max(node->value, max_value);
		node = node->next;
	}
	return (max_value);
}
