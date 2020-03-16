#include <stdio.h>
#include <omp.h>


int main()
{
    #pragma omp parallel
    {
        // Returns the current number of threads
        printf("Number of Threads:    %i\n", omp_get_num_threads());
    }
	return 0;
}


