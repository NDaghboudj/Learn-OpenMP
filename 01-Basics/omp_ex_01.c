#include <stdio.h>
#include <omp.h>


int main()
{
    // Returns the number of processors the OS does have
	printf("Number of Processors: %i\n", omp_get_num_procs());

    // Returns the maximum number of threads delivered by the OS
    printf("Maximum Threads:      %i\n", omp_get_max_threads());

    // Returns the current number of threads
    printf("Number of Threads:    %i\n", omp_get_num_threads());

    // Returns an integer that represents the ID of the current thread
    printf("Thread ID:            %i\n", omp_get_thread_num());

    // Returns non-zero integer if running in parallel, and zero otherwise
    printf("In Parallel:          %i\n", omp_in_parallel());

	return 0;
}


