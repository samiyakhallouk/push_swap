NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
SRC = helper_list.c helper.c helper1.c moves.c parsing.c pivotesorting.c push_swap.c split.c
BSRC = checker.c applymoves.c helper_list.c helper.c helper1.c moves.c parsing.c pivotesorting.c split.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
HEAD = push_swap.h
RM = rm -f

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
bonus : $(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

clean:
	$(RM) $(OBJ)

bonus_clean:
	rm -f $(BOBJ)
	
fclean: clean bonus_clean
	rm -f $(BNAME)
	rm -f $(NAME)

re: fclean all