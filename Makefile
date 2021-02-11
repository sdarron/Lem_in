# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warchiba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#              #
#    Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
INCLUDELIB = libft/includes/
INCLUDE = includes/
SRC = src/
LIBPATH = libft/
FUNC = main.c line_checkers.c solution.c read_utils.c parse_room_name.c free_utils.c parse_links.c check_rooms.c queue_utils.c edmonds_karp.c count_steps.c choose_solution.c init_utils.c quick_sort.c write_solution.c count_steps_2.c edmonds_karp_2.c parse_links_init.c init_queues.c
OBJ = $(FUNC:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): librun
	gcc $(FLAGS) $(addprefix $(SRC), $(FUNC)) -I $(INCLUDE) -I $(INCLUDELIB) -L $(LIBPATH) -lft -o $(NAME)

librun:
	cd $(LIBPATH) && $(MAKE) all

clean:
	/bin/rm -Rf $(OBJ)
	cd $(LIBPATH) && $(MAKE) clean

fclean: clean
	/bin/rm -Rf $(NAME)
	cd $(LIBPATH) && $(MAKE) fclean

re: fclean all
