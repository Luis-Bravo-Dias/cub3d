/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:08:21 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/14 10:25:12 by lleiria-         ###   ########.fr       */
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
# include <ctype.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

#define MAX_LINE_LEN 10000

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_input
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	**map;
	int		lines;
}	t_input;


//exit.c
int		msg_error(char *message);
void	free_matrix(char **matrix);
void	free_array(char *str);
//check_map.c
// char	***mp(void);
int		checker(char *mapa, char ***mp, t_map map);
//sort_data.c
// t_input	*map_reader(char *file, t_input *in);
int		sort_data(t_input *in, char *file);

#endif