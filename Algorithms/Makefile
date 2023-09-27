CC = gcc
override CFLAGS += -Wall -Wextra -g
MAIN = client.c

SORT_ALGORITHMS = $(wildcard *_sort.c)

all: $(SORT_ALGORITHMS)

%_sort: %_sort.c
	$(CC) $(CFLAGS) -o $(patsubst %_sort,%,$@) $^ $(MAIN)

clean:
	rm -f $(SORT_ALGORITHMS:%_sort=%)