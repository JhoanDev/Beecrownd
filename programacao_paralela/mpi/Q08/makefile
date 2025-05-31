EXEC = main
SRC = arvore.c
MPICC = mpicc
CFLAGS = -Wall -O2

all: $(EXEC)

$(EXEC): $(SRC)
	$(MPICC) $(CFLAGS) -o $(EXEC) $(SRC) -lm
clean:
	rm -f $(EXEC)
