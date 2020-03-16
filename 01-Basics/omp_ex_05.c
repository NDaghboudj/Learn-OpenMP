#include <stdio.h>
#include <omp.h>


int main()
{
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("I have been executed by Thread %i\n", omp_get_thread_num());
        }
    }
	return 0;
}


