# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 19:19:04 by tmerida-          #+#    #+#              #
#    Updated: 2022/05/18 19:19:05 by tmerida-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/philo.c \
		src/init_data.c\
		src/utils.c \
		src/routine.c \
		src/print_message.c \
		src/philo_dead.c \
		src/free_info.c

OBJ	= $(SRC:.c=.o)

CC = gcc

CFLAGS  = -Wall -Wextra -Werror

HEADER = ./include/philo.h

all: $(NAME)

$(NAME):$(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean