#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 840
double calPai(int start, int end){
  double partial_res = 0;
  int count = 0;
  while (count<1000) {
    while (start<=end) {
      partial_res+=1/(1+((start-0.5)/N)*((start-0.5)/N));
      start++;
    }
  }
  return partial_res/1000;
}
double final_deal_pai(double pre_result, int pro_num){
  return 4*pre_result/pro_num;
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

  int num_in_each_pro = N/size;

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
    printf("%d\n", sum_in_each_pro);
    MPI_Ssend(&sum_in_each_pro,1,MPI_DOUBLE,0,MPI_ANY_TAG,comm);
  }else{
    for(recv_count=1;recv_count<size;recv_count++){
      MPI_Recv(&temp, 1, MPI_DOUBLE, recv_count, MPI_ANY_TAG,comm, MPI_Status * status);
      result+=temp;
    }
    result = final_deal_pai(result,num_in_each_pro);
    printf("%f\n", result);
    MPI_Barrier(MPI_COMM_WORLD);

    tstop = MPI_Wtime();

    printf("%f, %f\n", result,tstop-tstart);
  }
  MPI_Finalize();
}
