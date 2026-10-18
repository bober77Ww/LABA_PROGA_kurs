#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:

    DynamicArray(int newSize) {
        if (newSize <= 0) {
           throw invalid_argument("Размер массива должен быть больше нуля");
        }
        size = newSize;
        data = new int[size]();
    }

    ~DynamicArray() {
        delete[] data;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка set: индекс вне границ");
        }
        if (value < -100 || value > 100) {
            throw invalid_argument("Ошибка set: значение не в диапозоне [-100, 100]");
        }
        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка get: индекс вне границ");
        }
        return data[index];
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "]\n";
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    void append(int value) {
        if (value < -100 || value > 100) {
            throw invalid_argument("Ошибка append: значение не в диапозоне [-100, 100]");
        }
        int* newData = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        size = size + 1;
    }

    void add(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            int otherValue = 0;
            if (i < other.size) {
                otherValue = other.data[i];
            }
            data[i] = data[i] + otherValue;
        }
    }

    void sub(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            int otherValue = 0;
            if (i < other.size) {
                otherValue = other.data[i];
            }
            data[i] = data[i] - otherValue;
        }
    }

    int getSize() const {
        return size;
    }
};