/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:31:54 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/15 14:39:11 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file(char *file)
{
	int	end;
	
	end = ft_strlen(file) - 1;
	if (file[end] != 'b' || file[end - 1] != 'u'
		|| file[end - 2] != 'c' || file[end - 3] != '.')
	{
		printf("\e[1;91mError\nInvalid file type\n\e[0m");
		exit(1);
	}
}

// int	file_lines(char	*file)
// {
// 	int		counter;
// 	int		fd;
// 	char	*line;

// 	counter = 0;
// 	fd = open(file, O_RDONLY);
// 	line = NULL;
// 	while ((line = get_next_line(fd)))
// 	{
// 		counter++;
// 		free(line);
// 	}
// 	if (line)
// 		free(line);
// 	close(fd);
// 	return (counter);
// }

void	liberate(t_input *in)
{
	free_array(in->NO);
	free_array(in->SO);
	free_array(in->WE);
	free_array(in->EA);
	free_array(in->F);
	free_array(in->C);
	free_matrix(in->map);
}

int	main(int ac, char **av)
{
	// t_map	map;
	t_input	in;
	int		j;
	// int		lines;
	
	// map.x = 0;
	// map.y = 0;
	j = 0;
	ft_memset(&in, 0, sizeof(t_input));
	if (ac != 2)
		printf("\e[1;91mError\nwrong number of arguments\n\e[0m");
	// lines = file_lines(av[1]);
	// printf("%d lines\n", lines);
	// check_file(av[1]);
	if (sort_data(&in, av[1]) || check_map(&in))
	{
		liberate(&in);
		return (1);
	}
	printf("elementos:\n");
	printf("NO = %s\n", in.NO);
	printf("SO = %s\n", in.SO);
	printf("WE = %s\n", in.WE);
	printf("EA = %s\n", in.EA);
	printf("F = %s\n", in.F);
	printf("C = %s\n", in.C);
	printf("map:\n");
	while (in.map[j])
	{
		printf("%s\n", in.map[j]);
		j++;
	}
	// checker(av[1], mp(), map);
	// printf("Valid map\n");
	liberate(&in);
}