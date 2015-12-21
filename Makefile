# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 23:48:57 by ebouther          #+#    #+#              #
#    Updated: 2015/12/21 17:24:25 by ebouther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

LIBFT = -L./libft/ -lft

INCLUDES = -I./libft/includes/

FLAGS += -Wall -Wextra -Werror $(LIBFT) $(INCLUDES)

SRCS = alum1.c \
	   resolution.c \
	   utils.c \
	   read.c \
	   ascii_art.c \
	   get_next_line.c

OBJS = alum1.o \
	   resolution.o \
	   utils.o \
	   read.o \
	   ascii_art.o \
	   get_next_line.o

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./libft/
	@gcc -o $(NAME) $(FLAGS) $(SRCS)

clean:
	@make -C ./libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	@rm -rf $(NAME)

re: fclean all
