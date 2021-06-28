/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:37:29 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 15:29:50 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s == d)
		return (dst);
	if (s > d)
	{
		while (len)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}
	}	
	else if (s < d)
		while (len--)
			*(d + len) = *(s + len);
	return (dst);
}
