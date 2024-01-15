
## Bandwidth ##
Big data bus rather than fast data bus
Parallel data transfer
Improve bandwidth:
- share/resue data
- data compression
- recompute than store + fetch

## Lantency ##
I/O

## Locality ##
### Spatial 空间上的 ###
a[i] be accessed -> a[i+k] also be accessed
``` for (i=0;i<N;i++) a[i] = 0; ```

### Temporal 时间上的 ###
a[i] be accessed now -> a[i] be accessed soon again
``` a[i] = i; a[i] += N; b[i] = a[i]*a[i] ```

## Memory Coalescing凝集 ##
If warp threads access words from the same block of 32 words, their memory requests are clubbed into one.
Without coalescing, each load/store would require one memory cycle

Degree of Coalescing: 33 - # memory transactions required for a wrap to execute an instruction
a[threadIdx.x] DoC 32
a[rand()] DoC 1 worst

AoS vs SoA
AoS: a thread accesses an attribute of a node, 
it also access an attricute of a node, 
it also access other attributes of the same node.
Better locality on CPU
```
struct node {
    int a;
    double b;
    char c;
};
struct node allnodes[N];
```

SoA:a thread accesses an attribute of a node, 
its neighboring thread accesses the same attribute of the next node 
Better coalesting on GPU
```
struct node{
    int alla[N];
    double allb[N];
    char allc[N];
};
```





