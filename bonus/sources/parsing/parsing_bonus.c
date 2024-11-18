/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:02:11 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/09/18 00:02:11 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	lines_counter(char mapname[])
{
	int		counter;
	char	*line;
	int		fd;

	counter = 0;
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), counter);
		counter++;
		free(line);
	}
	close(fd);
	return (0);
}

int	check_mapname(char mapname[], int *line)
{
	int	len;

	len = ft_strlen(mapname) - 4;
	if (ft_strncmp(mapname + len, ".cub", 5) != 0)
		return (-4);
	*line = lines_counter(mapname);
	if (*line == -1)
		return (-1);
	if (*line >= 0 && *line < 11)
		return (-5);
	return (0);
}

int	file_to_table(char mapname[], char **table)
{
	int		fd;
	char	*line;
	int		idx;

	1 && (idx = 0, fd = open(mapname, O_RDONLY));
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		table[idx++] = line;
	}
	table[idx] = NULL;
	close(fd);
	return (0);
}

int	load_textures(t_data *data)
{
	data->tex.north = mlx_load_png(data->map.north);
	if (!data->tex.north)
		return (ft_free_par(data->map.map), -17);
	data->tex.south = mlx_load_png(data->map.south);
	if (!data->tex.south)
		return (ft_free_par(data->map.map), delete_texture(data, 0), -17);
	data->tex.west = mlx_load_png(data->map.west);
	if (!data->tex.west)
		return (ft_free_par(data->map.map), delete_texture(data, 1), -17);
	data->tex.east = mlx_load_png(data->map.east);
	if (!data->tex.east)
		return (ft_free_par(data->map.map), delete_texture(data, 2), -17);
	data->tex.door = mlx_load_png("textures/door_2.png");
	if (!data->tex.door)
		return (ft_free_par(data->map.map), delete_texture(data, 3), -17);
	return (free_leaks(&data->map, 4), 0);
}

int	parsing(t_data *data, char mapname[])
{
	int		stat;
	char	**table;
	int		lines;

	stat = check_mapname(mapname, &lines);
	if (stat < 0)
		return (perreur(stat), stat);
	table = (char **)malloc (sizeof(char *) * (lines + 1));
	if (!table)
		return (perreur(-2), 2);
	stat = file_to_table(mapname, table);
	if (stat < 0)
		return (ft_free_par(table), perreur(stat), stat);
	data->map.table = table;
	stat = check_table(data);
	if (stat < 0)
		return (ft_free_par(table), perreur(stat), stat);
	ft_free_par(table);
	stat = load_textures(data);
	if (stat < 0)
		return (free_leaks(&data->map, 4), perreur(stat), stat);
	return (0);
}
