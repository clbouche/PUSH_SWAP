/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:48:15 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 18:58:30 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_order(t_dlist *stack_a)
{
	t_node	*node;
	int		i;

	node = stack_a->begin;
	i = 0;
	while (node != stack_a->end)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	check_if_double(t_dlist *stack_a, int value)
{
	t_node	*node;

	node = stack_a->begin;
	if (stack_a->len == 0)
		ft_error(ERR_EMPTY);
	if (stack_a->len == 1)
		return (0);
	while (node != stack_a->end)
	{
		if (value == node->value)
			ft_error(ERR_DOUBLE);
		node = node->next;
	}
	return (SUCCESS);
}

t_dlist	*check_if_integer(const char *arg, t_dlist *stack_a)
{
	double	long_number;
	int		number;
	int		i;

	i = 0 ;
	if (ft_isdigit(arg[i]) == 1)
		i++;
	else
		ft_error(ERR_NUMBER);
	long_number = atof(arg); //INTERDIIIIIT (faire fonction pr libft)
	if (long_number < INT_MAX && long_number > INT_MIN)
	{
		number = long_number;
		ft_dlstadd_back(stack_a, number, 0, 0);
	}
	else
		ft_error(ERR_LIMIT);
	return (stack_a);
}

int	check_input(int ac, char **av, t_dlist *stack_a)
{
	int	i;
	int	number;
	int	long_number;

	i = 1;
	if (ft_strstr(av[0], "./push_swap"))
	{
		while (i < ac)
		{
			stack_a = check_if_integer(av[i], stack_a);
			check_if_double(stack_a, ft_atoi(av[i]));
			i++;
		}
	}
	else
		ft_error(ERR_EXEC);
	return (SUCCESS);
}
