/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:27:55 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/18 20:57:07 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	elements_checker(t_data *data, int lines, t_map	*map)
{
	int		stat;

	if (map->color_f != 1 || map->color_c != 1 || map->news[0] != 1
		|| map->news[1] != 1 || map->news[2] != 1 || map->news[3] != 1)
		return (-5);
	stat = check_news_ptrs(map->north, "NO", map);
	if (stat < 0)
		return (stat);
	stat = check_news_ptrs(map->west, "WE", map);
	if (stat < 0)
		return (free_leaks(map, 1), stat);
	stat = check_news_ptrs(map->east, "EA", map);
	if (stat < 0)
		return (free_leaks(map, 2), stat);
	stat = check_news_ptrs(map->south, "SO", map);
	if (stat < 0)
		return (free_leaks(map, 3), stat);
	stat = f_c_checker(map);
	if (stat < 0)
		return (free_leaks(map, 4), stat);
	stat = parse_map(data, lines);
	if (stat < 0)
		return (free_leaks(map, 4), stat);
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
	int		stt;
	int		stat2;

	1 && (tab = data->map.table, i = -1);
	inisialize_vars(data);
	while (tab[++i])
	{
		check_table_v2(data, tab[i]);
		stt = map_begins(tab[i], data->map);
		if (stt == 0)
		{
			stat2 = get_map(data, i, &data->rows_n);
			if (stat2 < 0)
				return (stat2);
			break ;
		}
		else if (stt < 0)
			return (stt);
	}
	stt = elements_checker(data, data->rows_n, &data->map);
	if (stt < 0)
		return (ft_free_par(data->map.map), stt);
	return (stt);
}
