# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 12:06:25 by lleiria-          #+#    #+#              #
#    Updated: 2023/03/27 14:45:17 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread #-fsanitize=thread -g
#MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

NAME		=	cub3D

DEPS		=	libft/libft.a get_next_line/get_next_line.a
INCLUDE		=	-I cub3d.h
SRCS_		=	main.c \
				exit.c \
				check_map.c \
				sort_data.c \
				parsing_utils.c \
				check_map_utils.c

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

_OBJ		=	./obj/
_SRC		= 	./src/
OBJS		=	$(patsubst $(_SRC)%.c, $(_OBJ)%.o, $(SRCS))

all:		$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(NAME): $(DEPS) $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(DEPS)

#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

libft/libft.a:
	make libft.a -C libft
get_next_line/get_next_line.a:
	make get_next_line.a -C get_next_line

$(_OBJ):
	mkdir $@

clean:
	make clean -C libft
	make clean -C get_next_line
	$(RM) -r $(_OBJ)

fclean:	clean
	make fclean -C libft
	make fclean -C get_next_line
	$(RM) $(NAME)

re:	fclean all
