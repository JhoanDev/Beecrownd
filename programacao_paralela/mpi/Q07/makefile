EXEC = main
SRC = calculate_pi_mpi.c
MPICC = mpicc
CFLAGS = -Wall -O2

all: $(EXEC)

$(EXEC): $(SRC)
	$(MPICC) $(CFLAGS) -o $(EXEC) $(SRC)

# Limpa os arquivos gerados
clean:
	rm -f $(EXEC)
