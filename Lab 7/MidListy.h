#pragma once
#include "Listy.h"

template<typename T>
class MidListy : public Listy<T>
{
private: 
    int minIndex = ARR_SIZE / 2;
    int maxIndex = ARR_SIZE / 2;

public:
    void addItem(T thing);
    void addItemtwo(int var);
    void removeItem(int index);
    int getMinIndex() { return minIndex; }
    int getMaxIndex() { return maxIndex; }
    int size();
};

template<typename T>
inline void MidListy<T>::addItem(T thing)
{
    if (this->maxIndex - this->minIndex >= this->maxSize())
        throw ListyOverflow();
    if (this->minIndex == this->maxIndex) {
        this->data[this->maxIndex++] = thing;
        return;
    }

    for (int i = this->getMinIndex(); i < this->getMaxIndex(); i++) {
        if (this->data[i] >= thing) {
            if (this->getMinIndex() > 0) {
                // shift all back
                for (int j = this->getMinIndex() - 1; j < i; j++)
                    this->data[j] = this->data[j + 1];
                this->data[i] = thing;
                this->minIndex--;
                break;
            }
            else {
                for (int j = this->getMaxIndex(); j > i; j--)
                    this->data[j] = this->data[j - 1];
                this->data[i] = thing;
                this->maxIndex++;
                break;
            }
        }
    }
}

template<typename T>
inline void MidListy<T>::addItemtwo(int var)
{
    if (this->maxIndex - this->minIndex >= this->maxSize())
        throw ListyOverflow();

    if (this->maxIndex == this->minIndex) {
        this->data[this->maxIndex++] = var;
        return;
    }

    int i;
    for (i = this->minIndex; i < this->maxIndex; i++) {
        if (this->data[i] >= var)
        {
            i--;
            break;
        }
    }




    if (this->minIndex != 0 && i == this->minIndex && var <= this->data[i]) { // Insert left no shift
        this->data[--minIndex] = var;
        this->countAdding++;
    }
    else if (this->maxIndex == i) { // Insert right no shift    
        this->data[maxIndex++] = var;
        this->countAdding++;
    }
    else if (this->minIndex > 0) { // Insert middle shift left
        for (int j = this->minIndex - 1; j <= i; j++) {
            this->data[j - 1] = this->data[j];
            this->countAdding++;
        }
        this->data[i] = var;
        this->minIndex--;
    }
    else { // Insert middle shift right
        for (int j = this->maxIndex - 1; j > i; j--) {
            this->data[j] = this->data[j - 1];
            this->countAdding++;
        }
        this->data[i] = var;
        this->maxIndex++;
    }
}



template<typename T>
inline void MidListy<T>::removeItem(int index)
{
    if (this->size() == 0)
        throw ListyUnderflow();
    this->data[this->getMinIndex() + index] = INT_MIN;

    for (int i = this->getMinIndex() + index; i < this->getMaxIndex() - 1; i++) {
        this->data[i] = this->data[i + 1];
        this->countRemoving++;
    }
    this->data[--this->maxIndex] = INT_MIN;
}

template<typename T>
inline int MidListy<T>::size() {
    return this->maxIndex - this->minIndex;
}