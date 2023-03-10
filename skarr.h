// Author: 
//     Roberto Montalti 2023
//
// File:
//     skarr.h

#ifndef SKARR_H
#define SKARR_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;

typedef struct {
    u32 cap;
    u32 size;
    u8 data[];
} skarr;

void* skarr_create(void** dst, u32 size, u32 alloc);    // Creates a new array.
u32 skarr_size(void** arr);                             // Returns the number of elements.
u32 skarr_capacity(void** arr);                         // Returns the allocated bytes.
void skarr_free(void** arr);                            // Frees the entire data structure.
void skarr_reset(void** arr);                           // Removes all elements and frees allocated memory.
void skarr_clear(void** arr);                           // Removes all elements keeps memory allocated and sets it all to 0.
void skarr_erase(void** arr);                           // Removes all elements keeping memory untouched.
void* __skarr_push(void** arr, u32 typesize);           // Makes room for a new element and returns a pointer to that memory.
void* __skarr_pop(void** arr, u32 typesize);            // Removes the last element and return a pointer to that memory.

#define _skarr_push(__skarr__) \
    ((typeof(*__skarr__))(__skarr_push((void*)__skarr__, sizeof(**__skarr__))))
#define skarr_push(__skarr__, value) \
    (*_skarr_push(__skarr__) = value)
#define skarr_pop(__skarr__) \
    ((typeof(**__skarr__))*((typeof(*__skarr__))__skarr_pop((void**)__skarr__, sizeof(**__skarr__))))
    
#endif
