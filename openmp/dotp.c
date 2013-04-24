//demonstration of omp critical
#include<stdio.h>
#include<omp.h>

int main(int argc,char *argv[])
{
	int a[100],b[100],localsum,sum=0,i;
	#pragma omp parallel private(i,localsum) shared(a,b,sum)
	{
		int tid=omp_get_thread_num();
		#pragma omp for
		for(i=0;i<100;i++)
		{
			a[i]=i;
			b[i]=i;
		}
		localsum=0;
		#pragma omp for
		for(i=0;i<100;i++)
		{
			localsum+=a[i]*b[i];
		}
		printf("Local sum of thread %d is %d\n",tid,localsum);
		#pragma omp critical
			sum+=localsum;
	}
	printf("Dott product is %d\n",sum);
	return 0;
}
