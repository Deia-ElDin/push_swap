# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:07:04 by dehamad           #+#    #+#              #
#    Updated: 2024/03/19 03:52:42 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
AR = ar

LIBFT = libft/libft.a
SRCS = main.c parsing.c utils.c sign_parsing_utils.c stack_validation_utils.c \
	stack_swap_moves.c stack_push_moves.c stack_rotate_moves.c \
	
BNS = main.c
OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BNS_OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(BNS_OBJS) -o $(NAME)_bonus

$(LIBFT):
	make -C libft
	
clean:
	rm -f $(OBJS) ${BNS_OBJS}
	# make -C libft clean

fclean: clean
	rm -f $(NAME) ${NAME}_bonus
	# make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
