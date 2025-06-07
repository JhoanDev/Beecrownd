EXEC = main
SRC = anel.c
MPICC = mpicc
CFLAGS = -Wall

all: $(EXEC)

$(EXEC): $(SRC)
	$(MPICC) $(CFLAGS) -o $(EXEC) $(SRC) -lm
clean:
	rm -f $(EXEC)
