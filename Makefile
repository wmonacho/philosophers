# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmonacho <wmonacho@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 14:03:24 by wmonacho          #+#    #+#              #
#    Updated: 2022/08/23 14:03:24 by wmonacho         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =		philosophers

CFLAGS =	-Wall -Wextra -Werror -I .

SFLAGS =	-fsanitize=thread -g

CC =		gcc

OBJS_DIR = .objs

OBJ =	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

FILES = philosophers.c									\
		init.c											\
		parsing.c										\
		ft_atoi.c										\
		ft_putstr_fd.c									\
		free.c											\
		routine.c										\
		check.c											\
		utils.c											\

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SFLAGS) -pthread $(OBJ) -o $(NAME)
	
$(OBJS_DIR)/%.o:		%.c philosophers.h Makefile | $(OBJS_DIR)
				${CC} ${CFLAGS} -c $< -o $@

$(OBJS_DIR):			
				mkdir $(OBJS_DIR)

clean :
				rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o 

fclean :
				rm -f ${OBJ} ${OBJ_B} $(OBJS_DIR)/*.o
				rm -f ${NAME}
				rm -rf $(OBJS_DIR)

re :			fclean all

.PHONY:			all clean fclean re