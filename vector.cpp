#include <iostream>
#include "D:\Security\basic_algorithm\Benchmark\Benchmark\vector.h"


MyVector::MyVector() : array(nullptr), capacity(0), size(0) {}

MyVector::~MyVector() {
        clear();
        delete[] array;
    }

MyVector::MyVector(const MyVector& other) : MyVector() {
        reserve(other.size);
        for (size_t i = 0; i < other.size; i++) {
            array[i] = other.array[i];
        }
        size = other.size;
    }

MyVector& MyVector::operator=(const MyVector& other) {
        if (this != &other) {
            clear();
            reserve(other.size);
            for (size_t i = 0; i < other.size; i++) {
                array[i] = other.array[i];
            }
            size = other.size;
        }
        return *this;
    }

void MyVector::assign(size_t count, const int& value) {
        clear();
        reserve(count);
        for (size_t i = 0; i < count; i++) {
            array[i] = value;
        }
        size = count;
    }

void MyVector::reserve(size_t newCapacity) {
        if (newCapacity > capacity) {
            int* newArray = new int[newCapacity];

            for (size_t i = 0; i < size; i++) {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }
    }

void MyVector::clear() {
        delete[] array;
        array = nullptr;
        capacity = 0;
        size = 0;
    }

void MyVector::erase(size_t position) {
        if (position >= size) {
            throw "Index out of range";
        }

        for (size_t i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;
    }

void MyVector::push_back(const int& value) {
        if (size >= capacity) {
            reserve((capacity == 0) ? 1 : capacity * 2);
        }

        array[size] = value;
        size++;
    }

void MyVector::insert(size_t position, const int& value) {
        if (position > size) {
            throw "Index out of range";
        }

        if (size >= capacity) {
            reserve((capacity == 0) ? 1 : capacity * 2);
        }

        for (size_t i = size; i > position; i--) {
            array[i] = array[i - 1];
        }

        array[position] = value;
        size++;
    }

void MyVector::resize(size_t newSize) {
        if (newSize < size) {
            size = newSize;
        }
        else if (newSize > size) {
            reserve(newSize);
            for (size_t i = size; i < newSize; i++) {
                array[i] = 0;
            }
            size = newSize;
        }
    }

void MyVector::pop_back() {
        if (size > 0) {
            size--;
        }
    }

int MyVector::find(const int& value) {
        for (size_t i = 0; i < size; i++) {
            if (array[i] == value) {
                return i;
            }

        }
        return -1;
    }


/*int main() {
    // Create two vector objects
    MyVector vec1;
    MyVector vec2;

    // Add elements to vec1 using push_back()
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // Display the elements of vec1
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size; i++) {
        std::cout << vec1.array[i] << " ";
    }
    std::cout << std::endl;

    // Copy vec1 to vec2 using assignment operator
    vec2 = vec1;

    // Modify vec2
    vec2.insert(1, 15);
    vec2.push_back(40);

    // Display the elements of vec2
    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size; i++) {
        std::cout << vec2.array[i] << " ";
    }
    std::cout << std::endl;

    // Find an element in vec2
    int index = vec2.find(15);
    if (index != -1) {
        std::cout << "Element 15 found at index " << index << " in vec2" << std::endl;
    }
    else {
        std::cout << "Element 15 not found in vec2" << std::endl;
    }

    // Resize vec2
    vec2.resize(4);

    // Display the elements of vec2 after resizing
    std::cout << "vec2 after resizing: ";
    for (size_t i = 0; i < vec2.size; i++) {
        std::cout << vec2.array[i] << " ";
    }
    std::cout << std::endl;

    // Clear vec1 and vec2
    vec1.clear();
    vec2.clear();

    return 0;
}*/
