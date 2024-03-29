#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 8400000
double calPai(int start, int end){
  double partial_res = 0;
  int restart = start;
  int count = 0;
    while (start<=end) {
      partial_res+=1/(1+((start-0.5)/N)*((start-0.5)/N));
      start++;
    }
  return partial_res;
}
double final_deal_pai(double pre_result, int pro_num){
  return 4*pre_result/N;
}
int main(void)
{
  MPI_Init(NULL, NULL);

  MPI_Status status;

  int size, rank, len,pro_start,pro_end;

  char message[100];

  char name[MPI_MAX_PROCESSOR_NAME];

  MPI_Comm comm;

  comm = MPI_COMM_WORLD;

  MPI_Comm_size(comm,&size);

  MPI_Comm_rank(comm,&rank);

  MPI_Get_processor_name(name, &len);

  int num_in_each_pro = N/(size-1);//因为0进程不参与计算，所以分size-1次

  int count = 1;

  double tstart, tstop;

  double sum_in_each_pro = 0;
  double result = 0;
  double temp = 0;
  int recv_count=1;
  MPI_Barrier(MPI_COMM_WORLD);

  tstart = MPI_Wtime();
  if(rank!=0){
    pro_start = (rank-1)*num_in_each_pro+1;
    pro_end = rank*num_in_each_pro;
    sum_in_each_pro=calPai(pro_start,pro_end);
    //printf("%d\n", sum_in_each_pro);
    MPI_Ssend(&sum_in_each_pro,1,MPI_DOUBLE,0,MPI_ANY_TAG,comm);
  }else{
    for(recv_count=1;recv_count<size;recv_count++){
      MPI_Recv(&temp, 1, MPI_DOUBLE, recv_count, MPI_ANY_TAG,comm, &status);
      result+=temp;
      //printf("%f\n", result);
    }
    result = final_deal_pai(result,num_in_each_pro);
    //printf("%f\n", result);
    MPI_Barrier(MPI_COMM_WORLD);

    tstop = MPI_Wtime();
    printf("%f, %f\n", result/(size-1),tstop-tstart);
  }
  MPI_Finalize();
}
