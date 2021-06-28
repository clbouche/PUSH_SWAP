/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:08:40 by claclou           #+#    #+#             */
/*   Updated: 2021/06/28 18:05:19 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_dlist	*ft_dlstdelone_back(t_dlist *lst)
{
	t_node	*end;

	if (lst == NULL)
		ft_error(ERR_EMPTY_DLIST);
	if (lst->begin == lst->end)
	{
		lst = NULL;
		free(lst);
		return (NULL);
	}
	end = lst->end;
	lst->end = lst->end->prev;
	lst->end->next = NULL;
	ft_dlstdelone(end);
	lst->len -= 1;
	return (lst);
}
