/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:30:41 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/01 15:44:51 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_one_line(char *str, int j)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str)
		return (NULL);
	str2 = malloc(j + 2);
	if (!str2)
		return (NULL);
	while (i <= j)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*check(char **buffer, int j)
{
	char	*str2;
	char	*tmp;

	str2 = ft_one_line(*buffer, j);
	tmp = *buffer;
	*buffer = ft_substr2(*buffer, j + 1, ft_strlen2(*buffer) - j);
	if (!*buffer)
		return (free(tmp), NULL);
	return (free(tmp), str2);
}

char	*end_or_inv(int u, char **buffer)
{
	char	*line;

	if (u == 0)
	{
		if (ft_strlen2(*buffer) == 0)
		{
			free(*buffer);
			*buffer = NULL;
		}
		line = ft_one_line(*buffer, (ft_strlen2(*buffer) - 1));
		free (*buffer);
		*buffer = NULL;
		return (line);
	}
	else if (u == -1)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_read(int fd, char **buffer, char *str)
{
	int			u;
	int			j;

	j = 0;
	if (read(fd, str, 0) == -1)
	{
		free (*buffer);
		*buffer = NULL;
		return (free(str), NULL);
	}
	while (1)
	{
		j = ft_strchr2(*buffer, '\n');
		if (j != -1)
			return (free (str), check(buffer, j));
		u = read(fd, str, BUFFER_SIZE);
		if (u == -1 || u == 0)
			return (free(str), end_or_inv(u, buffer));
		str[u] = '\0';
		*buffer = ft_strjoin2(*buffer, str);
	}
	free (*buffer);
	*buffer = NULL;
	return (free(str), NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;

	if (fd >= 0 && BUFFER_SIZE > 0 && fd <= OPEN_MAX
		&& BUFFER_SIZE <= INT_MAX)
	{
		str = malloc((size_t)BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		return (ft_read(fd, &buffer, str));
	}
	free (buffer);
	buffer = NULL;
	return (NULL);
}
