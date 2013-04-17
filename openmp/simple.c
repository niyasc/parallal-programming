#include<omp.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	int th_id,num_threads;
	omp_set_num_threads(4);
	#pragma omp parallal private(th_id) num_threads(10)
	{
		th_id=omp_get_thread_num();
		printf("Hello from thread %d\n",th_id);
	}
	printf("Number of threads=%d\n",omp_get_num_threads());
	printf("Number of cores=%d\n",omp_get_num_procs());
	return 0;
}