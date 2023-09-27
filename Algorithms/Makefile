CC = gcc
override CFLAGS += -Wall -Wextra -g
MAIN = client.c

SORT_ALGORITHMS = $(wildcard *_sort)

all: main

main: $(MAIN) $(SORT_ALGORITHMS)
	@echo "Você deve especificar um algoritmo de ordenação, como 'make quick_sort'."

%_sort: %_sort.c
	$(CC) $(CFLAGS) -o main $^ $(MAIN)

clean:
	rm -f main