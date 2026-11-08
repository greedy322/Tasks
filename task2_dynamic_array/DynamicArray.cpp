#include "DynamicArray.h"

#include <algorithm>


DynamicArray::DynamicArray(const int* data, int size) {
    if (data != nullptr && size > 0) {
        size_ = size;
        data_ = new int[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = data[i];
        }
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    if (other.data_ != nullptr && other.size_ > 0) {
        size_ = other.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

DynamicArray::~DynamicArray() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;

        if (other.data_ != nullptr && other.size_ > 0) {
            size_ = other.size_;
            data_ = new int[size_];
            for (int i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }
    return *this;
}