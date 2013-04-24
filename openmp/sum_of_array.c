#include<omp.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	int a[100],tid,i,n,sum=0;
	for(i=0;i<100;i++)
		a[i]=i;
	#pragma omp parallel private(tid,i) num_threads(2)
	{
		tid=omp_get_thread_num();
		#pragma omp for reduction(+:sum) schedule(static,50)
			for(i=0;i<100;i++)
			{
				sum+=a[i];
				if(i==49)
				{
					printf("I'm thread %d sum %d\n",tid,sum);
				}
				else if(i==99)
				{
					printf("I'm thread %d sum %d\n",tid,sum);
				}
			}
	}
	printf("Total sum = %d\n",sum);
	return 0;
}
