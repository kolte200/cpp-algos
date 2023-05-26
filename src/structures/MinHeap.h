#pragma once

#include "BinHeap.h"

template<typename T> class MinHeap : public BinHeap<T> {
    public:

    void add(T value) {
        this->data.add(value);
        // TODO
    }
};
