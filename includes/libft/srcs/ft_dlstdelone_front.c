/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:09:26 by claclou           #+#    #+#             */
/*   Updated: 2021/06/29 16:00:00 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_dlstdelone_front(t_dlist *lst)
{
	t_node	*begin;

	begin = lst->begin;
	if (lst == NULL)
		ft_error(ERR_EMPTY_DLIST);
	if (lst->begin == lst->end)
	{
		lst->len -= 1;
		lst->begin = NULL;
		lst = NULL;
		return ;
	}
	lst->begin = lst->begin->next;
	lst->begin->prev = NULL;
	ft_dlstdelone(begin);
	lst->len -= 1;
}
