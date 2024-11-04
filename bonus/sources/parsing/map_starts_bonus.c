/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_starts_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:59:31 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/04 23:06:21 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	map_begins(char *tab, t_map map)
{
	int	i;

	i = 0;
	while (ft_isspace(tab[i]))
		i++;
	if (is_map_char(tab[i]) != 0 && tab[i] != '\0'
		&& tab[i] != 'F' && tab[i] != 'C')
		return (-10);
	if ((is_map_char(tab[i]) == 0 || tab[i] == 'F' || tab[i] == 'C')
		&& sec_char(tab, i) < 0)
		return (-10);
	if ((tab[i] == '1' || tab[i] == '0') && \
		(map.color_f != 1 || map.color_c != 1
			|| map.news[0] != 1 || map.news[1] != 1 || map.news[2] != 1
			|| map.news[3] != 1))
		return (-10);
	else if (tab[i] == '1' || tab[i] == '0')
		return (0);
	return (1);
}

int	fill_map_spaces(char ***map, t_data *data)
{
	int	len;
	int	strlen;
	int	i;

	1 && (i = 0, len = largest_line(*map));
	data->clmn_n = len;
	while ((*map)[i])
	{
		strlen = ft_strlen((*map)[i]);
		while (strlen < len + 8)
		{
			(*map)[i] = ft_strjoin((*map)[i], " ");
			if (!(*map)[i])
				return (-2);
			strlen = ft_strlen((*map)[i]);
		}
		i++;
	}
	return (0);
}

int	get_map(t_data *data, int i, int *j)
{
	char	**tab;
	char	**map;
	int		stat;

	1 && (tab = data->map.table, *j = map_lines(tab, i));
	map = (char **)malloc(sizeof(char *) * ((*j) + 1));
	if (!map)
		return (-2);
	(*j) = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) == 0)
			break ;
		map[(*j)] = ft_strdup(tab[i]);
		if (!map[(*j)])
			return (-2);
		1 && ((*j)++, i++);
	}
	map[(*j)] = NULL;
	if (tab[i])
		return (ft_free_par(map), -10);
	stat = fill_map_spaces(&map, data);
	if (stat < 0)
		return (ft_free_par(map), stat);
	return (data->map.map = map, 0);
}
