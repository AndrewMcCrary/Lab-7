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
    int getMinIndex() { return minIndex; }
    int getMaxIndex() { return maxIndex; }
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

    if (var >= this->data[ARR_SIZE / 2]) {
        if (maxIndex >= ARR_SIZE) {
            for (int i = minIndex; i <= ARR_SIZE / 2; i++) {
                this->data[i - 1] = this->data[i];
                this->countAdding++;
            }
            this->data[ARR_SIZE / 2] = var;
            minIndex--;
        }
        else {
            for (int i = maxIndex; i > ARR_SIZE / 2; i--) {
                this->data[i] = this->data[i - 1];
                this->countAdding++;
            }
            this->data[ARR_SIZE / 2] = var;
            maxIndex++;
        }
        for (int i = ARR_SIZE / 2; i < maxIndex-1; i++) {
            if (this->data[i] > this->data[i + 1]) {
                T temp = this->data[i + 1];
                this->data[i + 1] = this->data[i];
                this->data[i] = temp;
                this->countAdding++;
            }
        }
    }
    else {
        if (minIndex == 0) {
            for (int i = maxIndex; i > ARR_SIZE / 2; i--) {
                this->data[i] = this->data[i - 1];
                this->countAdding++;
            }
            this->data[ARR_SIZE / 2] = var;
            maxIndex++;
        }
        else {
            for (int i = minIndex - 1; i < ARR_SIZE / 2; i++) {
                this->data[i] = this->data[i + 1];
                this->countAdding++;
            }
            this->data[ARR_SIZE / 2] = var;
            minIndex--;
        }
        for (int i = ARR_SIZE / 2; i > minIndex; i++) {
            if (this->data[i - 1] < this->data[i]) {
                T temp = this->data[i - 1];
                this->data[i - 1] = this->data[i];
                this->data[i] = temp;
                this->countAdding++;
            }
        }
    }

    //if (this->maxIndex != this->maxSize()) {
    //    // Insert Right
    //    this->countAdding++;
    //    this->data[maxIndex++] = var;
    //    std::sort(this->data + (sizeof(int) * this->minIndex), this->data + (sizeof(int) * this->maxIndex));
    //}
    //else {
    //    // Insert Left
    //    this->countAdding++;
    //    this->data[--minIndex] = var;
    //    std::sort(this->data + (sizeof(int) * this->minIndex), this->data + (sizeof(int) * this->maxIndex));
    //}
}

template<typename T>
inline T MidListy<T>::removeItem(int index)
{
    if (this->size() == 0) {
        throw ListyUnderflow;
    }
    if(this->data[index] == INT_MIN){
		// no value at index, nothing changes
		return INT_MIN;
	}
    T retVal = this->data[index];
    if (index >= 12){
        for (int x = index; x < maxIndex-1; x++){
            this->data[x] = this->data[x + 1];
            // move
            this->countRemoving++;
        }
        maxIndex--;
        this->data[maxIndex] = INT_MIN;
    }
    else{
        for (int x = index; x > minIndex; x--) {
            this->data[x] = this->data[x - 1];
            // move
            this->countRemoving++;
        }
        this->data[minIndex] = INT_MIN;
        minIndex++;
    }
    return retVal;
}

template<typename T>
inline int MidListy<T>::size() {
    return this->maxIndex - this->minIndex;
}