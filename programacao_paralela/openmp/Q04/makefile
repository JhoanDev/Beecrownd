CC = gcc
CFLAGS = -Wall -fopenmp -g -lm
SRC = my_linear_system.c

all: main

main: $(SRC)
	@if [ -z "$(SRC)" ]; then \
		echo "Erro: use make SRC=arquivo.c"; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) $(SRC) -o main

.PHONY: all main
