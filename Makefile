NAME = libftprintf.a
SRC = sources/*.c libft/*.c
OBJECTS = *.o
HEADERS = includes/*.h libft/*.h

.PHONY: all
all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -I $(HEADERS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all