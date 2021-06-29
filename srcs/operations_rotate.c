/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:31:23 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/29 15:44:08 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ra : rotate a - décale d’une position vers le haut 
** tous les élements de la pile a.
** Le premier élément devient le dernier.
** rb : rotate b - décale d’une position vers le haut 
** tous les élements de la pile b.
** Le premier élément devient le dernier.
** rr : ra et rb en même temps. */

void	rotate(t_dlist *stack, char *cmd)
{
	t_node	*node;

	node = stack->begin;
	ft_dlstadd_back(stack, node->value, node->index);
	ft_dlstdelone_front(stack);
	write(1, cmd, 3);
}

void	rotate_both(t_dlist *stack_a, t_dlist *stack_b, char *cmd)
{
	t_node	*node_stack_b;
	t_node	*node_stack_a;

	node_stack_b = stack_b->begin;
	node_stack_a = stack_a->begin;
	ft_dlstadd_back(stack_b, node_stack_b->value, node_stack_b->index);
	ft_dlstdelone_front(stack_b);
	ft_dlstadd_back(stack_a, node_stack_a->value, node_stack_a->index);
	ft_dlstdelone_front(stack_a);
	write(1, cmd, 3);
}

/* rra : reverse rotate a - décale d’une position 
** vers le bas tous les élements de
** la pile a. Le dernier élément devient le premier.
** rrb : reverse rotate b - décale d’une position 
** vers le bas tous les élements de
** la pile b. Le dernier élément devient le premier.
** rrr : rra et rrb en même temps. */

void	reverse_rotate(t_dlist *stack, char *cmd)
{
	t_node	*node;

	node = stack->end;
	ft_dlstadd_front(stack, node->value, node->index);
	ft_dlstdelone_back(stack);
	write(1, cmd, 4);
}

void	reverse_rotate_both(t_dlist *stack_a, t_dlist *stack_b, char *cmd)
{
	t_node	*node_stack_b;
	t_node	*node_stack_a;

	node_stack_b = stack_b->end;
	node_stack_a = stack_a->end;
	ft_dlstadd_front(stack_b, node_stack_b->value, node_stack_b->index);
	ft_dlstdelone_back(stack_b);
	ft_dlstadd_front(stack_a, node_stack_a->value, node_stack_a->index);
	ft_dlstdelone_back(stack_a);
	write(1, cmd, 4);
}
