#include<stdio.h>
#include<omp.h>
int main(int argc,char *argv[])
{
	int th_id,num_threads,sum=0;
	int a[100],i;
	for(i=0;i<100;i++)
		a[i]=i;
	#pragma omp parallel private(th_id) num_threads(2)
	{
		th_id=omp_get_thread_num();
		#pragma omp parallel for reduction (+:sum)
		{
			for(i=0;i<100;i++)
			{
				sum+=a[i];
				if(i==49)
				{
					printf("I'm thread %d, sum=%d\n",th_id,sum);
				}
				if(i==99)
				{
					printf("I'm thread %d, sum=%d\n",th_id,sum);
				}
			}
		}
		#pragma sum barrier
		printf("I'm thread %d, sum=%d\n",th_id,sum);
	}

	return 0;
}
