/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:06:29 by claclou           #+#    #+#             */
/*   Updated: 2021/06/28 13:48:33 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

//gcc main_libft/main_ft_lstlast.c libft/srcs/ft_lstadd_front.c 
//libft/srcs/ft_lstnew.c libft/srcs/ft_lstsize.c libft/srcs/ft_lstlast.c

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
