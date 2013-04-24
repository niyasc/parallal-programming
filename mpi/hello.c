#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0)
	{
		printf("I'm the master and my rank is %d\n",rank);
	}
	else
	{
		printf("I'm the slave and my rank is %d\n",rank);
	}
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("Group size = %d\n",size);
	MPI_Finalize();
}
