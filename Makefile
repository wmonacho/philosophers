NAME =		philosophers

CFLAGS =	-Wall -Wextra -Werror -I .

SFLAGS =	-fsanitize=address -g

CC =		gcc

OBJS_DIR = .objs

OBJ =	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

FILES = philosophers.c									\
		init.c											\
		parsing.c										\
		ft_atoi.c										\
		ft_putstr_fd.c									\
		free.c											\

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SFLAG) $(OBJ) -o $(NAME)
	
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