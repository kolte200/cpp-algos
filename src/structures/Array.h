#pragma once

#include "common.h"


template<typename T> class Array {
    private:

    size_t len;
    const size_t maxlen;
    T* data;

    public:

    Array(size_t maxlen) : len(0), maxlen(maxlen) {
        data = new T[maxlen];
    }

    ~Array() {
        delete this->data;
    }

    size_t length() {
        return this->len;
    }

    void add(T value) {
        #ifdef SAFE_MODE
            if (this->len == maxlen)
                throw std::logic_error("no space left");
        #endif
        this->data[this->len++] = value;
    }

    T& get(size_t index) {
        #ifdef SAFE_MODE
            if (index < 0 || index >= len)
                throw std::logic_error("out of range index");
        #endif
        return this->data[index];
    }

    T& getLast() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw std::logic_error("empty array");
        #endif
        return this->data[len - 1];
    }

    T& getFirst() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw std::logic_error("empty array");
        #endif
        return this->data[0];
    }

    void set(size_t index, T value) {
        #ifdef SAFE_MODE
            if (index < 0 || index >= len)
                throw std::logic_error("out of range index");
        #endif
        this->data[index] = value;
    }

    void setFirst(T value) {
        #ifdef SAFE_MODE
            if (len == 0)
                throw std::logic_error("empty array");
        #endif
        this->data[0] = value;
    }

    void setLast(T value) {
        #ifdef SAFE_MODE
            if (len == 0)
                throw std::logic_error("empty array");
        #endif
        this->data[len - 1] = value;
    }

    T pop() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw std::logic_error("empty array");
        #endif
        return this->data[--this->len];
    }
};
