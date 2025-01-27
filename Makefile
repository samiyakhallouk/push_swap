NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
SRC = helper_list.c helper.c helper1.c moves.c parsing.c pivotesorting.c push_swap.c split.c 
OBJ = $(SRC:.c=.o)
HEAD = push_swap.h
RM = rm -f

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all