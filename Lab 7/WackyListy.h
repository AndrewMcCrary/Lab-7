#pragma once
#include "Listy.h"

template <typename T>
class WackyListy : public Listy<T>
{
private:
    void addItemRecur(int var, int midPoint, int prevMidpoint);
public:
    void addItem(int var);
    int size();
    T removeItem(int index);
};

template<typename T>
inline void WackyListy<T>::addItemRecur(int var, int midPoint, int prevMidpoint)
{
    if (this->data[midPoint] == INT_MIN) {
        this->data[midPoint] = var;
        return;
    }
    else if (midPoint == prevMidpoint) {
        // move shit around
        bool right = 0;
        int rightNullIndex;
        int leftNullIndex;
        for (rightNullIndex = midPoint; rightNullIndex < this->size(); ++rightNullIndex) {
            if (this->data[rightNullIndex] == INT_MIN) {
                right = true;
                break;
            }
        }

        for (leftNullIndex = midPoint; leftNullIndex > 0; leftNullIndex--) {
            if (this->data[leftNullIndex] == INT_MIN) {
                right = false;
                break;
            }
        }

        if (right) {
            for (; midPoint < rightNullIndex; rightNullIndex--) {
                this->data[rightNullIndex] = this->data[rightNullIndex - 1];
            }
            this->data[midPoint] = var;
        }
        else {
            for (; midPoint > leftNullIndex; leftNullIndex++) {
                this->data[leftNullIndex] = this->data[leftNullIndex + 1];
            }
            this->data[midPoint] = var;
        }

    }
    else if (var > this->data[midPoint]) {
        this->addItemRecur(var, midPoint + (abs(midPoint - prevMidpoint) / 2), midPoint);
    }
    else if (var <= this->data[midPoint]) {
        this->addItemRecur(var, midPoint - (abs(midPoint - prevMidpoint) / 2), midPoint);
    }
}

inline void WackyListy<int>::addItem(int var)
{
    if (this->size() == this->maxSize())
        throw ListyOverflow();

    this->addItemRecur(var, this->maxSize() / 2, NULL);
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
    if (this->isEmpty()) {
        throw ListyUnderflow;
    }
    if (this->data[index] == INT_MIN) {
        return INT_MIN;
    }
    else {
        this->data[index] = INT_MIN;
        T retVal = this->data[index];
        return retVal;
    }
}
