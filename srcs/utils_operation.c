/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:25:57 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 19:52:02 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command_both(void f(t_dlist *, t_dlist *), int iter, t_dlist *stack_a, t_dlist *stack_b)
{
	int i;

	i = 0;
	while (i < iter)
	{
		f(stack_a, stack_b);
		i++;
	}
}

void	command_push(void f(t_dlist *, t_dlist *, char *),
		int iter, t_dlist *stack_a, t_dlist *stack_b, char *cmd)
{
	int	i;

	i = 0;
	while (i < iter)
	{
		f(stack_a, stack_b, cmd);
		i++;
	}
}

void	command(void f(t_dlist *, char *), int iter, t_dlist *stack, char *cmd)
{
	int	i;

	i = 0;
	while (i < iter)
	{
		f(stack, cmd);
		i++;
	}
}
