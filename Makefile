NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRC = $(wildcard ft_*.c) 
OBJ = $(SRC:.c=.o)

$(NAME): 
			$(CC) $(CFLAAGS) -c $(SRC)
			$(AR) $(NAME) $(OBJ)
			ranlib $(NAME)

all: $(NAME)


clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean