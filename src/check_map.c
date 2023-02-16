/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:05:01 by lleiria-          #+#    #+#             */
/*   Updated: 2023/02/16 17:00:44 by lleiria-         ###   ########.fr       */
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

int	is_element(char **mp, int i, int j)
{
	if ((mp[j][i] == 'N' && mp[j][i + 1] == 'O') 
		|| (mp[j][i] == 'S' && mp[j][i + 1] == 'O')
		|| (mp[j][i] == 'W' && mp[j][i + 1] == 'E')
		|| (mp[j][i] == 'E' && mp[j][i + 1] == 'A')
		|| (mp[j][i] == 'F' && mp[j][i + 1] == ' ')
		|| (mp[j][i] == 'C' && mp[j][i + 1] == ' '))
		return (1);
	else
		return (0);
}

int	all_elements(char **mp, int width)
{
	int	nbr_el;
	int	i;
	int	j;

	nbr_el = 0;
	j = 0;
	while (j < width)
	{
		i = 0;
		while (mp[j][i] != '\n' && mp[j][i] != '\0')
		{
			if (is_element(mp, i, j))
				nbr_el++;
			i++;
		}
		j++;
	}
	printf("%d elements\n", nbr_el);
	if (nbr_el == 6)
		return (1);
	else
		return (0);
}

int	is_firstwall(char **mp, int i, int j)
{
	while (mp[j][i] != '\n' && mp[j][i] != '\0' && mp[j][i] != '1')
	{
		if (is_space(mp[j][i]))
				i++;
	}
	while (mp[j][i] != '\n' && mp[j][i] != '\0')
	{
		if (mp[j][i] != '1')
		{
			printf("is not closed\n");
			return(0);
		}
		i++;
	}
	return (1);
}

int	is_closed(char **mp, int width)
{
	int i;
	int	j;
	
	j = 0;
	while(j < width)
	{
		i = 0;
		while (mp[j][i] != '\n' && mp[j][i] != '\0')
		{
			if (is_space(mp[j][i]))
				i++;
			if (is_element(mp, i, j))
			{
				i = 0;
				j++;
			}
			if (is_space(mp[j][i]))
				i++;
			else if (is_firstwall(mp, i, j))
			{
				printf("is closed\n");
				break ;
			}
			i++;
		}
		j++;
	}
	return (1);	
}

int	checker(char *map, char ***mp)
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
	(*mp)[i] = get_next_line(fd);
	while ((*mp)[i])
	{
		// printf("%s", (*mp)[i]);
		(*mp)[++i] = get_next_line(fd);
	}
	if (!all_elements((*mp), width))
		error_exit("\e[1;91mError\nIncorret nbr of map elements\n\e[0m");
	if (!is_closed((*mp), width + 1))
		error_exit("\e[1;91mError\nMap is not closed\n\e[0m");
	return (0);
}