/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:08:21 by lleiria-          #+#    #+#             */
/*   Updated: 2023/03/27 16:15:08 by lleiria-         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_input
{
	char	*	NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	char		**map;
	int			lines;
	t_player	play;
}	t_input;


//exit.c
int		msg_error(char *message);
void	free_matrix(char **matrix);
void	free_array(char *str);
//check_map.c
int		check_map(t_input *in);
//check_map_utils.c
int		anormalies(char **map);
int		extreme_lines(char **map, int line);
int		validate(char x, int is_wall);
int		not_solo(t_input *in);
//sort_data.c
int		sort_data(t_input *in, char *file);
//parsing_utils.c
int		matrix_size(char **matrix);
char	*ft_strdup_cub(const char *s1);
int		file_lines(char *file);

#endif