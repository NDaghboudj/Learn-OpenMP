#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define N 1024
#define MAX_THREADS 4


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
    unsigned int sum[MAX_THREADS], gsum = 0;
    unsigned int stride;
    omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel
    {
        #pragma omp single
        stride = omp_get_num_threads();

        unsigned int id = omp_get_thread_num();
        sum[id] = 0;
        for(unsigned int i=id; i<size; i+=stride)
        {
            sum[id] += A[i];
        }
    #pragma omp barrier
    #pragma omp single
    for(unsigned int j=0; j<MAX_THREADS; j++) gsum += sum[j];
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


