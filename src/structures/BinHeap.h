#pragma once

#include "BucketsList.h"

template<typename T> class BinHeap {
    protected:

    BucketsList<T, 8192, 8192> data;
};
