NAME				=	philo

INC_DIR				= 	./includes/
CC 					= 	gcc
CFLAGS 				= 	-Wall -Werror -Wextra
SRC_DIR				=	src
SOURCES				=	$(SRC_DIR)/precise_sleep.c \
						$(SRC_DIR)/philo.c \

OBJS				= 	$(SOURCES:.c=.o)


 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

all: $(NAME)

fclean : clean

clean:
	rm -f $(OBJS) $(NAME) 

re: fclean all	 

.PHONY: all