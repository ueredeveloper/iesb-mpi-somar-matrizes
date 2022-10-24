#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
  // tamanho do processo e rank
  int size, rank;
  
  MPI_Init(&argc, &argv);
  // descobrir quantos processos foram disparados
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  // saber o id de cada processo
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  printf("Hello world mpi, processo: %d, de um total de: %d \n", rank, size);
  fflush(stdout);
  
  MPI_Finalize();
  return 0;
}