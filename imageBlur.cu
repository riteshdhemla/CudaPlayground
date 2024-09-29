#include <stdio.h>

__global__
void imageBlurKernel(float* A, float* T, int w, int h)
{
    // w : width , number of columns
    // h : height , number of rows
    int col = blockIdx.x*blockDim.x + threadIdx.x;
    int row = blockIdx.y*blockDim.y + threadIdx.y;
    
    int BLUR_SIZE = 1; // BLUR_MATRIX = 3 x 3
    float sum_pixels = 0.0f;
    int pixel_count = 0;
    int colIdx, rowIdx;
    
    if (col < w && row < h)
    {
        for(int blurRow=-BLUR_SIZE; blurRow <= BLUR_SIZE; blurRow++)
        {
            for(int blurCol=-BLUR_SIZE; blurCol <= BLUR_SIZE; blurCol++)
            {
                colIdx = col + blurCol;
                rowIdx = row + blurRow;
                if (colIdx >= 0 && rowIdx >= 0 && colIdx < w && rowIdx < h)
                {
                    sum_pixels += A[rowIdx * w + colIdx];
                    ++pixel_count;
                }
            }
        }
        T[row * w + col] = sum_pixels / pixel_count;
    }
}

extern "C" void imageBlur(float* A_h, float* T_h, int w, int h)
{
    float* A_d;
    float* T_d;
    int memSize = sizeof(float) * w * h;
    cudaError_t err;
    
    err = cudaMalloc((void **) &A_d, memSize);

    if (err != cudaSuccess)
    {
        printf("Error allocating device memory for A_d");
        return;
    }

    err = cudaMalloc((void **) &T_d, memSize);
    if (err != cudaSuccess)
    {
        printf("Error allocating device memory for T_d");
        return;
    }
    cudaMemcpy(A_d, A_h, memSize, cudaMemcpyHostToDevice);
  
    dim3 dimGrid(ceil(w/16.0), ceil(h/16.0), 1);
    dim3 dimBlock(16, 16, 1);
    imageBlurKernel<<<dimGrid,dimBlock>>>(A_d, T_d, w, h);

    cudaMemcpy(T_h, T_d, memSize, cudaMemcpyDeviceToHost);

    cudaFree(A_d);
    cudaFree(T_d);
}