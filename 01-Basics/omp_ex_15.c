#include <stdio.h>
#include <omp.h>


int main()
{
    unsigned int a = 90;
    printf("Before a = %i\n", a);
    #pragma omp parallel firstprivate(a)
    {
        a += 10 + omp_get_thread_num();
        printf("Inside a = %i\n", a);
    }
    printf("After  a = %i\n", a);
	return 0;
}

