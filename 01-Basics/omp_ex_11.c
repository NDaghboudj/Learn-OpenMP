#include <stdio.h>
#include <omp.h>


int main()
{
    unsigned int a = 90;
	#pragma omp parallel
    {
        a += 10 + omp_get_thread_num();
        printf("a=%i\n", a);
    }
	return 0;
}
