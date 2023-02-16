/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:03:46 by lleiria-          #+#    #+#             */
/*   Updated: 2023/02/16 12:38:16 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char ***mp)
{
	int	i;

	i = 0;
	if (*mp)
	{
		while ((*mp)[i])
			free((*mp)[i++]);
		free(*mp);
	}
}

void	error_exit(char *message)
{
	if (*mp())
		free_map(mp());
	printf("%s", message);
	exit(1);
}