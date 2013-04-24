#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
	int a[100];
	int i,rank,sum=0,size;
//	MPI_Status status;
	for(i=0;i<100;i++)
		a[i]=i;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0)
	{
		MPI_Status status;
		int n;
		printf("Number of procesess %d\n",size);
		printf("Enter number of terms\n");
		scanf("%d",&n);
		for(i=1;i<size;i++)
			MPI_Send(&n,1,MPI_INT,i,i,MPI_COMM_WORLD);
		for(i=rank;i<n;i+=size)
			sum+=a[i];
		printf("Sum from process %d is %d\n",rank,sum);
		int tmp;
		for(i=1;i<size;i++)
		{
			printf("Waiting for sum from process %d ...\n",i);
			MPI_Recv(&tmp,1,MPI_INT,i,i,MPI_COMM_WORLD,&status);
			printf("Sum of process %d is %d\n",i,tmp);
			sum+=tmp;
		}
		
		printf("Total sum = %d\n",sum);
	}
	else
	{
		MPI_Status status;	
		int n;
		int tmp=0;
		//printf("on process %d\n",rank);
		MPI_Recv(&n,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
		//printf("Received value\n");
		for(i=rank;i<n;i+=size)
			tmp+=a[i];
		//printf("Summation completed\n");
		MPI_Send(&tmp,1,MPI_INT,0,rank,MPI_COMM_WORLD);
		//printf("Sum sent\n");
		
	}
	MPI_Finalize();
	return 0;
}
