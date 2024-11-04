/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:27:55 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/04 22:49:23 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	elements_checker(t_data *data, int i, char **tab, int lines)
{
	t_map	*map;
	int		stat;

	map = &data->map;
	if (map->color_f != 1 || map->color_c != 1 || map->news[0] != 1
		|| map->news[1] != 1 || map->news[2] != 1 || map->news[3] != 1)
		return (-5);
	stat = check_news_ptrs(map->north, "NO", map);
	if (stat < 0)
		return (stat);
	stat = check_news_ptrs(map->west, "WE", map);
	if (stat < 0)
		return (stat);
	stat = check_news_ptrs(map->east, "EA", map);
	if (stat < 0)
		return (stat);
	stat = check_news_ptrs(map->south, "SO", map);
	if (stat < 0)
		return (stat);
	stat = f_c_checker(map);
	if (stat < 0)
		return (stat);
	stat = parse_map(data, lines);
	return (stat);
}

void	check_table_v2(t_data *data, char *tab)
{
	if (ft_strnstr(tab, "NO", ft_strlen(tab)))
		1 && (data->map.north = tab, data->map.news[0]++);
	else if (ft_strnstr(tab, "WE", ft_strlen(tab)))
		1 && (data->map.west = tab, data->map.news[2]++);
	else if (ft_strnstr(tab, "EA", ft_strlen(tab)))
		1 && (data->map.east = tab, data->map.news[1]++);
	else if (ft_strnstr(tab, "SO", ft_strlen(tab)))
		1 && (data->map.south = tab, data->map.news[3]++);
	else if (ft_strnstr(tab, "F", ft_strlen(tab)))
		1 && (data->map.fcolor = tab, data->map.color_f++);
	else if (ft_strnstr(tab, "C", ft_strlen(tab)))
		1 && (data->map.ccolor = tab, data->map.color_c++);
}

int	check_table(t_data *data)
{
	int		i;
	char	**tab;
	int		stat;
	int		stat2;
	int		j;

	1 && (tab = data->map.table, i = -1, j = 0);
	inisialize_vars(data);
	while (tab[++i])
	{
		check_table_v2(data, tab[i]);
		stat = map_begins(tab[i], data->map);
		if (stat == 0)
		{
			stat2 = get_map(data, i, &j);
			if (stat2 < 0)
				return (stat2);
			data->rows_n = j;
			break ;
		}
		else if (stat < 0)
			return (stat);
	}
	stat = elements_checker(data, i, tab, j);
	return (stat);
}
