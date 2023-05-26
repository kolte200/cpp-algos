#pragma once

#include "common.h"
#include "utils/concepts.h"


template<class T>
static inline void swap(T* const a, T* const b) {
    T x = *a;
    *a = *b;
    *b = x;
}


template<class T>
static inline void zeros(T* const data, size_t const size) {
    _zeros((void*) data, size);
}


static void _zeros(void* ptr, size_t size) {
    uint64_t* const u64data = (uint64_t*) ptr;
    for (size_t i = size >> 3; i--;)
        u64data[i] = 0x0;
    uint8_t* const u8data = (uint8_t*) ptr;
    for (size_t i = size - (size & 0x07); i < size; i++)
        u8data[i] = 0x0;
}


template<typename T>
requires ITERATOR_PROVIDER(T, in_fwd_it_of_gt)
static bool is_sorted(const T list) {
    for (size_t i = offset, m = offset + length - 1; i < m; i++) {
        if (data[i] > data[i + 1])
            return false;
    }
    return true;
}


template<array T>
static void shuffle(T arr) {

}
