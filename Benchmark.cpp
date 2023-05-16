#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
#include "D:\Security\basic_algorithm\Benchmark\Benchmark\list.h"
#include "D:\Security\basic_algorithm\Benchmark\Benchmark\vector.h"

MyVector myVector, myvectorCopy;
MyList myList, mylistCopy;

int main() {
    const int num_sizes = 3;
    const int sizes[num_sizes] = { 1000, 10000, 100000 };

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];

        auto startTime = std::chrono::high_resolution_clock::now();
        
        for (int j = 1; j <= size; j++) {
            myVector.push_back(j);
        }
        myVector.find(size); 
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << "Execution time for MyVector find with size " << size << ": " << duration.count() << " ms" << std::endl;
 
        startTime = std::chrono::high_resolution_clock::now();
        
        for (int j = 1; j <= size; j++) {
            myList.push_back(j);
        }
        myList.find(size); 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << "Execution time for MyList find with size " << size << ": " << duration.count() << " ms" << std::endl;
        std::cout << std::endl;

        startTime = std::chrono::high_resolution_clock::now();        
        for (int j = 1; j <= size; j++) {
            myVector.push_back(j);
        }
        myVector.erase(size); 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << "Execution time for MyVector erase with size " << size << ": " << duration.count() << " ms" << std::endl;
       
        startTime = std::chrono::high_resolution_clock::now();
        for (int j = 1; j <= size; j++) {
            myList.push_back(j);
        }
        myList.erase(size); 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << "Execution time for MyList erase with size " << size << ": " << duration.count() << " ms" << std::endl;
        std::cout << std::endl;

        myvectorCopy = myVector;
        startTime = std::chrono::high_resolution_clock::now();
        for (int j = 1; j <= size; j++) {
            myVector.push_back(j);
        }
        myvectorCopy.insert(size / 2,size + 1); 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << "Execution time for MyVector insert with size " << size << ": " << duration.count() << " ms" << std::endl;

        mylistCopy = myList;
        startTime = std::chrono::high_resolution_clock::now();
        for (int j = 1; j <= size; j++) {
            myList.push_back(j);
        }
        mylistCopy.insert(size / 2, size + 1); 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::cout << "Execution time for MyList insert with size " << size << ": " << duration.count() << " ms" << std::endl;
        std::cout << std::endl;
    }


    return 0;
}