CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -pedantic
TARGET  := 0-heap_extract

# Sources communes (ton main de test + ton code + le printer)
SRC_BASE := 0-main.c 0-heap_extract.c binary_tree_print.c

# Auto-détection : lib fournie ou helpers locaux
ifeq ($(wildcard libheap.a),libheap.a)
  USE_LIB := 1
endif
ifeq ($(wildcard helpers_for_local_test.c),helpers_for_local_test.c)
  HAVE_HELPERS := 1
endif

# Choix des sources / libs en fonction de ce qui est dispo
ifeq ($(USE_LIB),1)
  SRC  := $(SRC_BASE)
  LDLIBS := ./libheap.a
else ifeq ($(HAVE_HELPERS),1)
  SRC  := $(SRC_BASE) helpers_for_local_test.c
  LDLIBS :=
else
  $(error Ni libheap.a ni helpers_for_local_test.c trouvés. \
Ajoute l’un des deux pour compiler.)
endif

OBJS := $(SRC:.c=.o)
DEPS := binary_trees.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind ./$(TARGET)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all run valgrind clean fclean re
