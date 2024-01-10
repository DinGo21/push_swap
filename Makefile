NAME = push_swap
LIB = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c utils.c parse.c swap.c rotate.c rrotate.c push.c sorts.c radix.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	gcc $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : 
	make -C libft bonus

clean :
	@make -C libft clean
	@rm -rf $(OBJ)

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all