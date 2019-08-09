# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfrankly <hfrankly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 12:46:18 by hfrankly          #+#    #+#              #
#    Updated: 2019/08/09 11:18:45 by hfrankly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSWAP = push_swap
PSRCS = psrcs/main.c psrcs/ssort.c gnl/get_next_line.c
CHECKER = checker
CSRCS = csrcs/main.c gnl/get_next_line.c
FLAGS = -Wall -Wextra -Werror -g
SRCS = srcs/errors.c srcs/inits.c srcs/instructions.c
LIBFT = -L./libft -lft
INCLUDES = -I includes -I libft -I gnl -I.

all: $(CHECKER) $(PSWAP) make -C libft

$(PSWAP):
	gcc $(FLAGS) $(LIBFT) $(INCLUDES) $(SRCS) $(PSRCS) -o $(PSWAP)

$(CHECKER):
	gcc $(FLAGS) $(LIBFT) $(INCLUDES) $(SRCS) $(CSRCS) -o $(CHECKER)

clean:
	rm -rf *~

fclean: clean
	rm -rf $(CHECKER) $(PSWAP) 

re: fclean all
