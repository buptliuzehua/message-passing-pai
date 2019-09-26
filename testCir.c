include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int getLength(int a[]){
        int n = 0;
        while(a[n] != '\0') n++;  //'\0'=>表示的是数组存放元素结束的标志
        return n;
}
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

  if(rank!=0){

    char send_message[13] = "Hello World!\n"

    printf("this is from process from %s \n", name);

    //strcpy(message, "Hello World!\n");

    MPI_Send(&send_message,getLength(send_message)+1,MPI_CHAR,0,99,MPI_COMM_WORLD);
  }else{

    int count = 1;

    while(count < size) {

      MPI_Recv(&message,100,MPI_CHAR,i,99,MPI_COMM_WORLD,&status);

      printf("Hello World!this is from process %d \n", i);

      count++;
    }
  }

  MPI_Finalize();
}
