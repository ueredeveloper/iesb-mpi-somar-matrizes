  #include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  // tamanho do processo e rank
  int size, rank;
  MPI_Status st;
  /* processo envia valores para cada um dos processos...

    */
  int valorInicial, valorModificado, total, nproc;

  // INICIAR
  MPI_Init(&argc, &argv);
  // descobrir quantos processos foram disparados
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  // saber o id de cada processo
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // printf("Hello world mpi, processo: %d, de um total de: %d \n", rank, size);
  // fflush(stdout);
  // processo mestre

  int a1[] = {1, 2, 3};
  int a2[] = {3, 4, 5};
  int a3[3];
  int tag = 1;

  if (rank == 0) {
   
    MPI_Send(a1, 3, MPI_INT, 1, tag, MPI_COMM_WORLD);

    MPI_Recv(a3, 3, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &st);

    for (int i = 0; i < 3; i++) {
      printf(" mestre recebe a3, posição %d = %d \n", i, a3[i]);
    }

  } else {
    MPI_Recv(a1, 3, MPI_INT, 0, tag, MPI_COMM_WORLD, &st);

    for (int i = 0; i < 3; i++) {
      a3[i] = a1[i] + a2[i];
      printf(" escravo soma e envia a1 %d somado a a2 %d = a3 = %d\n", a1[i], a2[i], a3[i]);
    }
    MPI_Send(a3, 3, MPI_INT, 0, 1, MPI_COMM_WORLD);
  }

  /*
  if (rank == 0) {
    for (nproc = 1; nproc < size; nproc++) {
      valorInicial = nproc * 10;
      MPI_Send(&valorInicial, 1, MPI_INT, nproc, 0, MPI_COMM_WORLD);
      printf("Mestre - Enviei %d para Proc %d \n", valorInicial, nproc);
      fflush(stdout);
    }

    for (nproc = 1; nproc < size; nproc++) {
      MPI_Recv(&valorModificado, 1, MPI_INT, MPI_ANY_SOURCE,
  MPI_ANY_TAG,MPI_COMM_WORLD, &st); printf("Mestre - valor modificado recebido
  %d \n", valorModificado);
    }
  }
  // processo escravo
  else {
    MPI_Recv(&valorInicial, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
    printf("Escravo %d - Recebi %d do mestre \n", rank, valorInicial);
    fflush(stdout);
    // enviar valor multiplicado por 10
    valorModificado = valorInicial * 10;

    MPI_Send(&valorModificado, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
  }
  */

  MPI_Finalize();
  return 0;
}