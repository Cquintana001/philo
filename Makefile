NAME				=	philo

libft				= 	libft
INC_DIR				= 	./includes/
CC 					= 	gcc
CFLAGS 				= 	-Wall -Werror -Wextra  
SRC_DIR				=	src
SOURCES				=	$(SRC_DIR)/precise_sleep.c \
						$(SRC_DIR)/philo.c \
						$(SRC_DIR)/check_error.c \
						$(SRC_DIR)/fill_data.c \
						$(SRC_DIR)/find_min.c 
OBJS				= 	$(SOURCES:.c=.o)


 

$(NAME): $(OBJS)
	make -C $(libft)
	$(CC) $(CFLAGS) $(OBJS) $(libft)/libft.a -o $(NAME) 

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

all: $(NAME)

fclean : clean
	make fclean -C $(libft)
clean:
	rm -f $(OBJS) $(NAME) 

re: fclean all	 

.PHONY: all