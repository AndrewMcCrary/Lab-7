#pragma once
#include "Listy.h"

template <typename T>
class WackyListy : public Listy<T>
{
private:

public:
    void addItem(T var);
    int size();
    T removeItem(int index);
};

inline void WackyListy<int>::addItem(int var)
{
    if (this->data[this->maxSize() / 2] != (int)NULL) {
        this->data[this->maxSize() / 2] = var;
        return;
    }

    int starting = 0;
    int midPoint = this->maxSize() / 2;

    do
    {
        if (midPoint != (int)NULL) {
            this->data[midPoint] = var;
            break;
        }

        if (this->data[midPoint] > var) {

        }
        else {
            if (this->data[this->])
        }
    } while (void);

}

template<typename T>
inline int WackyListy<T>::size()
{
    int count = 0;
    for(int x = 0; x <= 24; x++){
        if(data[x] != NULL){
            count++;
        }
    }
    return count;
}

template<typename T>
inline T WackyListy<T>::removeItem(int index)
{
    if (isEmpty()) {
        throw ListyUnderflow;
    }
    if (data[index] == NULL) {
        return NULL;
    }
    else {
        T retval = data[index];
        data[index] = NULL;
        return retVal;
    }
}
