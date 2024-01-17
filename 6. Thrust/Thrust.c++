


#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <iostream> 

int main(void) {
    // H has storage 1o. egers thrust host_vect<int
    H[0] = 14; 
    H[1] = 20; 
    H[2] = 38; 
    H[3] = 46;  // H.size() returns the size of vector H
    std::cout << "H has size " << H.size() << std::endl;
    // print contents of H
    for(int i= 0; i< H.size(); i++) 
    std::cout << "H[" <<i << "] = " << H[i] << std::endl;
    // resize H 
    H.resize(2);
    std::cout << "H now has size " << H.size()<< std::endl;
    // Copy host_vector H to device_vector D 
    thrust::device_vector<in>D=H;
    // elements of D can be modified 
    D[0]= 99; D[1] = 88;
    // H and D are automatically deleted when the function returns 
    return 0;
}



#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/fill.h>
#include <thrust/sequence.h>
#include <iostream> 
int main(void) {
    // initialize all ten integers of a device_vector to 1 
    thrust::device_vector<int> D(10,1);
    // set the first seven elements of a vector to 9 
    thrust::fill(D.begin(), D.begin() + 7, 9);
    // initialize a host vector with the first five elements of D 
    thrust::host_vector<int> H(D.begin(), D.begin() + 5); 
    // set the elements of H to 0, 1, 2, 3, .. 
    thrust::sequence(H.begin(),H.end());
    // copy all of H back to the beginning of D 
    thrust::copy(H.begin(),H.end(),D.begin());
    // print D
    for(int i= 0; i < D.size(); i++)
        std::cout << "D[" << i << "]= " << D[i] << gtd::endl; 
    return 0;
}

//Functions
int main(void) {
    // allocate three device_vectors with 10 elements 
    thrust::device_vector<int>X(10); 
    thrust::device_vector<int>Y(10); 
    thrust::device_vector<int> Z(10);
    // initialize X to 0,1,2,3, ....
    thrust::sequence(X.begin(),X.end());
    // compute Y=-X
    thrust::transform(X.begin(), X.end(), Y.begin(), thrust::negate<int>();
    // fill Z with twos
    thrust::fill(Z.begin(),Z.end(), 2);
    // compute Y =X mod 2
    thrust::transform(X.begin(), X.end(), Z.begin(), Y.begin(), thrust::modulus<int>());
    // replace all the ones in Y with tens 
    thrust::replace(Y.begin(), Y.end(), 1, 10);
    // print Y
    thrust::copy(Y.begin(),Y.end(),ptd::ostream_iterator<int>(std::cout, "\n")); 
    return 0;
}

//Functors
// calculate result[] = (a *x[]) + y[] 
struct saxpy { 
    const float _a;
    saxpy(inta) :_a(a){}
    __host__ __device__
    float operator() (const float8 x, const float8 y) const { 
        return _a * x + y;
    }
};
thrust::device_vector<float> x, y, result;... // populate x,y.
thrust::transform(xbegin(),x.end(),y.begin(), result.begin(),saxpy(a));

//Reductions
int x, y;
thrust::host_vector<int> hvec; 
thrust::device_vector<int> dvec;
// (thrust::reduce is a sum operation by default)
x = thrust::reduce(hvec.begin(), hvec.end()); // on CPU 
y = thrust::reduce(dvec.begin(),dvec.end()); // on GPU
y = thrust::reduce(dvec.begin(),dvec.end(),(int)0, thrust::plus<int>());

//prefix

int data[6] = {1, 0, 2, 2, 1, 3};
// inclusive scan
thrust::inclusive_scan(data, data +6, data); // data is now {1, 1, 3, 5, 6, 9}
thrust::exclusive_scan(data, data + 6, data);// data is now {0, 1, 1, 3, 5, 6}