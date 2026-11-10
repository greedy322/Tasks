#include "DynamicArray.h"

#include <algorithm>
#include <cassert>

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

int& DynamicArray::operator[](int index) {
    assert(index >= 0 && index < size_);
    return data_[index];
}

const int& DynamicArray::operator[](int index) const {
    assert(index >= 0 && index < size_);
    return data_[index];
}

void DynamicArray::Swap(DynamicArray& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
}

int DynamicArray::Find(int value) const {
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

void DynamicArray::Sort() {
    for (int i = 1; i < size_; ++i) {
        int key = data_[i];
        int j = i - 1;
        while (j >= 0 && data_[j] > key) {
            data_[j + 1] = data_[j];
            --j;
        }
        data_[j + 1] = key;
    }
}

bool DynamicArray::Insert(int index, int value) {
    if (index < 0 || index > size_) {
        return false;
    }

    int* new_data = new int[size_ + 1];

    for (int i = 0; i < index; ++i) {
        new_data[i] = data_[i];
    }


    new_data[index] = value;

    for (int i = index; i < size_; ++i) {
        new_data[i + 1] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    ++size_;

    return true;
}

bool DynamicArray::RemoveAt(int index) {
    if (index < 0 || index >= size_) {
        return false;
    }

    if (size_ == 1) {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        return true;
    }

    int* new_data = new int[size_ - 1];

    for (int i = 0; i < index; ++i) {
        new_data[i] = data_[i];
    }

    for (int i = index + 1; i < size_; ++i) {
        new_data[i - 1] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    --size_;

    return true;
}

bool DynamicArray::Remove(int value) {
    int idx = Find(value);
    if (idx == -1) {
        return false;
    }
    return RemoveAt(idx);
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
    os << "[";
    for (int i = 0; i < arr.GetSize(); ++i) {
        os << arr[i] << (i + 1 < arr.GetSize() ? ", " : "");
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, DynamicArray& arr) {
    int count = 0;
    if (!(is >> count) || count < 0) {
        return is;
    }

    for (int i = 0; i < count; ++i) {
        int val = 0;
        is >> val;
        arr.Insert(arr.GetSize(), val);
    }

    return is;
}

int DynamicArray::RemoveAll(int value) {
    int count = 0;
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == value) {
            ++count;
        }
    }

    if (count == 0) {
        return 0;
    }

    int new_size = size_ - count;
    if (new_size == 0) {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        return count;
    }

    int* new_data = new int[new_size];
    int dest = 0;
    for (int i = 0; i < size_; ++i) {
        if (data_[i] != value) {
            new_data[dest++] = data_[i];
        }
    }

    delete[] data_;
    data_ = new_data;
    size_ = new_size;

    return count;
}

int DynamicArray::GetMin() const {
    assert(size_ > 0);
    int min_val = data_[0];
    for (int i = 1; i < size_; ++i) {
        if (data_[i] < min_val) {
            min_val = data_[i];
        }
    }
    return min_val;
}

int DynamicArray::GetMax() const {
    assert(size_ > 0);
    int max_val = data_[0];
    for (int i = 1; i < size_; ++i) {
        if (data_[i] > max_val) {
            max_val = data_[i];
        }
    }
    return max_val;
}

DynamicArray& DynamicArray::operator+=(int value) {
    Insert(size_, value);
    return *this;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& other) {
    if (other.size_ == 0) {
        return *this;
    }

    int new_size = size_ + other.size_;
    int* new_data = new int[new_size];

    for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    for (int i = 0; i < other.size_; ++i) {
        new_data[size_ + i] = other.data_[i];
    }

    delete[] data_;
    data_ = new_data;
    size_ = new_size;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
    os << "[";
    for (int i = 0; i < arr.GetSize(); ++i) {
        os << arr[i] << (i + 1 < arr.GetSize() ? ", " : "");
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, DynamicArray& arr) {
    int count = 0;
    if (!(is >> count) || count < 0) {
        return is;
    }

    for (int i = 0; i < count; ++i) {
        int val = 0;
        is >> val;
        arr.Insert(arr.GetSize(), val);
    }

    return is;
}

DynamicArray operator+(const DynamicArray& arr, int value) {
    DynamicArray result = arr;
    result += value;
    return result;
}

DynamicArray operator+(int value, const DynamicArray& arr) {
    return arr + value;
}

DynamicArray operator+(const DynamicArray& lhs, const DynamicArray& rhs) {
    DynamicArray result = lhs;
    result += rhs;
    return result;
}

bool operator==(const DynamicArray& lhs, const DynamicArray& rhs) {
    if (lhs.GetSize() != rhs.GetSize()) {
        return false;
    }
    for (int i = 0; i < lhs.GetSize(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const DynamicArray& lhs, const DynamicArray& rhs) {
    return !(lhs == rhs);
}