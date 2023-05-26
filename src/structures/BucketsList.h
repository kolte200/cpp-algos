#include <stddef.h>

template<typename T, size_t NB_BUCKETS, size_t BUCKET_LEN> class BucketsList {
    private:

    T* buckets[NB_BUCKETS];
    size_t bucket_index;
    size_t value_index;
    size_t allocated_buckets;

    public:

    BucketsList() {
        this->bucket_index = 0;
        this->value_index = 0;
        this->allocated_buckets = 1;
        this->buckets[0] = new T[BUCKET_LEN];
    }

    void add(T value) {
        size_t index = this->value_index;
        if (index == BUCKET_LEN) {
            this->buckets[this->bucket_index] = new T[BUCKET_LEN];
            this->allocated_buckets++;
            index = 0;
            this->bucket_index++;
        }
        this->buckets[this->bucket_index][index] = value;
        this->value_index = index + 1;
    }

    T pop() {
        size_t index = this->value_index;
        if (index == 0) {
            index = BUCKET_LEN;
            this->bucket_index--;
            if (this->allocated_buckets - this->bucket_index > 1) {
                delete this->buckets[this->allocated_buckets - 1];
                this->allocated_buckets--;
            }
        }
        index--;
        this->value_index = index;
        return this->buckets[this->bucket_index][index];
    }

    T get(size_t index) {
        size_t bucket = index / BUCKET_LEN;
        return this->buckets[bucket][index - bucket * BUCKET_LEN];
    }

    void set(size_t index, T value) {
        size_t bucket = index / BUCKET_LEN;
        this->buckets[bucket][index - bucket * BUCKET_LEN] = value;
    }

    size_t length() {
        return this->bucket_index * BUCKET_LEN + this->value_index;
    }
};
