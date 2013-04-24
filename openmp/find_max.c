//demonstration of omp critical
#include<stdio.h>
#include<omp.h>

int main(int argc,char *argv[])
{
	int a[100],localmax,max=0,i;
	#pragma omp parallel private(i,localmax) shared(a,max)
	{
		int tid=omp_get_thread_num();
		#pragma omp for
		for(i=0;i<100;i++)
		{
			a[i]=random()%100;
		}
		localmax=0;
		#pragma omp for
		for(i=0;i<100;i++)
		{
			if(a[i]>localmax)
				localmax=a[i];
		}
		printf("Local maximum of thread %d is %d\n",tid,localmax);
		#pragma omp critical
			if(localmax>max)
				max=localmax;
	}
	printf("Maximum is %d\n",max);
	return 0;
}
