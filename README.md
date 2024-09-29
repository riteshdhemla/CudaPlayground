# CUDA Playground

## Overview

This repository serves as a learning playground for CUDA (Compute Unified Device Architecture) programming. It contains various code snippets and examples demonstrating CUDA concepts and techniques.

## Purpose

The primary goal of this project is to get a hands-on learning experience in parallel computing using NVIDIA's CUDA platform. 

<!-- Through practical examples and exercises, users can gain insights into:

- CUDA kernel development
- Memory management in GPU computing
- Parallel algorithm design
- Performance optimization techniques -->

## Contents

- `vecAdd.cu`: A simple vector addition program demonstrating basic CUDA kernel usage
- (TO DO: Add more files and descriptions as repository grows)
<!-- 
## Getting Started

1. Ensure you have the NVIDIA CUDA Toolkit installed on your system.
2. Clone this repository:
3. Navigate to the project directory and compile the CUDA programs using `nvcc`. -->

## Compiling Programs
To compile `vecAdd` kernel, use:
```
nvcc -o vecAdd vecAddMain.c vecAdd.cu
```

## Reference Material

This project is inspired by and based on concepts from the book:

**"Programming Massively Parallel Processors: A Hands-on Approach"**
by David B. Kirk and Wen-mei W. Hwu

[Book Link](https://www.elsevier.com/books/programming-massively-parallel-processors/kirk/978-0-12-811986-0)

## Personal Learning Journey

This repository documents my personal journey in learning CUDA programming. The code snippets, examples, and experiments here reflect my progress and understanding of parallel computing concepts. While I strive for accuracy, some implementations might not be optimal as I'm still learning and experimenting.

<!-- 
## Contributions

Contributions, issues, and feature requests are welcome. Feel free to check the issues page if you want to contribute.

## License

[MIT](https://choosealicense.com/licenses/mit/) -->