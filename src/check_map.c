/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:05:01 by lleiria-          #+#    #+#             */
/*   Updated: 2023/02/15 17:21:47 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	***mp(void)
{
	static char	**map;
	
	return (&map);
}

int	map_width(char	*map)
{
	int		fd;
	int		lines;
	char	c[1];
	
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_exit(strerror(errno));
	lines = 0;
	while (read(fd, c, 1) != 0)
	{
		if (c[0] == '\n')
			lines++;
	}
	if (c[0] != '\n')
		lines++;
	close(fd);
	return (lines);
}

int	is_space(char	c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	is_element(char c)
{
	if (c == 'N' )
}

int	is_closed(char ***mp, int width)
{
	int i;
	int	j;
	
	j = 0;
	while((*mp)[j][i])
	{
		
	}	
}

int	checker(char map, char ***mp)
{
	int	width;
	int	fd;
	int	i;

	i = 0;
	width = map_width(map);
	*mp = malloc(sizeof(char *) * (width + 1));
	fd = open(map, O_RDONLY);
	if (!(*mp) || fd == -1)
		error_exit(strerror(errno));
	while ((*mp)[i])
		(*mp)[++i] = get_next_line(fd);
	if (!is_closed(mp, width + 1))
		error_exit("\e[1;91mError\nMap is not closed\n\e[0m");
	
	
}