/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:05:01 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/27 16:14:38 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_borders(char **map, int y, int x)
{
	int	end_space;

	end_space = (int)ft_strlen(map[y]) - 2;
	if (x == 1)
	{
		if (validate(map[y][0], 1) || validate(map[y][2], 0)
			|| validate(map[y + 1][1], 0) || validate(map[y - 1][1], 0))
			return (1);
	}
	else if (x == end_space)
	{
		if (validate(map[y][x - 1], 0) || validate(map[y][x + 1], 1)
			|| validate(map[y + 1][x], 0) || validate(map[y - 1][x], 0))
			return (1);
	}
	return (0);
}

int	check_inside(char **map, int y, int x)
{
	if (x <= 1 || x >= (int)ft_strlen(map[y]) - 2)
		return (0);
	if (validate(map[y][x - 1], 0) || validate(map[y][x + 1], 0)
			|| validate(map[y + 1][x], 0) || validate(map[y - 1][x], 0))
		return (1);
	return (0);
}

int	midle_lines(char **map, int line)
{
	int	i;

	i = -1;
	while (map[line][++i])
	{
		if (map[line][i] == '0' || map[line][i] == 'N' || map[line][i] == 'S'
			|| map[line][i] == 'E' || map[line][i] == 'W')
		{
			if (i == 0 || i == (int)ft_strlen(map[line]) - 1)
				return (1);
			if (check_borders(map, line, i))
				return (1);
			if (check_inside(map, line, i))
				return (1);
		}
	}
	return (0);
}

int	not_closed(char **map)
{
	int	line;
	int	error_found;
	int	last_line;

	line = -1;
	error_found = 0;
	last_line = 0;
	while (map[last_line])
		last_line++;
	while (map[++line])
	{
		if (line == 0 || line == last_line - 1)
			error_found += extreme_lines(map, line);
		else
			error_found += midle_lines(map, line);
		if (error_found != 0)
			break ;
	}
	return (error_found);
}

int	check_map(t_input *in)
{
	if (anormalies(in->map))
		return (msg_error("\e[1;91mError\nAnormalies found in the map\n\e[0m"));
	if (not_closed(in->map))
		return (msg_error("\e[1;91mError\nMap is not closed\n\e[0m"));
	if (not_solo(in))
		return (msg_error("\e[1;91mError\nThis map is not single player\n\e[0m"));
	printf("MAP IS fineeeeee\n");
	return (0);
}
