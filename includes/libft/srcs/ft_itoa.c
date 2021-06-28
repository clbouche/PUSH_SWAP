/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:04:44 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 13:46:32 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	len;
	int		sign;
	long	nb;

	nb = (long)n;
	len = ft_len(n);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	nb = n < 0 ? n * -1 : n * 1;
	sign = n < 0 ? 1 : 0;
	while (len > sign)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	str[ft_len(n)] = '\0';
	return (str);
}
