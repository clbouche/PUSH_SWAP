/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:09:26 by claclou           #+#    #+#             */
/*   Updated: 2021/06/28 18:16:07 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_dlist 	*ft_dlstdelone_front(t_dlist *lst)
{
	t_node *begin;

	begin = lst->begin;
	if (lst == NULL)
		ft_error(ERR_EMPTY_DLIST);
	if (lst->begin == lst->end)
	{
		lst->len -= 1;
		lst = NULL;
		return NULL;
	}
	lst->begin = lst->begin->next;
	lst->begin->prev = NULL;
	ft_dlstdelone(begin);
	lst->len -= 1;
	return (lst);
}
