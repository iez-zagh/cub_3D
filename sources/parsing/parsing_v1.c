/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:27:55 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/10/30 22:38:07 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'W' || c == 'E' || c == 'S' || c == 'N')
		return (0);
	return (1);
}

int check_directions(char **map, int i, int j)
{
	if (is_map_char(map[i - 1][j]) == 1
		&& is_map_char(map[i + 1][j] == 1
		&& is_map_char(map[i][j - 1]) == 1
		&& is_map_char(map[i][j + 1] == 1)))
		return (1);
	return (0);
}

int	first_last_line(char *line, int x)
{
	int	i;

	i = 0;
	if (x)
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != ' ' && line[i] != '2')
				return (0);
			i++;
		}
	}
	else if (!x)
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] != '1')
			return (0);
		i = ft_strlen(line) - 1;
		while(ft_isspace(line[i]) || line[i] == '2')
			i--;
		if (line[i] != '1')
			return (0);
	}
	return (1);
}

void	spacetoone(char **map)
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

void	angle_init(char c, t_data *data)
{
	if (c == 'S')
		data->player->angle = 90 * (M_PI / 180);
	else if (c == 'N')
		data->player->angle = 270 * (M_PI / 180);
	else if (c == 'W')
		data->player->angle = 180 * (M_PI / 180);
	else if (c == 'E')
		data->player->angle = 0 * (M_PI / 180);
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
				data->player->x = idx[1];
				data->player->y = idx[0];
			}
			idx[1]++;
		}
		idx[0]++;
	}
	if (count != 1)
		return (-15);
	return (0);
}

int parse_map(t_data *data, int lines)
{
	int		i;
	int		j;
	char	**map;

	1 && (map = data->map.map, i = 0);
	while (i < lines)
	{
		j = 0;
		if ((i == 0 || i == lines - 1) && (first_last_line(map[i], 1) == 0))
			return (-13);
		else if (i > 0 && i < lines - 1)
		{	while (map[i][j])
			{
				if (is_map_char(map[i][j]) == 1 && map[i][j] != ' ' && map[i][j] != '2')
					return (-11);
				else if (map[i][j] == '0' && check_directions(map, i, j) != 0)
					return (-12);
				if (first_last_line(map[i], 0) == 0)
					return (-14);
				j++;
			}
		}
		i++;
	}
	return (spacetoone(map), last_check(map, data));
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

int sec_char(char *tab, int i)
{
	if ((tab[i] == 'N' || tab[i] == 'S') && tab[i + 1] != 'O')
		return (-1);
	if ((tab[i] == 'F' || tab[i] == 'C') && !ft_isspace(tab[i + 1]))
		return (-1);
	if (tab[i] == 'E' && tab[i + 1] != 'A')
		return (-1);
	if (tab[i] == 'W' && tab[i + 1] != 'E')
		return (-1);
	return (0);
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
	if (max < 12)
		return (12);
	return (max);
}

int	_xtra_map(char ***map, int lenght)
{
	int	i;
	int len;
	char	**new_map;
	
	1 && (i = -1, new_map = (char **)malloc(sizeof(char *) * 9));
	if (!new_map)
		return (-2);
	while ((*map)[++i])
	{
		new_map[i] = ft_strdup((*map)[i]);
		if (!new_map[i])
			return (ft_free_par(*map), ft_free_par(new_map), -2);
	}
	while (i < 8)
	{
		1 && (len = -1, new_map[i] = NULL);
		while (++len < lenght)
		{
			new_map[i] = ft_strjoin(new_map[i], "2");
			if (!new_map[i])
				return (ft_free_par(*map), ft_free_par(new_map), -2);
		}
		i++;
	}
	return (new_map[i] = NULL,ft_free_par(*map), *map = new_map, 0);
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
		while (strlen < len)
		{
			(*map)[i] = ft_strjoin((*map)[i], "2");
			if (!(*map)[i])
				return ( -2);
			strlen = ft_strlen((*map)[i]);
		}
		i++;
	}
	if (i < 8)
		_xtra_map(map, len);
	return (0);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (1);
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
	data->rows_n = *j;
	map = (char **)malloc(sizeof(char *) * ((*j) + 1));
	if (!map)
		return (-2);
	(*j) = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) == 0 || empty_line(tab[i]) == 0)
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
		if (ft_strnstr(tab[i], "NO", ft_strlen(tab[i])))
			1 && (data->map.north = tab[i], data->map.news[0]++);
		else if (ft_strnstr(tab[i], "WE", ft_strlen(tab[i])))
			1 && (data->map.west = tab[i], data->map.news[2]++);
		else if (ft_strnstr(tab[i], "EA", ft_strlen(tab[i])))
			1 && (data->map.east = tab[i], data->map.news[1]++);
		else if (ft_strnstr(tab[i], "SO", ft_strlen(tab[i])))
			1 && (data->map.south = tab[i], data->map.news[3]++);
		else if (ft_strnstr(tab[i], "F", ft_strlen(tab[i])))
			1 && (data->map.fcolor = tab[i], data->map.color_f++);
		else if (ft_strnstr(tab[i], "C", ft_strlen(tab[i])))
			1 && (data->map.ccolor = tab[i], data->map.color_c++);
		stat = map_begins(tab[i], data->map);
		if (stat == 0)
		{
			stat2 = get_map(data, i, &j);
			if (stat2 < 0)
				return (stat2);
			break ;
		}
		else if (stat < 0)
			return (stat);
	}
	stat = elements_checker(data, i, tab, j);
	char **map = data->map.map;
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	return (stat);
}
