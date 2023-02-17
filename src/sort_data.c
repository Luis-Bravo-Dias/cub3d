/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/02/17 16:37:50 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	all_elements(char **mp, int width, t_input in)
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

t_input	sort_data(char *map, t_input in)
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
}