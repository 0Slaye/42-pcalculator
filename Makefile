NAME = exec
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm
SRC = ./srcs/pcalculator.c
INCL = ./includes
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lm

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCL)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re