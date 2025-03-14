#include "timee.h"

template <typename T>
scalar<T>::scalar() : n(0), capacity(1), data(new T[1]) {}

template <typename T>
scalar<T>::scalar(const scalar &p)
{
    n = p.n;
    capacity = p.capacity;
    data = p.data;
}

template <typename T>
scalar<T> &scalar<T>::operator=(const scalar &p)
{
    if (this != &p)
    {
        delete[] data;
        data = new T[p.n];
        for (int i = 0; i < p.n; ++i)
        {
            data[i] = p.data[i];
        }
        n = p.n;
        capacity = p.capacity;
    }
    return *this;
}

template <typename T>
int scalar<T>::size() const { return n; }

template <typename T>
void scalar<T>::push(T t)
{
    if (n == capacity)
    {
        T *temp = data;
        data = new T[capacity = 2 * capacity];
        copy(temp, temp + n, data);
        delete[] temp;
    }
    data[n++] = t;
}

template <typename T>
T &scalar<T>::operator[](int index)
{
    if (index >= n)
    {
        cout << "Error: Array index out of bound\n";
        exit(0);
    }
    return *(data + index);
}

template <typename T>
void scalar<T>::print() const
{
    for (int i = 0; i < n; i++)
    {
        cout << data[i];
    }
}

template <typename T>
void scalar<T>::print(ostream &out) const
{
    for (int i = 0; i < n; i++)
    {
        out << data[i];
    }
}

template <typename T>
void scalar<T>::clear()
{
    delete[] data;
}