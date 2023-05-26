#pragma once

#include "common.h"
#include "utils/concepts.h"


/**
 * @brief Do a binary search on a sorted array of data
 *
 * @tparam T The data type (need to have the < operator and == operator)
 * @param data Array to search in
 * @param length The length of data
 * @param offset Where to begin search in the array
 * @return size_t The index of the searched value or -1 if not found
 */
template<array_of_comparable T, array_value<T> V>
ssize_t binary_search(const T data, const V value, const size_t length, const size_t offset = 0) {
    if (length <= 0) return -1;
    size_t start = offset, end = offset + length;
    while (start < end) {
        size_t mid = (start + end) / 2;
        if (data[mid] < value) {
            start = mid + 1;
        } else if(data[mid] == value) {
            return mid;
        } else {
            end = mid;
        }
    }
    return -1;
}
