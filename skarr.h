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

void* skarr_create(void** dst, u32 size, u32 alloc);
u32 skarr_size(void** arr);
u32 skarr_capacity(void** arr);

void* __skarr_push(void** arr, u32 typesize);

#define _skarr_push(__skarr__) \
    ((typeof(*__skarr__))(__skarr_push((void*)__skarr__, sizeof(**__skarr__))))
#define skarr_push(__skarr__, value) (*_skarr_push(__skarr__) = value)
    
#endif
