# Makefile

NAME = Sokoban

SRCS = main.c \
		coup.c\
		grille.c\
		sokoban.h\

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all