/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:05:46 by claclou           #+#    #+#             */
/*   Updated: 2021/06/28 13:42:41 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* WARNING ------- pas utiliser le vrai printf*/

void	ft_error(char *error)
{
	printf("%s%s\n", ERR, error);
	exit(EXIT_FAILURE);
}
