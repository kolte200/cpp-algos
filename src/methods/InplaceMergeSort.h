#pragma once

// Very fast sort function (theorically faster than basic merge sort, quicksort or timsort)
// Complexity (I guess) :
//   Mininum : O(n)
//   Average : O(n log n)
//   Maximum : O(n log n)


#include "common.h"
#include "utils/utils.h"


// Can be optimized by doing a dichotomie search to find where data
// of the second part begin to be greater inside the first part
template<class T>
static void _inplace_merge(T* const data, T* const buff, const size_t start, const size_t mid, const size_t end) {
    // Return directly if no merge is needed (this is the slight improve over the normal merge sort)
    if (!(data[mid - 1] > data[mid])) return;

    // Merge until one part is processed
    size_t i = start, j = mid, s = 0, e = 0;
    for (; i < mid && j < end; i++) {
        if (s < e) {
            buff[e++] = data[i];
            if (buff[s] > data[j]) {
                data[i] = data[j++];
            } else {
                data[i] = buff[s++];
            }
        } else {
            if (data[i] > data[j]) {
                buff[e++] = data[i];
                data[i] = data[j++];
            }
        }
    }

    // If i not reached the mid then there still elements in the first part to offset to the end
    if (i < mid) {
        for (size_t k = end, l = mid; l > i; ) {
            data[--k] = data[--l];
        }
    }

    // Keep until buffer is empty (so all remaining elements are already nice placed)
    // or until j reached the end (so all remaining elements in the buffer must be placed at the end)
    for (; s < e && j < end; i++) {
        if (buff[s] > data[j]) {
            data[i] = data[j++];
        } else {
            data[i] = buff[s++];
        }
    }

    // j reached the end so everything inside the buffer is greater (so can be placed at end)
    while (s < e) {
        data[i++] = buff[s++];
    }
}


template<class T>
static size_t _inplace_merge_segments(T* const data, T* const buff, const size_t length, const size_t segment, const size_t remaining) {
    const size_t segmentX2 = segment * 2;
    if (remaining < segment && remaining > 0) {
        _inplace_merge<T>(data, buff, length - remaining - segment, length - remaining, length);
        remaining += segment;
    }
    size_t i = 0;
    if (length >= segmentX2 + remaining) {
        for (size_t m = length + 1 - segmentX2 - remaining; i < m; i += segmentX2) {
            _inplace_merge<T>(data, buff, i, i + segment, i + segmentX2);
        }
    }
    if (length - i >= remaining + segment) {
        _inplace_merge<T>(data, buff, i, i + segment, length);
        remaining = length - i;
    }
    return remaining;
}


// Iterative in place and slightly improved merge sort
template<class T>
void inplace_merge_sort(T* const data, const size_t length) {
    // Swap elements two by two
    for (size_t i = 0, m = length - 1; i < m; i += 2) {
        if (data[i] > data[i + 1])
            swap(&data[i], &data[i + 1]);
    }

    if (length < 3) return;

    const size_t stack_buff_len = 128 / sizeof(T);

    // Allocate on heap and one stack buffer
    T* const heap_buff = length > stack_buff_len ? new T[length] : nullptr;
    T stack_buff[stack_buff_len];

    // Iterative merge sort
    size_t segment = 2;
    size_t remaining = length & 0x1;
    for (; segment < length; segment *= 2) {
        T* buff = segment <= stack_buff_len ? stack_buff : heap_buff; // The the right buffer for speed
        remaining = _inplace_merge_segments(data, buff, length, segment, remaining);
    }

    if (heap_buff) delete heap_buff;
}
