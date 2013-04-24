#include<stdio.h>
#include<omp.h>
float f(float x)
{
	return x*x*x;
}
int main()
{
	float x0,xn,dx,ans=0.0,localans;
	int tid,n,i;
	printf("Enter lower and upper limits\n");
	scanf("%f%f",&x0,&xn);
	printf("Enter number of divisions\n");
	scanf("%d",&n);
	dx=(xn-x0)/n;
	#pragma omp parallel private(tid,i,localans) shared(ans)
	{
		tid=omp_get_thread_num();
		localans=0;
		#pragma omp for
		for(i=0;i<n;i++)
		{
			localans+=f(x0+i*dx);
		}
		printf("Contribution from thread %d is %f\n",tid,localans);
		
		#pragma omp critical
		{
			ans+=localans;
		}
	}
	ans=ans*dx;
	printf("Solution to integration is %f\n",ans);
	return 0;
}
		
