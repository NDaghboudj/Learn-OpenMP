#include <stdio.h>
#include <omp.h>


int main()
{
    unsigned a = 90;
    printf("Before a = %i\n", a);
    printf("Inside a = ");
    #pragma omp parallel for lastprivate(a)
    for(unsigned int i=0; i<16; i++)
    {
        a = 10 + i;
        printf("%i ", a);
    }
    printf("\n");
    printf("After  a = %i\n", a);
	return 0;
}


