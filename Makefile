CC = gcc
SRC = *.c
NAME = hsh
FLAGS = -Wall -Werror -Wextra -pedantic
VAL = valgrind
VALFLAGS = --track-origins=yes --leak-check=full --show-leak-kinds=all -s


all:
	$(CC) $(SRC) $(FLAGS) -g -o $(NAME)
run:
	./$(NAME)
mario:
	$(VAL) $(VALFLAGS) ./$(NAME)

