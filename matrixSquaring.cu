//cpu
void squarecpu(unsigned*matrix,unsigned *result,unsigned matrixsize /* 64*/){
    for(unsigned ii = 0;ii < matrixsize;ii++){
        for(unsigned jj = 0;jj < matrixsize;jj++){
            for(unsigned kk = 0;kk<matrixsize;kk++){
                result[ii*matrixsize+jj]=result[ii*matrixsize+kk]*matrix[kk*matrixsize+jj];
            }
        }
    }

}

//gpu version 1
square<<<1,N>>>(matrix,result,N);
__global__ void square(unsigned*matrix,unsigned *result,unsigned matrixsize){
        unsigned id = blockIdx.x*blockDim.x + threadIdx.x;
        for(unsigned jj = 0;jj < matrixsize;jj++){
            for(unsigned kk = 0;kk<matrixsize;kk++){
                result[id * matrixsize+jj]+=
                matrix[id * matrixsize +kk]*
                matrix[kk * matrixsize +jj];
            }
        }
}

//gpu version 2
square<<<N,N>>>(matrix,result,N);
__global__ void square(unsigned*matrix,unsigned *result,unsigned matrixsize){
        unsigned id = blockIdx.x*blockDim.x + threadIdx.x;
        unsigned ii = id / matrixsize;
        unsigned jj = id % matrixsize;
        for(unsigned kk = 0;kk < matrixsize;kk++){
            result[ii * matrixsize+jj]+=
            matrix[ii * matrixsize +kk]*
            matrix[kk * matrixsize +jj];
        }
        
}