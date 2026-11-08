#pragma once

#include <iostream>

class DynamicArray {
public:
	DynamicArray() = default;
	DynamicArray(const int* data, int size);
	DynamicArray(const DynamicArray& other);
	~DynamicArray();

	DynamicArray& operator=(const DynamicArray& other);

	int GetSize() const { return size_; }



private:
	int* data_ = nullptr;
	int size_ = 0;
};