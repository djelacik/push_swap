# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:59:53 by djelacik          #+#    #+#              #
#    Updated: 2024/08/06 17:17:38 by djelacik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

NAME        = push_swap
SOURCES     = \
	push_swap.c \
	push.c \
	rotate.c \
	swap.c \
	reverse_rotate.c \
	ps_utils.c \
	ps_utils2.c \
	algorithm_utils.c \
	set_costs.c \
	super_algo.c
OBJECTS     = ${SOURCES:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all:		${NAME}

${NAME}:	${OBJECTS}
			@echo "\033[35m----Compiling libft and get_next_line----"
			@make -C ./libft
			$(CC) $(OBJECTS) -Llibft -lft -o ${NAME}
			@echo "Push_swap Compiled!\n"

bonus:		.bonus

.bonus:		${B_OBJECTS}
			@echo "\033[36m----Compiling libft and get_next_line----"
			@make -C ./libft
			$(CC) $(B_OBJECTS) -Llibft -lft -o ${NAME}
			touch .bonus
			@echo "Pipex Bonus Compiled!\n"

clean:
			@make clean -C ./libft
			@rm -f ${OBJECTS} ${B_OBJECTS}
			rm -f .bonus

fclean:		clean
			@echo "\033[31mDeleting EVERYTHING\n"
			@make fclean -C ./libft
			@rm -f ${NAME}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re bonus re_bonus
