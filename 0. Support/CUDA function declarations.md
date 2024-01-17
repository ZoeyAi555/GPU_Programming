![cuda](cuda.png)
- __global__ defines a kernel must return void
- Host == CPU Device == GPU

CPU to GPU
```cudaHostAlloc(void** pHost,sizeof(int),0)```
- free ```cudaFreeHost()```
GPU to CPU
```cudaMemcpy ( void* dst, const void* src, size_t count, cudaMemcpyKind kind )```