CC = gcc
CFLAGS = -Wall -fopenmp

# Adiciona .c ao SRC, se não for passado
SRC ?= calculate_pi.c

all: main

main: $(SRC)
	@if [ -z "$(SRC)" ]; then \
		echo "Erro: use make SRC=arquivo.c"; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) $(SRC) -o main

.PHONY: all main
