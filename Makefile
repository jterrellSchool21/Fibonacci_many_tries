SRC=Fibonacci_solve.c
NAME=main

all:$(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)

fclean:
	/bin/rm -f $(NAME)

re: fclean re
