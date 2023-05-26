#pragma once

#include "common.h"


inline size_t _inc(size_t i, size_t max) {
    return (i + 1 == max) ? 0 : (i + 1);
}

inline size_t _dec(size_t i, size_t max) {
    return (i == 0) ? (max - 1) : (i - 1);
}

inline size_t _add(size_t i, size_t x, size_t max) {
    register size_t y = i + x;
    return (y >= max) ? (y - max) : y;
}


template<typename T, size_t MAX_LEN> class CircularArray {
    private:

    size_t len;
    size_t begin;
    T data[MAX_LEN];

    public:

    void rotateLeft() {
        begin = _dec(begin, MAX_LEN);
    }

    void rotateRight() {
        begin = _inc(begin, MAX_LEN);
    }

    T& get(size_t index) {
        #ifdef SAFE_MODE
            if (index < 0 || index >= len)
                throw throw std::exception("out of range index");
        #endif
        return data[_add(begin, index, MAX_LEN)]
    }

    T& getFirst() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty circular array");
        #endif
        return data[begin];
    }

    T& getLast() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty circular array");
        #endif
        return data[_add(begin, len - 1, MAX_LEN)];
    }

    void set(size_t index, T value) {
        #ifdef SAFE_MODE
            if (index < 0 || index >= len)
                throw throw std::exception("out of range index");
        #endif
        data[_add(begin, index, MAX_LEN)] = value;
    }

    void setFirst(T value) {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty circular array");
        #endif
        data[begin] = value;
    }

    void setLast(T value) {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty circular array");
        #endif
        data[_add(begin, len - 1, MAX_LEN)] = value;
    }

    void addLast(T value) {
        #ifdef SAFE_MODE
            if (this->len == MAX_LEN)
                throw std::exception("no space left");
        #endif
        data[_add(begin, len, MAX_LEN)] = value;
        len++;
    }

    void addFirst(T value) {
        #ifdef SAFE_MODE
            if (this->len == MAX_LEN)
                throw std::exception("no space left");
        #endif
        begin = _dec(begin, MAX_LEN);
        data[begin] = value;
        len++;
    }

    T popLast() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty circular array");
        #endif
        len--;
        return data[_add(begin, len, MAX_LEN)];
    }

    T popFirst() {
        #ifdef SAFE_MODE
            if (len == 0)
                throw throw std::exception("empty circular array");
        #endif
        begin = _inc(begin, MAX_LEN);
        len--;
        return data[begin];
    }
};
