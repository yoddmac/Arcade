CC	=	g++

RM	=	rm -rf

NAME	=	my_snake

CFLAGS	=	-W -Wall -Wextra

CFLAGS	=	-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window -lncurses

SRC	=	snake.cpp

OBJ	=$(SRC:.cpp=.o)

all: compil

compil: $(SRC)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

valgrind: $(SRC)
	$(CC) -g -o $(NAME) $(SRC) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: re all clean fclean