/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:31:23 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 18:58:36 by clbouche         ###   ########.fr       */
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
	ft_dlstadd_back(stack, node->value, node->index, node->keep);
	ft_dlstdelone_front(stack);
	write(1, cmd, 3);
}

void	rotate_both(t_dlist *stack_a, t_dlist *stack_b)
{
	rotate(stack_a, "rr");
	rotate(stack_b, "\n");
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
	t_node	*old_head;
	t_node	*new_head;
	t_node	*new_end;

	if (stack->len <= 1)
		return ;
	old_head = stack->begin;
	new_end = stack->end->prev;
	new_head = stack->end;
	stack->begin = new_head;
	stack->begin->next = old_head;
	stack->begin->prev = NULL;
	old_head->prev = stack->begin;
	stack->end = new_end;
	stack->end->next = NULL;
	write(1, cmd, 4);
}

/*void	reverse_rotate(t_dlist *stack, char *cmd)
{
	t_node	*prev;
	t_node	*elem;

	if (!stack->begin || !stack->begin->next || !stack)
		return ;
	elem = stack->begin;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = stack->begin;
	stack->begin = elem;
	prev->next = NULL;
}*/

void	reverse_rotate_both(t_dlist *stack_a, t_dlist *stack_b)
{
	reverse_rotate(stack_a, "rrr");
	reverse_rotate(stack_b, "\n");
}
