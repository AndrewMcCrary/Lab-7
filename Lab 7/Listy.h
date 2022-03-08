#pragma once
#include <exception>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <cstdint>

#define ARR_SIZE 25

template <typename T>
class Listy
{
protected:
	int _size = 0;
	T data[ARR_SIZE];

public:
	Listy();
	int maxSize() { return ARR_SIZE; }
	void addItem(T var);
	T removeItem(int index);
	bool isFull();
	bool isEmpty();
	void makeEmpty();
	int size() { return this->_size; }
	bool operator==(Listy* l);
	bool operator<(Listy* l);
	bool operator>(Listy* l);
};

struct ListyOverflow : public std::exception
{
	const char* what() const throw ()
	{
		return "The list is full.";
	}
};

struct ListyUnderflow : public std::exception
{
	const char* what() const throw ()
	{
		return "The list is empty.";
	}
};

struct IndexOutOfBounds : public std::exception
{
	const char* what() const throw ()
	{
		return "Index out of bounds.";
	}
};

template<typename T>
inline Listy<T>::Listy()
{
	for (int i = 0; i < this->maxSize(); i++) {
		this->data[i] = INT_MIN;
	}
}

template<typename T>
inline void Listy<T>::addItem(T var)
{
	if (this->isFull())
		throw ListyOverflow();
	this->data[_size++] = var;
	if (std::is_same<int, T>())
		std::sort(data, data + (sizeof(int) * this->size()));
}

template<typename T>
inline T Listy<T>::removeItem(int index)
{
	if(isEmpty())
		throw ListyUnderflow();
	if(index > 24)
		throw IndexOutOfBounds();
	if(data[index] == INT_MIN){
		// no value at index, nothing changes
		return NULL;
	}
	T retVal = data[index];
	for(int x = index; x < _size-1; x++){
		data[x] = data[x + 1];
	}
	data[_size-1] = INT_MIN;
	_size--;
	return retVal;
}

template<typename T>
inline bool Listy<T>::isFull()
{
	return this->size() >= ARR_SIZE;
}

template<typename T>
inline bool Listy<T>::isEmpty()
{
	return this->size() <= 0;
}

template<typename T>
inline void Listy<T>::makeEmpty()
{
	this->_sizesize = 0;
	return;
}

template<typename T>
inline bool Listy<T>::operator==(Listy* l)
{
	if (this->size() != l->size()) {
		return false;
	}

	for (int i = 0; i < l.size; i++) {
		if (this->data != l->data) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline bool Listy<T>::operator<(Listy* l)
{
	int smaller;
	if (this->size < l->size) {
		smaller = this->size;
	} else {
		smaller = l->size;
	}
	for (int i = 0; i < smaller;i++) {
		if (this->data != l->data && this->data < l->data) {
			return true;
		}
	}
	return false;
}

template<typename T>
inline bool Listy<T>::operator>(Listy* l)
{
	int smaller;
	if (this->size < l->size) {
		smaller = this->size;
	} else {
		smaller = l->size;
	}
	for (int i = 0; i < smaller;i++) {
		if (this->data != l->data && this->data > l->data) {
			return true;
		}
	}
	return false;
}