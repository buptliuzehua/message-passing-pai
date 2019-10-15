#include <stdio.h>
#include <stdlib.h>

#include <mpi.h>
#define N 100000000
#define LOOP 10
static double message1[N];
static double message2[N];
static double message_recv1[N];
static double message_recv2[N];
int main(void)
{
  int rank,size;
  double tstart, tstop;
  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Status status;
  int i,count;
  for(i=0;i<N;i++)
        message1[i]=1.0;
  for(i=0;i<N;i++)
        message2[i]=2.0;
  count = 0;
  tstart = MPI_Wtime();
  if(rank==0){
    while (count<LOOP) {
      MPI_Ssend(&message1,N, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
      MPI_Recv(&message_recv1, N, MPI_CHAR, 1, 0, MPI_COMM_WORLD,&status);
      count++;
    }
  }else if(rank==1){
      while (count<LOOP) {
        MPI_Recv(&message_recv2, N, MPI_CHAR, 0, 0, MPI_COMM_WORLD,&status);
        MPI_Ssend(&message2,N, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        count++;
      }
  }
  tstop = MPI_Wtime();
  printf("Receive and send %d bytes cost %f time\n", LOOP*2*8*N, (tstop-tstart));
  MPI_Finalize();
  return 0;
}
