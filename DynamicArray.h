#pragma once
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <cmath>
using namespace std;


template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:

    explicit DynamicArray(int newSize) {
        if (newSize <= 0) {
           throw invalid_argument("Размер массива должен быть больше нуля");
        }
        size = newSize;
        data = new T[size]();
    }

    ~DynamicArray() {
        delete[] data;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка set: индекс вне границ");
        }
        if constexpr (is_integral_v<T>) {
            if (value < -100 || value > 100) {
                throw invalid_argument("Ошибка set: целое число не в диапозоне [-100, 100]");
            }
        }
        data[index] = value;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка get: индекс вне границ массива ");
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
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    void append(const T& value) {
        if constexpr (is_integral_v<T>) {
            if (value < -100 || value > 100) {
                throw invalid_argument("Ошибка append: значение не в диапозоне [-100, 100]");
            }
        }
        T* newData = new T[size + 1];
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
            T otherValue = (i < other.size) ? other.data[i] : T();
            data[i] = data[i] + otherValue;
        }
    }

    void sub(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T otherValue = (i < other.size) ? other.data[i] : T();
            data[i] = data[i] - otherValue;
        }
    }

    double dist(const DynamicArray& other) const {
        if (size != other.size) {
            throw invalid_argument("Ошибка dist: размеры массивов не совпадают.");
        }
        if constexpr (is_arithmetic_v<T>) {
            double sum = 0.0;
            for (int i = 0; i < size; i++) {
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum += diff * diff;
            }
            return sqrt(sum);
        } else {
            throw bad_typeid();
        }
    }

    int getSize() const {
        return size;
    }
};


template <typename T>
ostream& operator<<(ostream& os, const DynamicArray<T>& arr) {
    os << "[ ";
    for (int i = 0; i < arr.getSize(); i++) {
        os << arr.get(i) << " ";
    }
    os << "]";
    return os;
}