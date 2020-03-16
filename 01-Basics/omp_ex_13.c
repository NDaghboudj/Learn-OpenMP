#include <stdio.h>
#include <omp.h>


int main()
{
    unsigned int a[] = {90, 90, 90, 90};
	#pragma omp parallel
    {
        unsigned int id = omp_get_thread_num();
        a[id]+= 10 + omp_get_thread_num();
    	printf("a=%i\n", a[id]);
    }
	return 0;
}
