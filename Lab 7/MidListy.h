#pragma once
#include "Listy.h"

template<typename T>
class MidListy : public Listy<T>
{
private: 
    int minIndex = ARR_SIZE / 2;
    int maxIndex = ARR_SIZE / 2;

public:
    void addItem(T var);
    T removeItem(int index);
    int size();
        
};

template<typename T>
inline void MidListy<T>::addItem(T var)
{
    if (this->isFull())
        throw ListyOverflow();
    if (this->isEmpty()) {
        this->data[maxIndex++] = var;
        return;
    }

    if (this->maxIndex != this->maxSize()) {
        // Insert Right
        this->data[maxIndex++] = var;
        std::sort(this->data + (sizeof(int) * this->minIndex), this->data + (sizeof(int) * this->maxIndex));
    }
    else {
        // Insert Left
        this->data[--minIndex] = var;
        std::sort(this->data + (sizeof(int) * this->minIndex), this->data + (sizeof(int) * this->maxIndex));
    }
}

template<typename T>
inline T MidListy<T>::removeItem(int index)
{
    if (this->size() == 0) 
        throw ListyUnderflow;
    if(this->data[index] == INT_MIN){
		// no value at index, nothing changes
		return INT_MIN;
	}
    T retVal = this->data[index];
    if (index >= 12){
        for (int x = index; x < maxIndex-1; x++){
            this->data[x] = this->data[x + 1];
        }
        this->data[--maxIndex] = INT_MIN;
    }
    else{
        for (int x = index; x > minIndex; x--) {
            this->data[x] = this->data[x - 1];
        }
        this->data[minIndex++] = INT_MIN;
    }
    return retVal;
}

template<typename T>
inline int MidListy<T>::size() {
    return this->maxIndex - this->minIndex;
}