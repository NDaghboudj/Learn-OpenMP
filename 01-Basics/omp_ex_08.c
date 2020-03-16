#include <stdio.h>
#include <omp.h>


int main()
{
    // After compiling this code, run it for a couple of times
    // What did you notice?
	#pragma omp parallel
    {
    	#pragma omp sections
        {
            #pragma omp section
            {
                printf("Hello World! from Section A %i\n", omp_get_thread_num());
            }

            #pragma omp section
            {
                printf("Hello World! from Section B %i\n", omp_get_thread_num());
            }

            #pragma omp section
            {
                printf("Hello World! from Section C %i\n", omp_get_thread_num());
            }

            #pragma omp section
            {
                printf("Hello World! from Section D %i\n", omp_get_thread_num());
            }
        }
    }
	return 0;
}
