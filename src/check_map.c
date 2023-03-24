/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:05:01 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/24 15:39:43 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_space(char	c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	anormalies(char **map)
{
	int	i;
	int	j;
	
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'N' && map[j][i] != 'S'
				&& map[j][i] != 'W' && map[j][i] != 'E' && map[j][i] != ' '
				&& map[j][i] != '\t' && map[j][i] != '\n')
				return (1);
			else
				i++;
		}
		j++;
	}
	return (0);
}

int	extreme_lines(char **map, int line)
{
	int	i;

	i = -1;
	while (map[line][++i])
		if (map[line][i] == '0' || map[line][i] == 'N'
			|| map[line][i] == 'S' || map[line][i] == 'E' || map[line][i] == 'W')
					return (1);
	return (0);
}

int	validate(char x, int is_wall)
{
	if (is_wall == 1)
	{
		if (x != '1')
		{
			printf("error in is wall char = %c\n", x);
			return (1);
		}
	}
	else
	{
		if (x == '0' || x == '1' || x == 'N' || x == 'S'
			|| x == 'E' || x == 'W')
			return (0);
		else
		{
			printf("error char = %c\n", x);
			return (1);
		}
	}
	return (0);
}

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
			{
				printf("error in y%d x%d\n", y, x);
				return (1);
			}
	return (0);
}

int	midle_lines(char **map, int line)
{
	int	i;

	i = -1;
	while (map[line][++i])
	{
		if (map[line][i] == '0' || map[line][i] == 'N'
			|| map[line][i] == 'S' || map[line][i] == 'E' || map[line][i] == 'W')
		{
				if (i == 0 || i == (int)ft_strlen(map[line]) - 1)
					return (1);
				if (check_borders(map, line, i))
					return (1);
				if (check_inside(map, line, i))
					return (msg_error("Aqui!!!\n"));
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
			break;
	}
	return (error_found);
}

// int	closed_extreme(char **map)
// {
// 	int	i;
// 	int	j;
	
// 	j = 0;
// 	while (map[j])
// 	{
// 		i = 0;
// 		while (map[0][i])
// 		{
// 			if (map[j][i] == '0' || map[j][i] == 'N' || map[j][i] == 'S'
// 				|| map[j][i] == 'W' || map[j][i] == 'E')
// 				return (1);
// 			else
// 				i++;
// 		}
// 		j++;
// 	}
// 	printf("%d linessssssssssssssssssssssssssssss\n", j);
// 	return (0);
// }

int	check_map(t_input *in)
{
	// int	i;
	
	// i = 0;
	if (anormalies(in->map))
		return(msg_error("\e[1;91mError\nAnormalies found in the map\n\e[0m"));
	if (not_closed(in->map))
		return(msg_error("\e[1;91mError\nMap is not closed\n\e[0m"));
	printf("MAP IS fineeeeee\n");
	return (0);
}

// char	***mp(void)
// {
// 	static char	**map;
	
// 	return (&map);
// }

// int	map_width(char	*map)
// {
// 	int		fd;
// 	int		lines;
// 	char	c[1];
	
// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 		error_exit(strerror(errno));
// 	lines = 0;
// 	while (read(fd, c, 1) != 0)
// 	{
// 		if (c[0] == '\n')
// 			lines++;
// 	}
// 	if (c[0] != '\n')
// 		lines++;
// 	close(fd);
// 	return (lines);
// }


// int	is_element(char **mp, int i, int j)
// {
// 	if ((mp[j][i] == 'N' && mp[j][i + 1] == 'O') 
// 		|| (mp[j][i] == 'S' && mp[j][i + 1] == 'O')
// 		|| (mp[j][i] == 'W' && mp[j][i + 1] == 'E')
// 		|| (mp[j][i] == 'E' && mp[j][i + 1] == 'A')
// 		|| (mp[j][i] == 'F' && mp[j][i + 1] == ' ')
// 		|| (mp[j][i] == 'C' && mp[j][i + 1] == ' '))
// 		return (1);
// 	else
// 		return (0);
// }

// int	all_elements(char **mp, int width)
// {
// 	int	nbr_el;
// 	int	i;
// 	int	j;

// 	nbr_el = 0;
// 	j = 0;
// 	while (j < width)
// 	{
// 		i = 0;
// 		while (mp[j][i] != '\n' && mp[j][i] != '\0')
// 		{
// 			if (is_element(mp, i, j))
// 				nbr_el++;
// 			i++;
// 		}
// 		j++;
// 	}
// 	printf("%d elements\n", nbr_el);
// 	if (nbr_el == 6)
// 		return (1);
// 	else
// 		return (0);
// }

// t_map	only_map(char **mp, t_map map, int width)
// {
// 	int i;
// 	int	j;
	
// 	j = 0;
// 	i = 0;
// 	while(j < width)
// 	{
// 		i = 0;
// 		while (mp[j][i] != '\0')
// 		{
// 			if (is_space(mp[j][i]))
// 				i++;
// 			else if (is_element(mp, i, j))
// 			{
// 				i = 0;
// 				j++;
// 			}
// 			else if (mp[j][i] == '1')
// 				break ;
// 			i++;
// 		}
// 		j++;
// 	}
// 	// printf("x = %d\ny = %d\n", map.x, map.y);
// 	map.x = i;
// 	map.y = j;
// 	return (map);
// }

// // int	is_firstwall(char **mp, int i, int j)
// // {
// // 	while (mp[j][i] != '\n' && mp[j][i] != '\0' && mp[j][i] != '1')
// // 	{
// // 		if (is_space(mp[j][i]))
// // 				i++;
// // 	}
// // 	while (mp[j][i] != '\n' && mp[j][i] != '\0')
// // 	{
// // 		if (mp[j][i] != '1')
// // 		{
// // 			printf("is not closed\n");
// // 			return(0);
// // 		}
// // 		i++;
// // 	}
// // 	return (1);
// // }

// // int	is_closed(char **mp, int width)
// // {
// // 	int i;
// // 	int	j;
	
// // 	j = 0;
// // 	while(j < width)
// // 	{
// // 		i = 0;
// // 		while (mp[j][i] != '\n' && mp[j][i] != '\0')
// // 		{
// // 			if (is_space(mp[j][i]))
// // 				i++;
// // 			if (is_element(mp, i, j))
// // 			{
// // 				i = 0;
// // 				j++;
// // 			}
// // 			if (mp[j][i] == '1' && mp[j][i + 1] == '1'
// // 				&& (mp[j][i - 1] == ' ' || mp[j][i - 1] == '\t'))
// // 			{
// // 				printf("is closed\n");
// // 				break ;
// // 			}
// // 			i++;
// // 		}
// // 		j++;
// // 	}
// // 	return (1);	
// // }

// int	checker(char *mapa, char ***mp, t_map map)
// {
// 	int	width;
// 	int	fd;
// 	int	i;

// 	i = 0;
// 	width = map_width(mapa);
// 	*mp = malloc(sizeof(char *) * (width + 1));
// 	fd = open(mapa, O_RDONLY);
// 	if (!(*mp) || fd == -1)
// 		error_exit(strerror(errno));
// 	(*mp)[i] = get_next_line(fd);
// 	while ((*mp)[i])
// 	{
// 		// printf("%s", (*mp)[i]);
// 		(*mp)[++i] = get_next_line(fd);
// 	}
// 	if (!all_elements((*mp), width))
// 		error_exit("\e[1;91mError\nIncorret nbr of map elements\n\e[0m");
// 	map = only_map((*mp), map, width);
// 	printf("x = %d\ny = %d\n", map.x, map.y);
// 	// if (check_anormalies())
// 	// if (!is_closed((*mp), width + 1))
// 	// 	error_exit("\e[1;91mError\nMap is not closed\n\e[0m");
// 	return (0);
// }