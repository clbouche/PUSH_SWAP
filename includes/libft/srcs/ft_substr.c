/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:12:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 13:54:41 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (*s == '\0')
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (len && s[start])
	{
		new[i] = s[start];
		len--;
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
