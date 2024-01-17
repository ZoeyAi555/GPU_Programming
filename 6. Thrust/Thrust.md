Thrust is a parallel algorithms library supports vectors and associated transforms
- We don't know code executes on CPU or GPU
- Make sure of C++ fearures such as functors and __host__ and __device__ fucntions 

## Functions:
- find(begin, end, value);
- find_if(begin, end, predicate);
- copy, copy_if 
- count, count_if
- equal.
- min_element, max_element
- merge, sort, reduce
- transform.

## Algorithms
- dual implementations: host and device
- iterators as arguments must be on the same device