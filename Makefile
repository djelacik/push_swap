# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:59:53 by djelacik          #+#    #+#              #
#    Updated: 2024/08/12 15:47:52 by djelacik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

NAME_PS		= push_swap
NAME_CH		= checker

SOURCE_PS     = \
	src/push_swap.c \
	src/initialize.c \
	src/push.c \
	src/rotate.c \
	src/swap.c \
	src/reverse_rotate.c \
	src/ps_utils.c \
	src/ps_utils2.c \
	src/algorithm_utils.c \
	src/set_costs.c \
	src/super_algo.c 
	
SOURCE_CH     = \
	src/initialize.c \
	src/push.c \
	src/rotate.c \
	src/swap.c \
	src/reverse_rotate.c \
	src/ps_utils.c \
	src/ps_utils2.c \
	src/algorithm_utils.c \
	src/set_costs.c \
	src/super_algo.c \
	src/exec_instructions.c \
	src/checker.c \
	src/hidden_swap_push.c \
	src/hidden_rotate.c \
	src/hidden_reverse.c 
	
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
			@make fclean -C ./get_next_line
			@rm -f ${NAME_PS} ${NAME_CH}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re bonus re_bonus
