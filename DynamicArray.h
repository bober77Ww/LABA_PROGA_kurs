#pragma once
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <cmath>
#include <utility>
using namespace std;

// дописать
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
    //конструктор копирования
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    //оператор присваивания копированием
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    //move-конструктор
    DynamicArray(DynamicArray&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    //move-оператор присваивания
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка set: индекс вне границ");
        }
        if constexpr (is_integral_v<T>) {
            if (value < -100 || value > 100) {
                throw invalid_argument("Ошибка set: целое число вне диапозона [-100, 100]");
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

    void append(const T& value) {
        if constexpr (is_integral_v<T>) {
            if (value < -100 || value > 100) {
                throw invalid_argument("Ошибка append: значение вне диапозона [-100, 100]");
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


    class Proxy {
    private:
        DynamicArray& arr;
        int index;
    public:
        Proxy(DynamicArray& a, int i) : arr(a), index(i) {
        }


        operator T() const {
            return arr.get(index);
        }


        void operator=(const T& value) {
            arr.set(index, value);
        }
    };


    Proxy operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Ошибка []: индекс все границ");
        }
        return Proxy(*this, index);
    }


    T operator[](int index) const {
        return get(index);
    }


    bool operator==(const DynamicArray& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }



    bool operator!=(const DynamicArray& other) const {
        if (*this == other) {
            return false;
        } else {
            return true;
        }
    }


    DynamicArray& operator+=(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T otherValue;
            if (i < other.size) {
                otherValue = other.data[i];
            } else {
                otherValue = T();
            }

            T new_val = data[i] + otherValue;
            if constexpr (is_integral_v<T>) {
                if (new_val < -100 || new_val > 100) {
                    throw invalid_argument("Ошибка +=: результат вне диапозона [-100, 100]");
                }
            }
            data[i] = new_val;
        }
        return *this;
    }


    DynamicArray& operator-=(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T otherValue;
            if (i < other.size) {
                otherValue = other.data[i];
            } else {
                otherValue = T();
            }

            T new_val = data[i] - otherValue;
            if constexpr (is_integral_v<T>) {
                if (new_val < -100 || new_val > 100) {
                    throw invalid_argument("Ошибка -=: результат вне диапозона [-100, 100]");
                }
            }
            data[i] = new_val;
        }
        return *this;
    }


    DynamicArray& operator+=(const T& scalar) {
        for  (int i = 0; i < size; i++) {
            T new_val = data[i] + scalar;
            if constexpr (is_integral_v<T>) {
                if (new_val < - 100 || new_val > 100) {
                    throw invalid_argument("Ошибка -= scalar: результат вне диапозона [-100, 100]");
                }
            }
            data[i] = new_val;
        }
        return *this;
        
    }


    T* begin() {
        return data;
    }


    const T* begin() const {
        return data;
    }


    T* end() {
        return data + size;
    }


    const T* end() const {
        return data + size;
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