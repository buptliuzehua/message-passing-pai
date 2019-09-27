#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 840

int main(void)
{
  MPI_Init(NULL, NULL);

  MPI_Status status;

  int size, rank, len;

  char message[100];

  char name[MPI_MAX_PROCESSOR_NAME];

  MPI_Comm_size(MPI_COMM_WORLD,&size);

  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  MPI_Get_processor_name(name, &len);

  int num_in_each_pro = N/size;

  int count = 1;

  double tstart, tstop;

  double sum_in_each_pro = 0;

  MPI_Barrier(MPI_COMM_WORLD);

  tstart = MPI_Wtime();

  while(count<=num_in_each_pro){


    sum_in_each_pro+=1/(1+((count-0.5)/num_in_each_pro)*((count-0.5)/num_in_each_pro));

    count++;

  }

  double result = 4*sum_in_each_pro/num_in_each_pro;

  MPI_Barrier(MPI_COMM_WORLD);

  tstop = MPI_Wtime();

  printf("%f, %f\n", result,tstop-tstart);

  MPI_Finalize();
}
