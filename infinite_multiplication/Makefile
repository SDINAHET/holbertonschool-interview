# =========================
#  Infinite Multiplication
# =========================

CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -pedantic
NAME    := mul
SRC     := 0-mul.c _putchar.c
OBJ     := $(SRC:.c=.o)
HEADERS := mul.h

.PHONY: all clean fclean re betty run

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# Vérification du style/documentation Betty (si installée)
betty:
	@betty-style.pl $(SRC) $(HEADERS) || true
	@betty-doc.pl   $(SRC)            || true

# Petit raccourci pour tester rapidement (ex: make run ARGS="10 98")
run: $(NAME)
	@./$(NAME) $(ARGS)
