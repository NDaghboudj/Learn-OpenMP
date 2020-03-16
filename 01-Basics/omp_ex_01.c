#include <stdio.h>
#include <omp.h>

/*
MIT License
Copyright (c) 2019 NOUREDDINE DAGHBOUDJ

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


int main()
{
    // Returns the number of processors the OS does have
    printf("Number of Processors: %i\n", omp_get_num_procs());

    // Returns the maximum number of threads delivered by the OS
    printf("Maximum Threads:      %i\n", omp_get_max_threads());

    // Returns the current number of threads
    printf("Number of Threads:    %i\n", omp_get_num_threads());

    // Returns an integer that represents the ID of the current thread
    printf("Thread ID:            %i\n", omp_get_thread_num());

    // Returns non-zero integer if running in parallel, and zero otherwise
    printf("In Parallel:          %i\n", omp_in_parallel());

	return 0;
}


