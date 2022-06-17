# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baura <baura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 20:19:06 by baura             #+#    #+#              #
#    Updated: 2022/04/11 18:09:51 by baura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST = 		ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c		ft_isalpha.c\
			ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_memchr.c			ft_memcmp.c\
			ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_strchr.c			ft_strdup.c\
			ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		ft_strncmp.c		ft_strnstr.c\
			ft_strrchr.c	ft_tolower.c	ft_toupper.c	ft_putchar_fd.c		ft_substr.c\
			ft_strjoin.c	ft_strmapi.c	ft_putendl_fd.c	ft_strtrim.c		ft_putnbr_fd.c\
			ft_putstr_fd.c	ft_itoa.c		ft_striteri.c	ft_split.c\
			get_next_line.c	get_next_line_utils.c

LIST_B = 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

OBJ = $(LIST:%.c=%.o)
OBJ_B = $(LIST_B:%.c=%.o)

HEADER = libft.h
FLAGS = -Wall -Wextra -Werror -I$(HEADER)
CC = gcc
RM = rm -f

.PHONY : all clean fclean re bonus

all :	$(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus :
	@make OBJ="$(OBJ_B)" all

clean : 
	$(RM) $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re: fclean all bonus
