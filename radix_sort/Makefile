CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g
SRC = 0-main.c 0-radix_sort.c print_array.c
OUT = radix

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

valgrind: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(OUT)

clean:
	rm -f $(OUT)
