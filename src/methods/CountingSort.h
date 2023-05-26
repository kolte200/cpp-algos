#pragma once

#include "common.h"
#include "utils/utils.h"

constexpr size_t MAX_STACK_SIZE = 128;

/**
 * @brief Sort data
 *
 * @tparam T Must be an integer type
 * @param data Data to sort
 * @param length The length of data
 * @param offset Where to begin search in the array
 */
template<class T>
void counting_sort(T* data, size_t length, size_t offset = 0) {
    if (length <= 0) return;

    T maxv = data[0];
    T minv = data[0];

    for (size_t i = offset, m = offset + length; i < m; i++) {
        const T val = data[i];
        if (val < minv) minv = val;
        if (val > maxv) maxv = val;
    }

    T* count_array = nullptr;
    const size_t arr_size = sizeof(T) * (maxv - minv + 1);
    if (arr_size <= MAX_STACK_SIZE) {
        T arr[arr_size];
        count_array = arr;
    } else {
        count_array = new T[arr_size];
    }

    zeros(count_array, arr_size);

    for (int i = offset, m = offset + lenght; i < m; i++) {
        count_array[data[i] - minv]++;
    }

    for(size_t i = 0, j = 0; i < arr_size; i++) {
        for (size_t k = count_array[i]; k--;)
            data[j++] = i + minv;
    }

    /*for(int i=1;i<BUCKET_SIZE;i++) {
		count_array[i] += count_array[i-1];
	}

	for(int i=0;i<n;i++) {
		output_array[ count_array[data[i]]-1] = data[i];
		count_array[data[i]]--;
	}

	for(int i=0;i<n;i++) {
		data[i] = output_array[i];
	}*/
}
