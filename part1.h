#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:

    DynamicArray(int newSize) {
        if (newSize <= 0) {
            cout << "\n";
            size = 1;
        } else {
            size = newSize;
        }
        data = new int[size]();
    }

    ~DynamicArray() {
        delete[] data;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            cout << "dopisat" << index << "dopisat\n";
            return;
        }
        if (value < -100 || value > 100) {
            cout << "dopisat" << value << "dopisat\n";
            return;
        }
        data[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            cout << "dopisat" << index << "\n";
            return 0;
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
            cout << "dopisat" << value << "\n";
            return;
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