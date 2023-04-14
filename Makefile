CC = gcc
SRC = *.c
NAME = hsh
FLAGS = -Wall -Werror -Wextra -pedantic

all:
	$(CC) $(SRC) $(FLAGS) -o $(NAME)
run:
	./$(NAME)
