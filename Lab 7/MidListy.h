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
    void removeItem(int index);
    int getMinIndex() { return minIndex; }
    int getMaxIndex() { return maxIndex; }
    int size();
};

template<typename T>
inline void MidListy<T>::addItem(T var)
{
    if (this->getMaxIndex() - this->getMinIndex() > this->maxSize())
        throw ListyOverflow();
    
    // max is empty, min contains first value
    
    if (this->getMaxIndex() >= this->maxSize()) {
        this->data[this->maxSize() - 1] = var;
    }
    else {
        this->data[maxIndex++] = var;
    }

    return;
}

template<typename T>
inline void MidListy<T>::removeItem(int index)
{
    if (this->size() == 0)
        throw ListyUnderflow();
    this->data[this->getMinIndex() + index] = INT_MIN;

    for (int i = this->getMinIndex() + index; i < this->getMaxIndex() - 1; i++)
        this->data[i] = this->data[i + 1];
    this->data[--this->maxIndex] = INT_MIN;
}

template<typename T>
inline int MidListy<T>::size() {
    return this->maxIndex - this->minIndex;
}