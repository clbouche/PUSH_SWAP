/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:08:06 by claclou           #+#    #+#             */
/*   Updated: 2021/06/28 18:54:23 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_dlstdelone(t_node *node)
{
	node->next = NULL;
	node->prev = NULL;
	node->value = 0;
	node->index = 0;
	node->keep = 0;
	free(node);
}
