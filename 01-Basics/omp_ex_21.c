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
    unsigned int sum = 0;
    for(unsigned int i=0; i<size; i++)
    {
        sum += A[i];
    }
    return sum;
}


int main()
{
    unsigned int a[N], b[N], c[N];
    srand(0);
    initArray(a, N);

    printf("sum(A) = %i\n", sumArray(a, N));

	return 0;
}


