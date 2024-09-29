#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <time.h>

extern void imageBlur(float *A_h, float *T_h, int w, int h);

int main()
{
    float *A_h, *T_h;

    int w, h;
    
    scanf("%d", &w);
    scanf("%d", &h);

    clock_t start_time, end_time;
    srand(42);

    int mem_size = w * h * sizeof(float);
    A_h = (float *) malloc(mem_size);
    T_h = (float *) malloc(mem_size);
    int random_number; 
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < h; ++j)
        {
            random_number = rand() % 256;
            A_h[i + j*w] = (float) random_number;
        }
    }
    start_time = clock();
    imageBlur(A_h, T_h, w, h);
    end_time = clock();
    // printf("Wall Time : %ld \n", (end_time - start_time) / CLOCKS_PER_SEC);

    printf("Input: \n");
    for (int j = 0; j < h; ++j)
    {
        for (int i = 0; i < w; ++i)
        {
            printf("%.2f ", A_h[i + j*w]);
        }
        printf("\n");
    }

    printf("Output: \n");

    for (int j = 0; j < h; ++j)
    {
        for (int i = 0; i < w; ++i)
        {
            printf("%.2f ", T_h[i + j*w]);
        }
        printf("\n");
    }

    free(A_h);
    free(T_h);

    return 0;
}