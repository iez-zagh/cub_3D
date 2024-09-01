/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:06:46 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/18 08:35:35 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_count(const char *str, char c)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			word++;
		}
		else if (str[i] == c)
		{
			j = 0;
		}
		i++;
	}
	return (word);
}

void	ft_int(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

char	**ft_free(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		p[i] = 0;
		i++;
	}
	free(p);
	p = 0;
	return (NULL);
}

char	**t3mar(char const *str, char **p, char c, int num_words)
{
	int	douz;
	int	len;
	int	j;

	ft_int(&douz, &len, &j);
	while (j < num_words)
	{
		if (*str != c && douz == 0)
		{
			douz = 1;
			len = 0;
		}
		else if ((*str == c || *str == '\0') && douz == 1)
		{
			p[j] = ft_substr(str - len, 0, len);
			if (!p[j])
				return (ft_free(p, j));
			douz = 0;
			j++;
		}
		len++;
		str++;
	}
	return (&p[j]);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	**tmp;
	int		kalimat;

	if (!s)
		return (NULL);
	kalimat = count_count(s, c);
	p = malloc((kalimat + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	tmp = t3mar(s, p, c, kalimat);
	if (tmp == NULL)
		return (NULL);
	*tmp = 0;
	return (p);
}
