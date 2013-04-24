#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
	int sum=0,tmp,size,n,rank,i;
	int a[100];
	n=100;
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	tmp=0;
	for(i=rank;i<n;i+=size)
		tmp+=a[i];
	MPI_Reduce(&tmp,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	MPI_Finalize();
	if(rank==0)
		printf("Sum is %d\n",sum);
	return 0;
}
