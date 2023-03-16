/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:05:01 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/16 17:28:45 by lleiria-         ###   ########.fr       */
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

int	closed_extreme(char **map, int line)
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
			}
	return (0);
}

int	is_closed(char **map)
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
			error_found += closed_extreme(map, line)
	}
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
	if (!is_closed(in->map))
		return(msg_error("\e[1;91mError\nMap not closed\n\e[0m"));
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