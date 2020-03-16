#include <stdio.h>
#include <omp.h>


int main()
{
	#pragma omp parallel
    {
        unsigned int a = 90;
        a += 10 + omp_get_thread_num();
    	printf("a=%i\n", a);
    }
	return 0;
}
