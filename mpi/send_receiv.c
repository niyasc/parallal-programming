#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
	int rank;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0)
	{
		int x=10;
		printf("Process %d\n",rank);
		printf("x initialized with 10\n");
		MPI_Send(&x,1,MPI_INT,1,2,MPI_COMM_WORLD);
	}
	if(rank==1)
	{
		int x;
		MPI_Recv(&x,1,MPI_INT,0,2,MPI_COMM_WORLD,&status);
		printf("Process %d\n",rank);
		printf("x received and value is %d\n",x);
	}
	MPI_Finalize();
	return 0; 
}
