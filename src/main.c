/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:31:54 by lleiria-          #+#    #+#             */
/*   Updated: 2023/02/17 16:08:57 by lleiria-         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map	map;
	t_input	in;
	
	map.x = 0;
	map.y = 0;
	if (ac != 2)
		printf("\e[1;91mError\nwrong number of arguments\n\e[0m");
	check_file(av[1]);
	in = sort_data(av[1], mp(), in)
	checker(av[1], mp(), map);
	printf("Valid map\n");
}