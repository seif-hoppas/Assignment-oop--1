#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int default_value = 3;

template<typename T>
class Array
{
    private:
        int its_size;
        T* pType;
    public:
        Array(int size);// constructor to inilize size.
        Array(const Array& rhs);// copy constructor.
        ~Array(){delete[] pType;}// destructor to delete the pointer.
        T& operator[](int index){return pType[index];}// overloading [] to get the particular element
        const T& operator[](int index) const{return pType[index];}// overloading [] to get the particular element
        Array& operator=(const Array& rhs);// ovrloaded assignment operator
        int Size() const{return its_size;}// function to know the size.
};

template<typename T>// declaring template
Array<T>::Array(int size):
its_size(size)
{
    pType = new int[its_size];
    for(int i = 0; i < size; i++)
        pType[i] = (int)0;
}

template<typename T>// declaring template
Array<T>::Array(const Array& rhs)
{
    its_size = rhs.Size();
    pType = new int[its_size];
    for(int i = 0; i < its_size; i++)
        pType[i] = rhs[i];
}

template<typename T>// declaring template
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if(this == &rhs)
        return *this;
    delete[] pType;
    its_size = rhs.Size();
    pType = new int[its_size];
    for(int i = 0; i < its_size;i++) 
    {
        pType[i] = rhs[i];
    }
    return *this;
}

int main() {
    
    return 0;
}