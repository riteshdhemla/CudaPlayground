#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <time.h>

__global__ void vecAddKernel(float* A_d, float* B_d, float* C_d, int n);

extern void vecAdd(float *A, float *B, float *C, int n);

int main()
{
    float *A_h, *B_h, *C_h;
    int n;
    clock_t start_time, end_time;
    
    scanf("%d", &n);

    int memSize = n * sizeof(float);
    
    A_h = (float*) malloc(memSize);
    B_h = (float*) malloc(memSize);
    C_h = (float*) malloc(memSize);

    for (int i = 0; i < n; ++i)
    {
        A_h[i] = i;
        B_h[i] = i;
    }

    start_time = clock();
    vecAdd(A_h, B_h, C_h, n);
    end_time = clock();

    printf("Time Elapsed : %f \n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; ++i)
    {
        if ( i % 100 == 0)
            printf("\n");
        printf("%.1f ", C_h[i]);
    }

    free(A_h);
    free(B_h);
    free(C_h);
    return 0;
}
