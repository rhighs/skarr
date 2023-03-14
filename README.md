### Dynamic array library

A simple dynamic array library made as an experiment after lurking through @antirez's [sds](https://github.com/antirez/sds)

Example usage:
```c
#include "skarr.h"
#include <stdio.h>

int main(void) {
    double* arr = skarr_create((void*)0, sizeof(double), 100);
    for (int i=0; i<100; i++) skarr_push(&arr, (double)i);
    for (int i=0; i<100; i++) printf("arr[%d]: %f\n", i, arr[i]);
    skarr_clear(&arr);
    for (int i=0; i<100; i++) skarr_push(&arr, (double)i*2);
    for (int i=0; i<100; i++) printf("arr[%d]: %f\n", i, arr[i]);
    skarr_free(&arr);
    return 0;
}
```
