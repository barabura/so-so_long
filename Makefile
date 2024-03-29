# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baura <baura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:31:33 by baura             #+#    #+#              #
#    Updated: 2022/07/07 16:51:07 by baura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

# NAME_B 	= so_long_bonus

LIB 	= libft/libft.a

SRCS 	= 	so_long.c	so_long_utils.c		map_check.c		map_transform.c		window.c \
			moves.c		moves_check.c		init.c			animation.c			animation_2.c

# SRCS_B 	= 	

OBJS 	= $(SRCS:%.c=%.o)
OBJS_B 	= $(SRCS_B:%.c=%.o)

HEADER 	= so_long.h
FLAGS 	= -Wall -Wextra -Werror -g
LFLAGS 	= -L libft/ -lft
CC 		= gcc
RM 		= rm -f

.PHONY 	: all clean fclean re

all		:	$(NAME)

$(NAME) :	$(OBJS) $(HEADER) $(LIB)
			@make -C mlx/
			$(CC) $(FLAGS) $(LFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# bonus 	:	$(NAME_B)

# $(NAME_B) :	$(OBJS_B) $(HEADER) $(LIB)
#			$(CC) $(FLAGS) $(LFLAGS) $(OBJS_B) -o $(NAME_B)
		
%.o : %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(LIB) 	: 
	make -C libft/
			
do :
	leaks -atExit -- ./so_long map.ber

clean : 
	$(RM) $(OBJS) $(OBJ_B)
	@make clean -C libft/
	@make clean -C mlx/

fclean : clean
	$(RM) $(NAME) $(NAME_B)
	@make fclean -C libft/

re: fclean all
