# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:07:04 by dehamad           #+#    #+#              #
#    Updated: 2024/03/17 20:43:13 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
AR = ar

LIBFT = libft/libft.a
SRCS = main.c parsing_utils.c
BNS = main.c
OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	make -C libft
	${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

bonus: ${BNS_OBJS}
	make -C libft
	make -C mlx
	${CC} ${CFLAGS} ${LIBFT} ${BNS_OBJS} -o ${NAME}_bonus

clean:
	rm -f $(OBJS) ${BNS_OBJS}
	make -C libft clean

fclean: clean
	rm -f $(NAME) ${NAME}_bonus
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
