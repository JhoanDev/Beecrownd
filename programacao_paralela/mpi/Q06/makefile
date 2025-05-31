EXEC = main
SRC = histogram_mpi.c
MPICC = mpicc
CFLAGS = -Wall -O2 

all: $(EXEC)

$(EXEC): $(SRC)
	$(MPICC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC)
