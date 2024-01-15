__global__ void dkernel(unsigned*vector,unsigned vectorsize){
    unsigned id = blockIdx.x*blockDim.x+threadId.x;
    if(id%2) vector[id] = id;
    else vector[id] = vectorsize*vectorsize;
    vector[id]++;
}
/*
Wrap: Differnt wrap-thread execute different instructions, thraed are said to diverge
Diverge
Degree of Divergence; # steps to complete one instruction for each thread in the wrap
*/

//rewrite the following program to remove thread-divergence: 
int x,y,z;
if(x==y) x=z; 
else x=y;

int mask = (x == y); // 1 if x equals y, 0 otherwise
int value_if_true = z;
int value_if_false = y;

// Perform both operations for all threads
int result_if_true = value_if_true;
int result_if_false = value_if_false;

// Combine the results based on the mask
x = mask * result_if_true + (!mask) * result_if_false;
