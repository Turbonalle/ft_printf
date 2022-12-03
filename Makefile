NAME = libftprintf.a
MAIN = main.c
EXE = exe.out
SRC = ft_printf.c ft_printf_utils.c
OBJECTS = *.o
HEADER = ft_printf.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cc -I $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Ft_printf is now compiled, good sir!"

run:
	@gcc $(MAIN) $(NAME) -o $(EXE)
	@./$(EXE)

clean: $(OBJECTS)
	@/bin/rm -f $(OBJECTS)
	@echo "I wiped the object files under the carpet for you!"

fclean: clean
	@/bin/rm -f $(NAME) $(EXE)
	@echo "...and the library and executable are in the trash!"

re: fclean all
.PHONY: all