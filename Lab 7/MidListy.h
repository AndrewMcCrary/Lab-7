#pragma once
#include "Listy.h"

template<typename T>
class MidListy : public Listy<T>
{
private: 
    T data = Listy();
    int minIndex = 12;
    int maxIndex = 12;

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
        data[maxIndex++] = var;
        return;
    }

    if (this->maxIndex != 25) {
        // Insert Right
        this->data[maxIndex++] = var;
        std::sort(data + (sizeof(int) * this->minIndex), data + (sizeof(int) * this->maxIndex));
    }
    else {
        // Insert Letf
        this->data[--minIndex] = var;
        std::sort(data + (sizeof(int) * this->minIndex), data + (sizeof(int) * this->maxIndex));
    }
}

template<typename T>
inline T MidListy<T>::removeItem(int index)
{
    if (isEmpty()) 
        throw ListyUnderflow;
    if (index > size()) 
        throw IndexOutOfBounds;

}

template<typename T>
inline int MidListy<T>::size() {
    return this->maxIndex - this->minIndex;
}
