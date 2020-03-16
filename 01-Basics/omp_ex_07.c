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
                printf("Hello World! from Section A\n");
            }

            #pragma omp section
            {
                printf("Hello World! from Section B\n");
            }

            #pragma omp section
            {
                printf("Hello World! from Section C\n");
            }

            #pragma omp section
            {
                printf("Hello World! from Section D\n");
            }
        }
    }
	return 0;
}
