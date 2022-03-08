#pragma once
#include "Listy.h"

template <typename T>
class WackyListy : public Listy<T>
{
private:

public:
    void addItem(int var);
    int size();
    T removeItem(int index);
};

inline void WackyListy<int>::addItem(int var) {
    if (this->size() == 0) {
        this->data[this->maxSize() / 2] = var;
        return;
    }

    int upperBound, lowerBound;

    for (upperBound = 0; this->data[upperBound] < var && upperBound < this->maxSize() - 1; upperBound++);
    for (lowerBound = upperBound; this->data[lowerBound - 1] == INT_MIN && lowerBound > 0; lowerBound--);

    if (upperBound - lowerBound) {
        this->data[(upperBound + lowerBound) / 2] = var;
        return;
    }

    // The bounds would be the same if there is no space

    // Check if shift right is possible
    int shiftIndex = -1;
    for (int i = upperBound; i < this->maxSize(); i++) {
        if (this->data[i] == INT_MIN) {
            shiftIndex = i;
            break;
        }
    }

    if (shiftIndex == -1) {
        // Shift left
        for (int i = upperBound; i >= 0; i--)
            if (this->data[i] == INT_MIN) {
                shiftIndex = i;
                break;
            }

        for (int i = shiftIndex; i < upperBound; i++)
            this->data[i] = this->data[i + 1];
        this->data[upperBound] = var;
        // moved item
        this->countAdding++;
    }
    else {
        // Shift right
        for (int i = shiftIndex; i > upperBound; i--)
            this->data[i] = this->data[i - 1];
        this->data[upperBound] = var;
        // moved item
        this->countAdding++;
    }

}

template<typename T>
inline int WackyListy<T>::size()
{
    int count = 0;
    for(int x = 0; x < this->maxSize(); x++) {
        if(this->data[x] != INT_MIN){
            count++;
        }
    }
    return count;
}

template<typename T>
inline T WackyListy<T>::removeItem(int index)
{
    /*if (this->isEmpty()) 
        throw ListyUnderflow;*/
    if (this->data[index] == INT_MIN) {
        return INT_MIN;
    }
    else {
        this->data[index] = INT_MIN;
        T retVal = this->data[index];
        return retVal;
        // no swaps/comparisons, count stays 0!
    }
}
