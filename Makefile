##
## EPITECH PROJECT, 2022
## bs paint
## File description:
## Makefile
##

SRC = 	$(wildcard src/*.c)\
		$(wildcard src/load/*.c)\
		$(wildcard src/inventory/*.c)\
		$(wildcard lopotipoucet/*.c)\
		$(wildcard src/window_gestion/*.c)\
		$(wildcard src/init/*.c)\
		$(wildcard src/loader/*.c) \
		$(wildcard src/colision/*.c)\
		$(wildcard src/xp/*.c)\
		$(wildcard src/pause/*.c)\
		$(wildcard src/dialogue/*.c) \
		$(wildcard chaperon/*.c)\
		$(wildcard petit_cochon/*.c)\

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -g3 -I./include/

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

TARGET = my_rpg

all : $(TARGET)
	make clean

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re : fclean all
