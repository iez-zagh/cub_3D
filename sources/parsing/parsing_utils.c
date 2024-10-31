/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:28:59 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/10/31 01:43:37 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(char c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	return (0);
}

void	perreur2(int x)
{
	if (x == -11)
		write (2, "Error : the map chars are [0,1,' ',N|W|E|S]!\n", 46);
	else if (x == -12)
		write (2, "Error : the map : empty space inside map!\n", 43);
	else if (x == -13)
		write (2, "Error : the map : accepted chars on first/last"
			" lines are '1' & ' '!\n", 69);
	else if (x == -14)
		write (2, "Error : the map : '1' char needs tobe on first/last"
			" of the string !\n", 69);
	else if (x == -15)
		write (2, "Error : the map : N/S/W/E one of those chars must be"
			" inside map !\n", 67);
}

void	perreur(int x)
{
	if (x == -1)
		write(2, "Error : open(); failed !\n", 26);
	else if (x == -2)
		write(2, "Error : allocation failed !\n", 29);
	else if (x == -3)
		write (2, "", 25);
	else if (x == -4)
		write(2, "Error : mapfile should be .cub extention !\n", 44);
	else if (x == -5)
		write(2, "Error : mapfile is empty or insufuzent lines !\n", 48);
	else if (x == -6)
		write (2, "Error : NO/WE/SO/EA or texture path facing an issue\n", 53);
	else if (x == -7)
		write (2, "Error : textures must be on .png/.xpm extansions\n", 50);
	else if (x == -8)
		write (2, "Error : F / C lines facing error !\n", 36);
	else if (x == -9)
		write (2, "Error : F / C rgb values must bein 0-255 range !\n", 50);
	else if (x == -10)
		write (2, "Error : mapfile structure different than expected!\n", 52);
	else
		perreur2(x);
}

void	ft_free_par(char **tab)
{
	int	i;

	i = 0;
	if (!*tab || !tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	inisialize_vars(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		data->map.news[i] = 0;
	data->map.color_c = 0;
	data->map.color_f = 0;
	data->map.west = NULL;
	data->map.north = NULL;
	data->map.south = NULL;
	data->map.east = NULL;
}
