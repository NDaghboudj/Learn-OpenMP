#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/*
MIT License
Copyright (c) 2019 NOUREDDINE DAGHBOUDJ

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


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
    omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel
    {
        unsigned int id = omp_get_thread_num();
        sum[id] = 0;
        #pragma omp for
        for(unsigned int i=0; i<size; i++)
        {
            sum[id] += A[i];
        }
    }
    for(unsigned int j=0; j<MAX_THREADS; j++) gsum += sum[j];
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


