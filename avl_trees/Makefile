# ====== Build (projet) ======
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -pedantic -I .
NAME    = 0-is_avl
SRCS    = binary_tree_node.c binary_tree_print.c 0-binary_tree_is_avl.c 0-main.c
OBJS    = $(SRCS:.c=.o)

# ====== Tests (sans Criterion) ======
TEST_BIN        = tests/test_runner
TEST_SRCS       = tests/test_runner.c binary_tree_node.c 0-binary_tree_is_avl.c
TEST_OBJS       = $(TEST_SRCS:.c=.o)

.PHONY: all clean fclean re run test

# ---- binaire de démo ----
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c binary_trees.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

# ---- tests sans framework externe ----
test: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST_BIN)
	./$(TEST_BIN)

tests/test_runner.o: tests/test_runner.c binary_trees.h
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_BIN)

re: fclean all
