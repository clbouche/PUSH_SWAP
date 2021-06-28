/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:22:41 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 14:35:18 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		len;
	int		start;

	len = ft_strlen(s1);
	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while ((ft_chr(s1[start], set)))
		start++;
	if (start == len)
		return (ft_substr(s1, 0, 0));
	while ((ft_chr(s1[len - 1], set)))
		len--;
	if (len == 0)
		return (ft_substr(s1, 0, 0));
	new = ft_substr(s1, start, len - start);
	if (!new)
		return (0);
	return (new);
}
