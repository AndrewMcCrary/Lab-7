#pragma once
#include <exception>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <cstdint>

template <typename T>
class Listy
{
protected:
	int _size;
	T data[25];

public:
	int maxSize() { return 25; }
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
inline void Listy<T>::addItem(T var)
{
	if (this->isFull())
		throw ListyOverflow();
	this.data[_size++] = var;
	if (std::is_same<int, T>)
		std::sort(data, data + (sizeof(int) * this->size()));
}

template<typename T>
inline T Listy<T>::removeItem(int index)
{
	if(isEmpty())
		throw ListyUnderflow();
	if(index > 24)
		throw IndexOutOfBounds();
	if(data[index] == NULL){
		return NULL;
	}
	T retVal = data[index];
	for(int x = index; x < _size-1; x++){
		data[x] == data[x + 1];
	}
	data[_size-1] = NULL;
	_size--;
	return retVal;
}

template<typename T>
inline bool Listy<T>::isFull()
{
	return this->size() >= 25;
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