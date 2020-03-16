#include <stdio.h>
#include <omp.h>

unsigned int a = 90;

int main()
{
    #pragma omp threadprivate(a)
    printf("Before a = %i\n", a);
    #pragma omp parallel
    {
        a += 10 + omp_get_thread_num();
        printf("Inside a = %i\n", a);
    }
    printf("After  a = %i\n", a);
	return 0;
}


