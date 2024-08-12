# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:59:53 by djelacik          #+#    #+#              #
#    Updated: 2024/08/10 15:18:55 by djelacik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

NAME_PS		= push_swap
NAME_CH		= checker

SOURCE_PS     = \
	push_swap.c \
	initialize.c \
	push.c \
	rotate.c \
	swap.c \
	reverse_rotate.c \
	ps_utils.c \
	ps_utils2.c \
	algorithm_utils.c \
	set_costs.c \
	super_algo.c \
	
SOURCE_CH     = \
	initialize.c \
	push.c \
	rotate.c \
	swap.c \
	reverse_rotate.c \
	ps_utils.c \
	ps_utils2.c \
	algorithm_utils.c \
	set_costs.c \
	super_algo.c \
	exec_instructions.c \
	checker.c \
	hidden_swap_push.c \
	hidden_rotate.c \
	hidden_reverse.c 
	
	
OBJECTS_PS     = ${SOURCE_PS:.c=.o}

OBJECTS_CH		= ${SOURCE_CH:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all:		${NAME_PS} ${NAME_CH}

${NAME_PS}:	${OBJECTS_PS}
			@echo "\033[35m----Compiling libft and get_next_line----"
			@make -C ./libft
			@make -C ./get_next_line
			$(CC) $(OBJECTS_PS) -Llibft -lft -Lget_next_line -lgetnextline -o ${NAME_PS}
			@echo "Push_swap Compiled!\n"
			
${NAME_CH}:	${OBJECTS_CH}
			@echo "\033[35m----Compiling libft and get_next_line----"
			@make -C ./libft
			@make -C ./get_next_line
			$(CC) $(OBJECTS_CH) -Llibft -lft -Lget_next_line -lgetnextline -o ${NAME_CH}
			@echo "Push_swap Compiled!\n"
			
bonus:		${NAME_CH}

.bonus:		${OBJECTS_CH}
			@echo "\033[36m----Compiling libft and get_next_line----"
			@make -C ./libft
			@make -C ./get_next_line
			$(CC) $(OBJECTS_CH) -Llibft -lft -Lget_next_line -lgetnextline -o ${NAME_CH}
			touch .bonus
			@echo "Push_swap Bonus Compiled!\n"

clean:
			@make clean -C ./libft
			@rm -f ${OBJECTS_PS} ${OBJECTS_CH}
			rm -f .bonus

fclean:		clean
			@echo "\033[31mDeleting EVERYTHING\n"
			@make fclean -C ./libft
			@rm -f ${NAME_PS} ${NAME_CH}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re bonus re_bonus
