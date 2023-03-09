/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/09 12:50:17 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_element(t_input *in, char *line)
{
	if (!ft_strncmp(line, "NO", 3) && in->NO == NULL)
		in->NO = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO", 3) && in->SO == NULL)
		in->SO = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE", 3) && in->WE == NULL)
		in->WE = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA", 3) && in->EA == NULL)
		in->EA = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2) && in->F == NULL)
		in->F = ft_strdup(line + 2);
	else if (!ft_strncmp(line, "C ", 2) && in->C == NULL)
		in->C = ft_strdup(line + 2);
}

int	matrix_size(char **matrix)
{
	int	counter;

	counter = 0;
	while (matrix[i])
		counter++;
	return (counter);
}

//perguntar ao Lucas sobre o 6 e o 5
int	putt_elems(t_input *in, char **tmp)
{
	int	i;
	
	i = -1;
	in->lines = matrix_size(tmp) - 6;
	while (++i <= 5)
		is_element(in, tmp[i]);
}

char	*ft_strdup_cub(const char *s1)
{
	char	*p;
	size_t	n;
	size_t	slen;

	slen = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	n = 0;
	if (p == NULL)
		return (NULL);
	while (s1[n] != '\0' && s1[n] != '\n')
	{
		p[n] = s1[n];
		n++;
	}
	p[n] = '\0';
	return (p);
}


int	file_lines(char *file)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(strerror(errno));
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		counter++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (counter);
}

int	sort_data(t_input *in, char	*file)
{
	int	fd;
	int	i;
	char	**tmp;
	char	*map_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(strerror(errno));
	in->lines = file_lines(file);
	tmp = malloc(sizeof(char *) * (in->lines + 1));
	tmp[in->lines] = NULL;
	i = -1;
	map_line = get_next_line(fd);
	while (map_line)
	{
		if (line[0] != '\n' && in->lines > 0)
		{
			tmp[++i] = ft_strdup_cub(map_line);
			in->lines--;
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (putt_elems(in, tmp));
}

// int	ft_strlen_int(const char *str)
// {
// 	int	n;

// 	n = 0;
// 	while (str[n] != '\0')
// 		n++;
// 	return (n);
// }

// int	is_space(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\v')
// 		return (1);
// 	return (0);
// }

// int	is_element(char *mp, int i)
// {
// 	if ((mp[i] == 'N' && mp[i + 1] == 'O')
// 		|| (mp[i] == 'S' && mp[i + 1] == 'O')
// 		|| (mp[i] == 'W' && mp[i + 1] == 'E')
// 		|| (mp[i] == 'E' && mp[i + 1] == 'A')
// 		|| (mp[i] == 'F' && mp[i + 1] == ' ')
// 		|| (mp[i] == 'C' && mp[i + 1] == ' '))
// 		return (1);
// 	else
// 		return (0);
// }

// int	is_map(char c)
// {
// 	if (c == '1' || c == '0' || c == 'N'
// 		|| c == 'S' || c == 'E' || c == 'W')
// 		return (1);
// 	else
// 		return (0);
// }

// char	*ft_strcpy(char *dest, const char *src)
// {
// 	int	n;

// 	n = 0;
// 	while (src[n] != '\0')
// 	{
// 		dest[n] = src[n];
// 		n++;
// 	}
// 	dest[n] = '\0';
// 	return (dest);
// }


// char	**allocator(int	lines, int max_len)
// {
// 	char	**matrix;
// 	int		i;

// 	i = 0;
// 	matrix = malloc(sizeof(char *) * lines);
// 	if (!matrix)
// 		return (NULL);
// 	while (i < lines)
// 	{
// 		matrix[i] = malloc(sizeof(char) * max_len);
// 		i++;
// 	}
// 	return (matrix);
// }

// t_input	*map_reader(char *file, t_input *in)
// {
// 	int		lines;
// 	char	*map_line;
// 	int		fd;
// 	int		i;
// 	int		j;
	
// 	lines = file_lines(file);
// 	in->elems = allocator(lines, MAX_LINE_LEN);
// 	if (!in->elems)
// 		return (NULL);
// 	in->map = allocator(lines, MAX_LINE_LEN);
// if (!in->map)
// {
// 	free(in->elems);
// 	return (NULL);
// }
// 	fd = open(file, O_RDONLY);
// 	map_line = NULL;
// 	i = 0;
// 	while ((map_line = get_next_line(fd)))
// 	{
// 		j = 0;
// 		while (map_line[j] != '\0' && map_line[j] != '\n')
// 		{
// 			if (is_space(map_line[j]))
// 				j++;
// 			else if (is_element(map_line, j))
// 			{
// 				if (in->elems)
// 					ft_strcpy(in->elems[i], map_line);
// 				break ;
// 			}
// 			else
// 			{
// 				if (in->map)
// 					ft_strcpy(in->map[i], map_line);
// 			}
// 			j++;
// 		}
// 		free(map_line);
// 		i++;
// 	}
// 	close(fd);
// 	return(in);
// }



// t_input	*in_init(t_input *in)
// {
// 	in->width = 0;
// 	in->height = 0;
// 	in->NO = NULL;
// 	in->SO = NULL;
// 	in->WE = NULL;
// 	in->EA = NULL;
// 	in->F = NULL;
// 	in->C = NULL;
// 	in->map = NULL;
// 	return (in);
// }

// int	divide_to_conquer(char *map_line, t_input *in,
// 	char **tmp_elems, char **tmp_map)
// {
// 	int	j;

// 	tmp_map[in->height] = NULL;
// 	tmp_elems[in->height] = NULL;
// 	j = 0;
// 	while (j < ft_strlen_int(map_line))
// 	{
// 		if (is_space(map_line[j]))
// 			j++;
// 		else if (is_element(map_line, j))
// 		{
// 			if (in->blank)
// 			{
// 				tmp_elems[in->height] = ft_strdup(map_line);
// 				break ;
// 			}
// 			j++;
// 		}
// 		else if (is_map(map_line[j]))
// 		{
// 			tmp_map[in->height] = ft_strdup(map_line);
// 			break ;
// 		}
// 		else if (map_line[j] == '\n')
// 		{
// 			in->blank = 1;
// 			j++;
// 		}
// 		else
// 			j++;
// 	}
// 	if (in->elems)
// 		free(in->elems);
// 	if (in->map)
// 		free(in->map);
// 	in->elems = tmp_elems;
// 	in->map = tmp_map;
// 	in->height++;
// 	return (1);
// }



// int	read_file(int fd, t_input *in)
// {
// 	char	*map_line;
// 	// char	**tmp_elems;
// 	// char	**tmp_map;
// 	// int		i;

// 	while ((map_line = get_next_line(fd)) != NULL)
// 	{
// 		// i = 0;
// 		if (in->width == 0)
// 			in->width = ft_strlen_int(map_line);
// 		printf("line: %s\n", map_line);
		
// 		// if (!(tmp_elems = malloc(sizeof(char *) * (in->height +1))))
// 		// 	return (0);
// 		// if (!(tmp_map = malloc(sizeof(char *) * (in->height +1))))
// 		// {
// 		// 	free(tmp_elems);
// 		// 	return (0);
// 		// }
// 		// i = 0;
// 		// while (i < in->height)
// 		// {
// 		// 	tmp_elems[i] = in->elems[i];
// 		// 	tmp_map[i] = in->map[i];
// 		// 	i++;
// 		// }
// 		// if (!divide_to_conquer(map_line, in, tmp_elems, tmp_map))
// 		// 	return (0);
// 	}
// 	if (map_line == NULL && in->height == 0)
// 	{
// 		free(in);
// 		return (0);
// 	}
// 	return (1);
// }

// t_input	*sort_data(char	*file, t_input *in)
// {
// 	int		fd;

// 	if (!in)
// 		return (NULL);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("%s\n", strerror(errno));
// 		free(in);
// 		return (NULL);
// 	}
// 	in = in_init(in);
// 	if (!read_file(fd, in))
// 	{
// 		free(in);
// 		return (NULL);
// 	}
// 	close(fd);
// 	return (in);
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