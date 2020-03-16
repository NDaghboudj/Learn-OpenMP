#include <stdio.h>
#include <omp.h>


int main()
{
    // Hello World! in parallel
	#pragma omp parallel
    {
    	printf("Hello World!\n");
    }
    // What's going on?!!!
	return 0;
}
