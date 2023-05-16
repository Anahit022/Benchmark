#ifndef MYVECTOR_H
#define MYVECTOR_H

struct MyVector {
    int* array;
    size_t capacity;
    size_t size;

    MyVector();
    ~MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    void assign(size_t count, const int& value);
    void reserve(size_t newCapacity);
    void clear();
    void erase(size_t position);
    void push_back(const int& value);
    void insert(size_t position, const int& value);
    void resize(size_t newSize);
    void pop_back();
    int find(const int& value);
};

#endif  // MYVECTOR_H
