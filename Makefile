NAME = libftprintf.a
MAIN = main.c
EXE = exe.out
SRC = sources/ft_printf.c
OBJECTS = *.o
HEADERS = includes/ft_printf.h

all: $(NAME)

$(NAME):
	@cc -Wall -Wextra -Werror -I $(HEADERS) -c $(SRC)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Ft_printf is now compiled, good sir!"

run:
	@gcc -Wall -Wextra -Werror $(MAIN) $(NAME) -o $(EXE)
	@./$(EXE)

clean: $(OBJECTS)
	@/bin/rm -f $(OBJECTS)
	@echo "I wiped the object files under the carpet for you!"

fclean: clean
	@/bin/rm -f $(NAME) $(EXE)
	@echo "...and the library and executable are in the trash!"

re: fclean all
.PHONY: all