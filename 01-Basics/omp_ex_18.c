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


void addArrays(unsigned int *A, unsigned int *B, unsigned int *C, unsigned int size)
{
    unsigned int stride;
    #pragma omp parallel
    {
        #pragma omp single
        stride = omp_get_num_threads();

        unsigned int id = omp_get_thread_num();
        for(unsigned int i=id; i<size; i+=stride)
        {
            C[i] = A[i] + B[i];
        }
    }
}


int main()
{
    unsigned int a[N], b[N], c[N];
    srand(0);
    initArray(a, N);
    initArray(b, N);

    addArrays(a, b, c, N);

    printf("C = A + B\n");
    printf("A = ");
    printArray(a, 16);
    printf("B = ");
    printArray(b, 16);
    printf("C = ");
    printArray(c, 16);
	return 0;
}


