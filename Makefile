NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = ./Mandatory/helper_list.c ./Mandatory/helper.c ./Mandatory/helper1.c\
		./Mandatory/moves.c ./Mandatory/parsing.c ./Mandatory/pivotesorting.c\
		./Mandatory/push_swap.c ./Mandatory/split.c

BSRC = ./Bonus/checker.c ./Bonus/applymoves_bonus.c ./Bonus/helper_list_bonus.c\
		./Bonus/helper_bonus.c ./Bonus/helper1_bonus.c ./Bonus/moves_bonus.c\
		./Bonus/parsing_bonus.c ./Bonus/split_bonus.c ./Bonus/gnl_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

HEAD = ./Mandatory/push_swap.h
BHEAD = ./Bonus/push_swap_bonus.h
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
bonus : $(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

Mandatory/%.o: Mandatory/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

%bonus.o: %bonus.c $(BHEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)
	
fclean: clean
	$(RM) $(BNAME)
	$(RM) $(NAME)

re: fclean all