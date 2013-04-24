//set number of threads dynamically using num_threads
#include<stdio.h>
#include<omp.h>
int main(int argc,char *argv[])
{
	int tid,n;
	if(argc!=2)
	{
		printf("Syntax: %s <num_threds>\n",argv[0]);
		return 1;
	}
	n=0;
	int i;
	for(i=0;argv[1][i]!=0;i++)
	{
		if(argv[1][i]>='0'&&argv[1][i]<='9')
		{
			n=n*10+(argv[1][i]-48);
		}
		else
		{
			printf("Invalid number of threads\n");
			return 1;
		}
	}
	#pragma omp parallel private(tid) num_threads(n)
	{
		tid=omp_get_thread_num();
		printf("Hello from thread %d\n",tid);
		if(tid==0)
		{
			n=omp_get_num_threads();
			printf("Number of threads %d\n",n);
		}
	}
	return 0;
}
		 
