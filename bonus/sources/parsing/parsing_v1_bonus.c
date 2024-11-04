/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:27:55 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/04 21:47:26 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int fill_lines(int *i, char ***new_map, int lenght, int max)
{
	int	strlen;
	
	while ((*i) < max)
	{
		strlen = 0, (*new_map)[(*i)] = ft_strdup("22222222");
		while (strlen < lenght)
		{
			(*new_map)[(*i)] = ft_strjoin((*new_map)[(*i)], "2");
			if (!(*new_map)[(*i)])
				return (-2);
			strlen++;
		}
		(*i)++;
	}
	return (0);
}

int	_xtra_map(char ***map, int lenght, int lines, t_data *data)
{
	int	i;
	int	len;
	int	k;
	char	**new_map;
	
	1 && (i = 0, new_map = (char **)malloc(sizeof(char *) * (lines + 9)));
	if (!new_map)
		return (-2);
	if (fill_lines(&i, &new_map, lenght, 4) < 0)
		return (ft_free_par(*map), ft_free_par(new_map), -2);
	k = 0;
	while ((*map)[k])
	{
		new_map[i] = ft_strjoin(ft_strdup("22222222"), (*map)[k]);
		if (!new_map[i])
			return (ft_free_par(*map), ft_free_par(new_map), -2);
		i++, k++;
	}
	if (fill_lines(&i, &new_map, lenght, lines + 8) < 0)
		return (ft_free_par(*map), ft_free_par(new_map), -2);
	new_map[i] = NULL;
	1 && (data->clmn_n += 8, data->rows_n += 5);
	return (ft_free_par(*map), data->map.map = new_map, 0);
}

int	last_check(char **map, t_data *data)
{
	int	idx[2];
	int	count;

	idx[0] = 0;
	count = 0;
	while(map[idx[0]])
	{
		idx[1] = 0;
		while (map[idx[0]][idx[1]])
		{
			if (map[idx[0]][idx[1]] == 'N' || map[idx[0]][idx[1]] == 'S'
				|| map[idx[0]][idx[1]] == 'W' || map[idx[0]][idx[1]] == 'E')
			{
				count++;
				angle_init(map[idx[0]][idx[1]], data);
				data->player->x = idx[1] + 8;
				data->player->y = idx[0] + 4;
			}
			idx[1]++;
		}
		idx[0]++;
	}
	if (count != 1)
		return (-15);
	return (_xtra_map(&map, data->clmn_n + 8, data->rows_n, data));
}

int char_checker(char **map, int i, int j)
{
	if (is_map_char(map[i][j]) == 1 && map[i][j] != ' ')
		return (-11);
	else if ((map[i][j] == '0' || is_player(map[i][j]))
		&& check_directions(map, i, j, 1) != 0)
		return (-12);
	else if (map[i][j] == 'D' && check_directions(map, i, j, 0) != 0)
		return (-16);
	return (0);
}

int parse_map(t_data *data, int lines)
{
	int		i;
	int		j;
	char	**map;
	int		stat;

	1 && (map = data->map.map, i = 0);
	while (i < lines)
	{
		j = 0;
		if ((i == 0 || i == lines - 1) && (first_last_line(map[i]) == 0))
			return (-13);
		else if (i > 0 && i < lines - 1)
		{	while (map[i][j])
			{
				stat = char_checker(map, i, j);
				if (stat < 0)
					return (stat);
				j++;
			}
		}
		i++;
	}
	return (spacetotwo(map), last_check(map, data));
}

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

int map_begins(char *tab, t_map map)
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
	if ((tab[i] == '1' || tab[i] == '0') && 
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
