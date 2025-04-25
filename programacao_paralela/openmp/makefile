# Compilador e flags
CC = gcc
CFLAGS = -Wall -O2 -fopenmp

# Nome do programa fonte passado como variável: p=arquivo.c
# Ex: make p=q1.c
.PHONY: all

all:
ifndef p
	$(error Você precisa passar o nome do arquivo. Ex: make p=arquivo.c)
endif
	$(CC) $(CFLAGS) -o main $(p)

