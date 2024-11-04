/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:21:07 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/04 21:46:04 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_lines(char **tab, int i)
{
	int	j;

	j = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) == 0)
			break ;
		j++;
		i++;
	}
	return (j);
}

int	largest_line(char **map)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

void	spacetotwo(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '2';
			j++;
		}
		i++;
	}
}

int is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'W' || c == 'E' || c == 'S' || c == 'N')
		return (0);
	return (1);
}

int check_directions(char **map, int i, int j)
{
	if (is_map_char(map[i - 1][j])
		|| is_map_char(map[i + 1][j])
		|| is_map_char(map[i][j - 1])
		|| is_map_char(map[i][j + 1]))
		return (1);
	return (0);
}
