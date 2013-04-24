#include<stdio.h>
#include<omp.h>
int main()
{
	int a[20],i,tid,j;
	#pragma omp parallel private(i,tid) shared(a)
	{
		tid=omp_get_thread_num();
		#pragma omp for
		for(i=0;i<20;i++)
			a[i]=random()%100;
		#pragma omp critical
		for(i=0;i<19;i++)
		{
			printf("At thread %d\n",omp_get_thread_num());
			for(j=i+1;j<20;j++)
			{
				if(a[i]>a[j])
				{
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	printf("sorted array is \n");
	for(i=0;i<20;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
