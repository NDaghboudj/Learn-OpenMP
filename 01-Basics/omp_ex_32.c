#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define N 1024


void initArray(unsigned int *array, unsigned int size)
{
    for(unsigned int i=0; i<size; i++) array[i] = rand() % 40 + 10;
}


void printArray(unsigned int *array, unsigned int size)
{
    for(unsigned int i=0; i<size; i++) printf("%i ", array[i]);
    printf("\n");
}


unsigned int sumArray(unsigned int *A, unsigned int size)
{
    unsigned int gsum = 0;
    unsigned int stride;
    #pragma omp parallel
    {
        #pragma omp single
        stride = omp_get_num_threads();

        unsigned int id = omp_get_thread_num();
        unsigned int sum = 0;
        for(unsigned int i=id; i<size; i+=stride)
        {
            sum += A[i];
        }
    #pragma omp critical
    gsum += sum;
    }
    return gsum;
}


int main()
{
    unsigned int a[N], b[N], c[N];
    srand(0);
    initArray(a, N);

    printf("sum(A) = %i\n", sumArray(a, N));

	return 0;
}


