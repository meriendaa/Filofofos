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

SRC = src/main.c

OBJ	= $(addprefix objs/,$(SRC:.c=.o))

CC = gcc

CFLAGS  = -Wall -Wextra -Werror

HEADER = ./include/philo.h

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^


all: $(NAME)

$(NAME):$(OBJ) $(HEADER)
		$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf ./objs

fclean:
	@rm -f ${NAME}

re:
	fclean all

.PHONY: all re clean fclean