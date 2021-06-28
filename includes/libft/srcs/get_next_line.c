/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:12 by clbouche          #+#    #+#             */
/*   Updated: 2021/06/28 14:40:53 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_savetxt(char *s)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	save = malloc(sizeof(char) * (ft_strlen(s)) - i + 1);
	if (!save)
		return (0);
	j = -1;
	i++;
	while (s[i])
		save[j++] = s[i++];
	free(s);
	save[j] = '\0';
	return (save);
}

int	get_next_line(int fd, char **line)
{
	int			op;
	char		*buff;
	static char	*str;

	op = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	while (op != 0 && ft_check(str) != -1)
	{
		op = read(fd, buff, BUFFER_SIZE);
		if (op == -1)
			return (-1);
		buff[op] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	*line = ft_form_line(str);
	str = ft_savetxt(str);
	if (op == 0)
		return (0);
	return (1);
}
