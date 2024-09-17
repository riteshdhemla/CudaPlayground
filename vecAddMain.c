#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <time.h>

__global__ void vecAddKernel(float* A_d, float* B_d, float* C_d, int n);

extern void vecAdd(float *A, float *B, float *C, int n);

int main()
{
    float *A_d, *B_d, *C_d;
    int n;
    clock_t start_time, end_time;
    
    scanf("%d", &n);

    int memSize = n * sizeof(float);
    
    A_d = (float*) malloc(memSize); 
    B_d = (float*) malloc(memSize); 
    C_d = (float*) malloc(memSize); 

    for (int i = 0; i < n; ++i)
    {
        A_d[i] = i;
        B_d[i] = i;
    }

    start_time = clock();
    vecAdd(A_d, B_d, C_d, n);
    end_time = clock();

    printf("Time Elapsed : %f \n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; ++i)
    {
        if ( i % 100 == 0)
            printf("\n");
        printf("%.1f ", C_d[i]);
    }

    free(A_d);
    free(B_d);
    free(C_d);
    return 0;
}