NAME = codexion
CC = cc
SRC =	time.c \
		parsing_input.c \
		coders.c \
		utils.c \
		codexion.c \
		init_threads.c \
		coder_routine.c

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.out

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re