#include <stdio.h>
#include <omp.h>
#include <math.h>

/*
MIT License
Copyright (c) 2019 NOUREDDINE DAGHBOUDJ

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


int main()
{
    float x1 = 1, y1 = 5, z1 = 4; // First Point
    float x2 = 2, y2 = 3, z2 = 6; // Second Point
    float dx, dy, dz;
    float distance;

	#pragma omp parallel
    {
    	#pragma omp sections
        {
            #pragma omp section
            {
                dx = x2 - x1;
            }

            #pragma omp section
            {
                dy = y2 - y1;
            }

            #pragma omp section
            {
                dz = z2 - z1;
            }
        }
    }
    distance = sqrt(dx * dx + dy * dy + dz * dz);
    printf("%f\n", distance);
    
	return 0;
}
