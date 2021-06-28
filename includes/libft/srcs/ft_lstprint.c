/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:11:28 by claclou           #+#    #+#             */
/*   Updated: 2021/06/28 13:49:44 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

void	ft_lstprint(t_list *lst)
{
	if (lst == NULL)
		printf("la liste est vide\n");
	while (lst != NULL)
	{
		printf("check element : %d\n", (int)lst->content);
		lst = lst->next;
	}
}
