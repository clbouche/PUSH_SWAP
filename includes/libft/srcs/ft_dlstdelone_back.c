/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:08:40 by claclou           #+#    #+#             */
/*   Updated: 2021/06/29 14:49:45 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_dlstdelone_back(t_dlist *lst)
{
	t_node	*end;

	if (lst == NULL)
		ft_error(ERR_EMPTY_DLIST);
	if (lst->begin == lst->end)
	{
		lst = NULL;
		free(lst);
		return ;
	}
	end = lst->end;
	lst->end = lst->end->prev;
	lst->end->next = NULL;
	ft_dlstdelone(end);
	lst->len -= 1;
}
