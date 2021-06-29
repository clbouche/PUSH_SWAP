/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:52:42 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/29 13:28:32 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* pa : push a - prend le premier élément au sommet de b 
** et le met sur a. Ne fait
** rien si b est vide.
** pb : push b - prend le premier élément au sommet de a
** et le met sur b. Ne fait
** rien si a est vide. */

void	push(t_dlist *src, t_dlist *dst, char *cmd)
{
	ft_dlstadd_front(dst, src->begin->value, src->begin->index);
	ft_dlstdelone_front(src);
	write(1, cmd, 3);
}
