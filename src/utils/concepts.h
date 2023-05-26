#pragma once

#include "common.h"

#include <concepts>


// Comparaisons concepts

template<typename T>
concept lower_than_comparable = requires(T a, T b) {
    {a<b} -> std::convertible_to<bool>;
    {b<a} -> std::convertible_to<bool>;
};

template<typename T>
concept greater_than_comparable = requires(T a, T b) {
    {a>b} -> std::convertible_to<bool>;
    {b>a} -> std::convertible_to<bool>;
};

template<typename T>
concept equal_comparable = requires(T a, T b) {
    {a==b} -> std::convertible_to<bool>;
    {b==a} -> std::convertible_to<bool>;
};



// Iterators concepts

template<typename T>
concept forward_iterable = requires(T a) {
    {++a} -> std::same_as<T>;
};

template<typename T>
concept bidirectional_iterable = forward_iterable<T> && requires(T a) {
    {--a} -> std::same_as<T>;
};


// Iterator providers

#define ITERATOR_PROVIDER(type, iterable_concept) requires(type a) {{a.begin()} -> iterable_concept<>; {a.end()} -> iterable_concept<>;}


// References

template<typename T>
concept in_reference = requires(T a) {
    *a;
};

template<typename T>
concept out_reference = requires(T a) {
    std::is_lvalue_reference(*a);
};

template<typename T>
concept io_reference = in_reference<T> && out_reference<T>;

#define IN_REFERENCE_OF(type, value_concept) requires(type a) {{*a} -> value_concept<>;}
#define IO_REFERENCE_OF(type, value_concept) out_reference<type> && requires(type a) {{*a} -> value_concept<>;}


// Blends

// Input forward iterable of comparable with greater than
template<typename T> concept in_fwd_it_of_gt = forward_iterable<T> && IN_REFERENCE_OF(T, greater_than_comparable);

// Input forward iterable of comparable with greater than
template<typename T> concept io_fwd_it_of_gt = forward_iterable<T> && IO_REFERENCE_OF(T, greater_than_comparable);

/*
template<typename T>
concept output_iterable = forward_iterable<T> && output_reference<T>;

template<typename T>
concept input_iterable = forward_iterable<T> && input_reference<T>;

template<typename T>
concept input_iterable_of_comparable = forward_iterable<T> && input_reference_of_comparable<T>;

template<typename T>
concept io_iterable = forward_iterable<T> && reference<T>;

template<typename T>
concept io_iterable_of_comparable = forward_iterable<T> && reference_to_comparable<T>;


template<typename T>
concept output_bi_iterable = bidirectional_iterable<T> && output_reference<T>;

template<typename T>
concept input_bi_iterable = bidirectional_iterable<T> && input_reference<T>;

template<typename T>
concept input_bi_iterable_of_comparable = bidirectional_iterable<T> && input_reference_of_comparable<T>;

template<typename T>
concept io_bi_iterable = bidirectional_iterable<T> && reference<T>;

template<typename T>
concept io_bi_iterable_of_comparable = bidirectional_iterable<T> && reference_to_comparable<T>;
*/


// Array concepts

template<typename T>
concept array = requires(T a, size_t i) {
    a[i];
    {a.size()} -> std::convertible_to<size_t>;
};

template<typename T>
concept array_of_comparable = requires(T a, size_t i) {
    {a[i]} -> lower_than_comparable<>;
};

template<typename V, typename T>
concept array_value = requires(T a, size_t i) {
    {a[i]} -> std::convertible_to<V>;
};
