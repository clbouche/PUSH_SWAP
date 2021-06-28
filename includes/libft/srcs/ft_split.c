/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:28:16 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 13:51:52 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] != c && s[i] == c) || (s[i + 1] == '\0' && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static void	ft_form_tab(char **tab, const char *s, char c)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			tab[count] = (char *)malloc(sizeof(char *) * (len + 1));
			tab[count] = ft_substr(s, i, len);
			i = i + len;
			count++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	len = ft_words_count(s, c);
	tab = (char **)malloc(sizeof(char **) * (len + 1));
	if (!tab)
		return (0);
	tab[len] = 0;
	ft_form_tab(tab, s, c);
	return (tab);
}
