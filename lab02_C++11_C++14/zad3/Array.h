#pragma once
#include <initializer_list>
#include <iostream>

template<typename T>
class Array {
public:
    Array() = default;

    Array(std::size_t size) : size(size) {
        arr = new T[size];
        for (std::size_t i = 0; i < size; ++i)
            arr[i] = T();
    }

    Array(std::initializer_list<T> list) {
        append(list);
    }

    void append(std::initializer_list<T> list) {
        std::size_t newSize = list.size() + size;
        T* newArr = new T[newSize];
        for (std::size_t i = 0; i < size; ++i) 
            newArr[i] = arr[i];

        std::size_t i = size;
        for (auto el : list)
            newArr[i++] = el;
        
        delete []arr;
        arr = newArr;
        size = newSize;
    }

    void print() const {
        for (std::size_t i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
    }
private:
    std::size_t size = 0;
    T* arr = nullptr;
};