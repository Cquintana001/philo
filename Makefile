NAME				=	philo

INC_DIR				= 	./includes/
CC 					= 	gcc
CFLAGS 				= 	-Wall -Werror -Wextra
SRC_DIR				=	src
SOURCES				=	$(SRC_DIR)/precise_sleep.c \
						$(SRC_DIR)/philo.c

OBJS				= 	$(SOURCES:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INC_DIR) -o $(NAME) 

all: $(NAME)

fclean : clean

clean:
	rm -f $(OBJS) $(NAME) 

re: fclean all	 

.PHONY: all