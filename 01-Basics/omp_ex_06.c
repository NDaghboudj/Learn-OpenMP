#include <stdio.h>
#include <omp.h>


int main()
{
    #pragma omp parallel
    {
        #pragma omp master
        {
            printf("I have been executed by the Master Thread %i\n", omp_get_thread_num());
        }
    }
	return 0;
}


