NAME = codexion
CC = cc
SRC =	time.c \
		parsing_input.c

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