/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/01 17:20:24 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_int(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	is_element(char *mp, int i)
{
	if ((mp[i] == 'N' && mp[i + 1] == 'O')
		|| (mp[i] == 'S' && mp[i + 1] == 'O')
		|| (mp[i] == 'W' && mp[i + 1] == 'E')
		|| (mp[i] == 'E' && mp[i + 1] == 'A')
		|| (mp[i] == 'F' && mp[i + 1] == ' ')
		|| (mp[i] == 'C' && mp[i + 1] == ' '))
		return (1);
	else
		return (0);
}

int	is_map(char c)
{
	if (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

t_input	*in_init(t_input *in)
{
	in->width = 0;
	in->height = 0;
	in->elems = NULL;
	in->map = NULL;
	return (in);
}

int	divide_to_conquer(char *map_line, t_input *in,
	char **tmp_elms, char **tmp_map)
{
	int	j;

	tmp_map[in->height] = ft_strdup(map_line);
	tmp_elms[in->height] = NULL;
	j = 0;
	while (j < ft_strlen_int(map_line))
	{
		if (is_space(map_line[j]))
			j++;
		else if (is_element(map_line, j))
		{
			tmp_elms[in->height] = ft_strdup(map_line);
			break ;
		}
		else if (is_map(map_line[j]))
		{
			tmp_map[in->height] = ft_strdup(map_line);
			break ;
		}
		j++;
	}
	if (in->elems)
		free(in->elems);
	if (in->map)
		free(in->map);
	in->elems = tmp_elms;
	in->map = tmp_map;
	in->height++;
	return (1);
}



int	read_file(int fd, t_input *in)
{
	char	*map_line;
	char	**tmp_elms;
	char	**tmp_map;
	int		i;

	while ((map_line = get_next_line(fd)) != NULL)
	{
		if (in->width == 0)
			in->width = ft_strlen_int(map_line);
		if (!(tmp_elms = malloc(sizeof(char *) * (in->height +1))))
			return (0);
		if (!(tmp_map = malloc(sizeof(char *) * (in->height +1))))
		{
			free(tmp_elms);
			return (0);
		}
		i = 0;
		while (i < in->height)
		{
			tmp_elms[i] = in->elems[i];
			tmp_map[i] = in->map[i];
			i++;
		}
		if (!divide_to_conquer(map_line, in, tmp_elms, tmp_map))
			return (0);
	}
	if (map_line == NULL && in->height == 0)
	{
		free(in);
		return (0);
	}
	return (1);
}

t_input	*sort_data(char	*file, t_input *in)
{
	int		fd;

	if (!in)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		free(in);
		return (NULL);
	}
	in = in_init(in);
	if (!read_file(fd, in))
	{
		free(in);
		return (NULL);
	}
	close(fd);
	return (in);
}

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

// t_input	divide()

// t_input	sort_data(char *map, t_input in)
// {
// 	int	width;
// 	int	fd;
// 	int	i;

// 	i = 0;
// 	width = map_width(map);
// 	// *mp = malloc(sizeof(char *) * (width + 1));
// 	fd = open(map, O_RDONLY);
// 	if (!(*mp) || fd == -1)
// 		error_exit(strerror(errno));
// 	if (!all_elements())
// 	in = divide(in, width, map)
// }