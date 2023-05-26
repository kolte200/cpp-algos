#pragma once

#include "common.h"
#include <cmath>


template<typename T, size_t MAX_LEN> class Vector {
    private:

    size_t len;
    T data[MAX_LEN];

    public:

    size_t length() {
        return this->len;
    }

    void add(T value) {
        #ifdef SAFE_MODE
            if (this->len == MAX_LEN)
                throw std::exception("no space left");
        #endif
        this->data[this->len++] = value;
    }

    T& get(size_t index) {
        #ifdef SAFE_MODE
            if (index < 0 || index >= len)
                throw throw std::exception("out of range index");
        #endif
        return this->data[index];
    }

    T& getLast() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty vector");
        #endif
        return this->data[len - 1];
    }

    T& getFirst() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty vector");
        #endif
        return this->data[0];
    }

    void set(size_t index, T value) {
        #ifdef SAFE_MODE
            if (index < 0 || index >= len)
                throw throw std::exception("out of range index");
        #endif
        this->data[index] = value;
    }

    void setFirst(T value) {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty vector");
        #endif
        this->data[0] = value;
    }

    void setLast(T value) {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty vector");
        #endif
        this->data[len - 1] = value;
    }

    T pop() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty vector");
        #endif
        return this->data[--this->len];
    }
};
