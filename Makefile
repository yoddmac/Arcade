##
## EPITECH PROJECT, 2021
## B-PSU-400-NCY-4-1-nmobjdump-thomas.terosiet
## File description:
## Makefile
##

NAME_ARCADE			= arcade

NAME_LIBSFML		= ./lib/arcade_sfml.so

NAME_NCURSES        = ./lib/arcade_ncurses.so

NAME_LIBSDL 		= ./lib/arcade_sdl2.so

NAME_NIBBLE			= ./lib/arcade_nibbler.so

CC 				= g++

RM				= rm -f

SCR_ARCADE			= src/arcade.cpp \
					  include/encapsulation_dll.cpp\
                      main.cpp

SRC_LIBSFML  		= sfml/Sfml.cpp

SRC_NCURSES         = Ncurses/Ncurses.cpp

SRC_LIBSDL  		= Sdl/Sdl.cpp

SRC_NIBBLE  		= Games/Snake.cpp

CXXFLAGS += -W -Wall -Wextra -g
CXXFLAGS += -I includes -std=c++17 -fpic

OBJS_ARCADE		= $(SCR_ARCADE:.cpp=.o)

OBJS_LIBSFML	= $(SRC_LIBSFML:.cpp=.o)

OBJS_NCURSES	= $(SRC_NCURSES:.cpp=.o)

OBJS_LIBSDL		= $(SRC_LIBSDL:.cpp=.o)

OBJS_NIBBLE		= $(SRC_NIBBLE:.cpp=.o)


all: arcade libsfml ncurses libsdl nibble

graphicals : libsfml ncurses libsdl

core : arcade

games : nibble

arcade : $(NAME_ARCADE)

libsfml : $(NAME_LIBSFML)

libsdl : $(NAME_LIBSDL)

ncurses: $(NAME_NCURSES)

nibble : $(NAME_NIBBLE);

$(NAME_ARCADE):	$(OBJS_ARCADE)
			$(CC) $(OBJS_ARCADE) -o $(NAME_ARCADE) $(LDFLAGS) -ldl

$(NAME_LIBSFML): $(OBJS_LIBSFML)
			$(CC) -shared -o $(NAME_LIBSFML) $(OBJS_LIBSFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME_LIBSDL): $(OBJS_LIBSDL)
			$(CC) -shared -o $(NAME_LIBSDL) $(OBJS_LIBSDL) -lSDL2 -lSDL2_ttf -lSDL2_image
$(NAME_NCURSES): $(OBJS_NCURSES)
			$(CC) -shared -o $(NAME_NCURSES) $(OBJS_NCURSES) -lncurses
$(NAME_NIBBLE): $(OBJS_NIBBLE)
			$(CC) -shared -o $(NAME_NIBBLE) $(OBJS_NIBBLE)

clean:
	$(RM) $(OBJS_ARCADE)
	$(RM) $(OBJS_LIBSFML)
	$(RM) $(OBJS_NCURSES)
	$(RM) $(OBJS_LIBSDL)
	$(RM) $(OBJS_NIBBLE)

fclean: clean
	$(RM) $(NAME_ARCADE)
	$(RM) ./lib/$(NAME_LIBSFML)
	$(RM) ./lib/$(NAME_NCURSES)
	$(RM) ./lib/$(NAME_LIBSDL)
	$(RM) ./lib/$(NAME_NIBBLE)

re: fclean all

.PHONY: all clean fclean re
