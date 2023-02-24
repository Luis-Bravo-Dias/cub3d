/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:08:21 by lleiria-          #+#    #+#             */
/*   Updated: 2023/02/22 14:57:20 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <math.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_input
{
	int		width;
	int		height;
	char	**elems;
	char	**map;
}	t_input;


//exit.c
void	error_exit(char *message);
//check_map.c
// char	***mp(void);
int		checker(char *mapa, char ***mp, t_map map);
//sort_data.c
t_input	sort_data(char *map, t_input in);

#endif