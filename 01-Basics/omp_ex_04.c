#include <stdio.h>
#include <omp.h>


int main()
{
    // After compiling this code, run it for a couple of times
    // What did you notice?
	#pragma omp parallel
    {
    	printf("Hello World! from thread %i\n", omp_get_thread_num());
    }
	return 0;
}
