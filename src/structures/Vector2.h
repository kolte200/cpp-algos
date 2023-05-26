#pragma once

#include "common.h"


template<typename T> class Vector2 {
    public:

    T x, y;

    Vector2(T x, T y) : x(x), y(y) {}

    T sqLength() {
        return x*x + y*y;
    }

    float length() {
        return sqrtf((float)sqLength());
    }
};
