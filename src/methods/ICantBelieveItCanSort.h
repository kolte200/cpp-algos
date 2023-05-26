#pragma once

// https://arxiv.org/pdf/2110.01111.pdf

#include "common.h"


template<class T>
void i_cant_believe_it_can_sort(T* data, size_t length, size_t offset = 0) {
    data = &data[offset];
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length; j++) {
            if (data[i] < data[j]) {
                swap(&data[i], &data[j]);
            }
        }
    }
}
