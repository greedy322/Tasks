#pragma once

#include <iostream>

class DynamicArray {
public:
    class iterator {
    public:
        iterator(int* ptr = nullptr) : ptr_(ptr) {}
        int& operator*() const { return *ptr_; }
        int* operator->() const { return ptr_; }
        iterator& operator++() { ++ptr_; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++ptr_; return tmp; }
        iterator& operator--() { --ptr_; return *this; }
        iterator operator--(int) { iterator tmp = *this; --ptr_; return tmp; }
        bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }

    private:
        int* ptr_ = nullptr;
        friend class DynamicArray;
    };

    class const_iterator {
    public:
        const_iterator(const int* ptr = nullptr) : ptr_(ptr) {}
        const int& operator*() const { return *ptr_; }
        const int* operator->() const { return ptr_; }
        const_iterator& operator++() { ++ptr_; return *this; }
        const_iterator operator++(int) { const_iterator tmp = *this; ++ptr_; return tmp; }
        const_iterator& operator--() { --ptr_; return *this; }
        const_iterator operator--(int) { const_iterator tmp = *this; --ptr_; return tmp; }
        bool operator==(const const_iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const const_iterator& other) const { return ptr_ != other.ptr_; }

    private:
        const int* ptr_ = nullptr;
        friend class DynamicArray;
    };

    iterator begin() { return iterator(data_); }
    iterator end() { return iterator(data_ + size_); }
    const_iterator begin() const { return const_iterator(data_); }
    const_iterator end() const { return const_iterator(data_ + size_); }
    const_iterator cbegin() const { return const_iterator(data_); }
    const_iterator cend() const { return const_iterator(data_ + size_); }

    DynamicArray() = default;
    DynamicArray(const int* data, int size);
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept; 
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other) noexcept;

	int GetSize() const { return size_; }

	int& operator[](int index);
	const int& operator[](int index) const;

	void Swap(DynamicArray& other);

	int Find(int value) const;
	void Sort();

	bool Insert(int index, int value);
	bool RemoveAt(int index);
	bool Remove(int value);
	int RemoveAll(int value);

	int GetMin() const;
	int GetMax() const;

    iterator Insert(iterator pos, int value);
    iterator Erase(iterator pos);
    iterator Erase(iterator first, iterator last);

	DynamicArray& operator+=(int value);
	DynamicArray& operator+=(const DynamicArray& other);

private:
	int* data_ = nullptr;
	int size_ = 0;
};

std::ostream& operator<<(std::ostream& os, const DynamicArray& arr);
std::istream& operator>>(std::istream& is, DynamicArray& arr);

DynamicArray operator+(const DynamicArray& arr, int value);
DynamicArray operator+(int value, const DynamicArray& arr);

DynamicArray operator+(const DynamicArray& lhs, const DynamicArray& rhs);

bool operator==(const DynamicArray& lhs, const DynamicArray& rhs);
bool operator!=(const DynamicArray& lhs, const DynamicArray& rhs);
