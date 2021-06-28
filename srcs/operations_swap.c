/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:23:16 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 15:24:43 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. 
** Ne fait rien s’il n’y en a qu’un ou aucun.
** sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. 
** Ne fait rien s’il n’y en a qu’un ou aucun.
** ss : sa et sb en même temps.*/

void	swap(t_dlist *stack, char *cmd)
{
	int		first;
	int		second;
	int		temp;

	first = stack->begin->value;
	second = stack->begin->next->value;
	temp = stack->begin->value;
	stack->begin->value = stack->begin->next->value;
	stack->begin->next->value = temp;
	write(1, cmd, 3);
}

void	swap_both(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_b->len >= 2)
	{
		swap(stack_a, "ss");
		swap(stack_b, "\n");
	}
}
