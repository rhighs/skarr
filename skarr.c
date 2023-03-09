#include "skarr.h"

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>

static
skarr* __get_data(void* arr) {
    return &((skarr*)arr)[-1];
}

u32 skarr_size(void** arr) { return __get_data(*arr)->size; }
u32 skarr_capacity(void** arr) { return __get_data(*arr)->cap; }

static
skarr* __skarr_realloc(skarr* m_data) {
    u32 new_cap = m_data->cap + m_data->cap/2;
    m_data = realloc(m_data, sizeof(skarr) + new_cap);
    m_data->cap = new_cap;
    return m_data;
}

void* skarr_create(void** dst, u32 size, u32 n) {
    u32 bufsize = size * (n != 0 ? n : 4);
    skarr* out = (skarr*)malloc(sizeof(skarr) + bufsize);
    out->cap = bufsize;
    out->size = 0;
    if (dst != NULL) {
        *dst = out->data;
    }
    return &out->data;
}

void* __skarr_push(void** arr, u32 typesize) {
    skarr* m_data = __get_data(*arr);
    if (m_data->size*typesize + typesize >= m_data->cap) {
        m_data = __skarr_realloc(m_data);
        *arr = m_data->data;
    }
    return (void*)&m_data->data[typesize * m_data->size++];
}

