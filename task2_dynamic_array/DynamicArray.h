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

	int& operator[](int index);
	const int& operator[](int index) const;

	void Swap(DynamicArray& other);

	int Find(int value) const;

	void Sort();

	bool Insert(int index, int value);

	bool RemoveAt(int index);

	bool Remove(int value);

private:
	int* data_ = nullptr;
	int size_ = 0;
};

std::ostream& operator<<(std::ostream& os, const DynamicArray& arr);
std::istream& operator>>(std::istream& is, DynamicArray& arr);