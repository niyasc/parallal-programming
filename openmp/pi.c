#include<omp.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	int th_id,n,i;
	float area=0.0,pi,x;
	printf("Enter number of segements : ");
	scanf("%d",&n);
	#pragma omp parallel private(th_id) num_threads(3)
	{
		th_id=omp_get_thread_num();
		#pragma omp for private(x) reduction(+:area)
		{
			for(i=0;i<n;i++)
			{
				x=(i+0.5)/n;
				area+=4.0/(1+x*x);
			}
		}
	}
	pi=area/n;
	printf("Value of pi= %d\n",pi);
}
