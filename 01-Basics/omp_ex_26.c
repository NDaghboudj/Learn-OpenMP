#include <stdio.h>
#include <omp.h>


int main()
{
    #pragma omp parallel for
    for(unsigned int i=0; i<16; i++)
    {
        unsigned id = omp_get_thread_num();
        printf("i = %i from thread: %i\n", i, id);
    }
	return 0;
}


