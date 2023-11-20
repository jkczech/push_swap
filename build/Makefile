# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/18 16:57:53 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[31;1m
GREEN = \033[32;1m
ORANGE = \033[33;1m

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP
AR = ar rcs
RM = rm -rf
LIBFT = 		../library/libft/build/libft.a
PRINTF = 		../library/printf/build/printf.a

SRCS = 	free.c \
		ft_atoi_mod.c \
		main.c \
		op_1.c op_2.c op_3.c \
		sort.c \
		sort_few.c \
		stack.c 	
# print.c for testing
		
MATH_FLAGS = -lm

OBJ_DIR = object
OBJS = $(addprefix ../object/, $(SRCS:.c=.o))
DEPS = $(addprefix ../object/, $(SRCS:.c=.d))

.SILENT:

all: $(LIBFT) $(PRINTF) $(NAME)

../object/%.o: ../source/%.c 
	mkdir -p $(dir $@)
	printf "$(ORANGE).$(END)";
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CC_FLAGS) $(MLX_FLAGS) $(MATH_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)
	printf "\r\r$(GREEN)🚀 ./$(NAME)\tcreated                          \n$(END)"

$(LIBFT):
	printf "$(ORANGE)🔁 ./$(NAME)\tcompiling.$(END)"
	make bonus -sC ../library/libft/build

$(PRINTF):
	printf "$(ORANGE).$(END)";
	make  -sC ../library/printf/build

clean:
	$(RM) ../object
	make clean -sC ../library/libft/build
	make clean -sC ../library/printf/build
	printf "$(RED)💥 object files\tremoved\n$(END)"

fclean: clean
	make fclean -sC ../library/libft/build
	make fclean -sC ../library/printf/build
	$(RM) $(NAME)
	printf "$(RED)💥 ./$(NAME) \tremoved\n$(END)"

re: reprint fclean all
	
reprint:
	printf "$(ORANGE)🚧 ./$(NAME)\trebuild\n$(END)"

valgrind: all
	valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no ./$(NAME) $(ARG)

funcheck: all
	funcheck ./$(NAME) $(ARG)

funchecka: all
	funcheck -a ./$(NAME) $(ARG)

-include $(DEPS)

.PHONY: all bonus clean fclean re valgrind funcheck funchecka