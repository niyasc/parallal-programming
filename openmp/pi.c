#include<stdio.h>
#include<omp.h>
int main(int argc,char *argv[])
{
	int i,n;
	double area=0.0,x;
	printf("Enter number of segments\n");
	scanf("%d",&n);
	#pragma omp parallel num_threads(3)
	{
		#pragma omp for private(x) reduction(+:area)
		for(i=0;i<n;i++)
		{
			x=(i+.5)/n;
			area+=4/(1+x*x);
		}
	}
	double pi=area/n;
	printf("Value of pi = %f \n",pi);
	return 0;
}
