CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -pedantic
SRC     = 0-merge_sort.c print_array.c
HDR     = sort.h

# binaries
DEMO    = demo
TESTBIN = tests_runner

.PHONY: all clean fclean re test demo betty check-o ltracecheck

all: $(DEMO)

$(DEMO): tests/demo_main.c $(SRC) $(HDR)
	$(CC) $(CFLAGS) tests/demo_main.c $(SRC) -o $(DEMO)

$(TESTBIN): tests/test_merge_sort.c $(SRC) $(HDR)
	$(CC) $(CFLAGS) tests/test_merge_sort.c $(SRC) -o $(TESTBIN)

demo: $(DEMO)
	./$(DEMO)

test: $(TESTBIN)
	./$(TESTBIN)

# best-effort: vérif du contenu exact du fichier 0-O
check-o:
	@grep -qx 'O(nlog(n))' 0-O || (echo "0-O: ligne 1 invalide" && exit 1)
	@sed -n '2p' 0-O | grep -qx 'O(nlog(n))' || (echo "0-O: ligne 2 invalide" && exit 1)
	@sed -n '3p' 0-O | grep -qx 'O(nlog(n))' || (echo "0-O: ligne 3 invalide" && exit 1)
	@[ $$(wc -l < 0-O) -eq 3 ] || (echo "0-O: doit contenir exactement 3 lignes" && exit 1)
	@echo "0-O OK"

# best-effort: compter malloc/free avec ltrace (si dispo)
ltracecheck: $(TESTBIN)
	@if command -v ltrace >/dev/null 2>&1; then \
	  echo "Running ltrace (best-effort)…"; \
	  ltrace -e malloc,free -o ltrace.log ./$(TESTBIN) >/dev/null 2>&1 || true; \
	  echo "Sample (first 10 lines):"; head -n 10 ltrace.log || true; \
	else \
	  echo "ltrace non disponible — étape ignorée."; \
	fi

betty:
	@if [ ! -d Betty ]; then git clone --depth=1 https://github.com/holbertonschool/Betty.git; fi
	@cd Betty && sudo ./install.sh >/dev/null 2>&1 || true
	@betty 0-merge_sort.c $(HDR)

clean:
	$(RM) $(DEMO) $(TESTBIN) ltrace.log

fclean: clean
	@rm -rf Betty

re: fclean all
