#include <stdio.h>
#include <omp.h>
#include <math.h>


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
