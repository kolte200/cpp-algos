#pragma once

#include "common.h"
#include "utils/concepts.h"


template<typename T>
requires ITERATOR_PROVIDER(T, io_fwd_it_of_gt)
void bead_sort(T list) {
    // Find the maximum element
    int max = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    // Allocating memory
    std::vector<std::vector<int>> beads;
    beads.resize(len);
    for (int i = 0; i < len; i++) {
        beads[i].resize(max);
        std::fill(beads[i].begin(), beads[i].end(), 0);
    }

    // Mark the beads
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < a[i]; j++) {
            beads[i][j] = 1;
        }
    }

    // Move down the beads
    for (int j = 0; j < max; j++) {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += beads[i][j];
            beads[i][j] = 0;
        }
        for (int i = len-1; i >= len-sum; i--) {
            beads[i][j] = 1;
        }
    }

    // To get sorted array
    std::vector<int> result;
    result.resize(len);
    for (int i = 0; i < len; i++) {
        int sum = 0;
        for (int j = 0; j < max; j++) {
            sum += beads[i][j];
        }
        result[i] = sum;
    }
    return result;
}
