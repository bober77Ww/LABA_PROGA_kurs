#include <iostream>
#include <stdexcept>
#include <algorithm>

class DynamicArray {
private:
    int* data;  // Указатель на данные
    int size;   // Размер массива

public:
    // === ЗАДАНИЕ 1 ===
    
    // Конструктор, получающий на вход размер массива
    DynamicArray(int size) : size(size) {
        if (size < 0) {
            throw std::invalid_argument("Размер массива не может быть отрицательным.");
        }
        data = new int[size](); // Инициализируем нулями
    }

    // Деструктор
    ~DynamicArray() {
        delete[] data;
    }

    // Сеттер: проверка индекса и значения [-100, 100]
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Ошибка сеттера: индекс выходит за границы массива.");
        }
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Ошибка сеттера: значение должно быть в промежутке от -100 до 100.");
        }
        data[index] = value;
    }

    // Геттер: проверка индекса
    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Ошибка геттера: индекс выходит за границы массива.");
        }
        return data[index];
    }

    // Функция вывода всех значений массива
    void print() const {
        std::cout << "[ ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << (i < size - 1 ? ", " : " ");
        }
        std::cout << "]\n";
    }

    // === ЗАДАНИЕ 2 ===
    
    // Конструктор копирования
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // === ЗАДАНИЕ 3 ===
    
    // Добавление значения в конец с расширением размера
    void append(int value) {
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Ошибка append: значение должно быть в промежутке от -100 до 100.");
        }
        
        int* newData = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        
        delete[] data;
        data = newData;
        size++;
    }

    // === ЗАДАНИЕ 4 ===
    
    // Сложение массивов (элемент за элементом)
    void add(const DynamicArray& other) {
        // Размер исходного массива не изменяется, проходим только по его размеру
        for (int i = 0; i < size; ++i) {
            int otherVal = (i < other.size) ? other.data[i] : 0; // Недостающие = 0
            data[i] += otherVal;
        }
    }

    // Вычитание массивов (элемент за элементом)
    void sub(const DynamicArray& other) {
        for (int i = 0; i < size; ++i) {
            int otherVal = (i < other.size) ? other.data[i] : 0; // Недостающие = 0
            data[i] -= otherVal;
        }
    }

    // Вспомогательный метод для получения размера (удобно для демонстрации)
    int getSize() const {
        return size;
    }
};


// === ДЕМО ВСЕХ 4 ЗАДАНИЙ ===

int main() {
    try {
        std::cout << "--- Задание 1: Базовые операции ---\n";
        DynamicArray arr1(5);
        arr1.set(0, 10);
        arr1.set(1, -50);
        arr1.set(2, 100);
        arr1.set(3, -100);
        arr1.set(4, 0);
        
        std::cout << "arr1: ";
        arr1.print();
        std::cout << "Получение элемента по индексу 2: " << arr1.get(2) << "\n\n";

        // Демонстрация проверок
        std::cout << "Проверка границ и значений:\n";
        try { arr1.set(5, 10); } catch (const std::exception& e) { std::cout << "  " << e.what() << "\n"; }
        try { arr1.set(0, 150); } catch (const std::exception& e) { std::cout << "  " << e.what() << "\n"; }
        try { arr1.get(-1); } catch (const std::exception& e) { std::cout << "  " << e.what() << "\n"; }


        std::cout << "\n--- Задание 2: Конструктор копирования ---\n";
        DynamicArray arr2 = arr1; // Вызов конструктора копирования
        std::cout << "arr2 (копия arr1): ";
        arr2.print();
        
        arr2.set(0, 99); // Изменяем копию
        std::cout << "arr2 после изменения индекса 0: ";
        arr2.print();
        std::cout << "arr1 (должен остаться неизменным): ";
        arr1.print();


        std::cout << "\n--- Задание 3: Добавление в конец (append) ---\n";
        arr1.append(42);
        std::cout << "arr1 после добавления 42: ";
        arr1.print();
        
        try { arr1.append(101); } catch (const std::exception& e) { std::cout << "  " << e.what() << "\n"; }


        std::cout << "\n--- Задание 4: Сложение и вычитание ---\n";
        DynamicArray arrA(3);
        arrA.set(0, 10); arrA.set(1, 20); arrA.set(2, 30);

        DynamicArray arrB(5); // Массив больше, чем arrA
        arrB.set(0, 1); arrB.set(1, 2); arrB.set(2, 3); arrB.set(3, 4); arrB.set(4, 5);

        DynamicArray arrC(2); // Массив меньше, чем arrA
        arrC.set(0, 5); arrC.set(1, 5);

        std::cout << "arrA: "; arrA.print();
        std::cout << "arrB: "; arrB.print();
        std::cout << "arrC: "; arrC.print();

        arrA.add(arrB);
        std::cout << "arrA после arrA.add(arrB) (лишние элементы arrB игнорируются): "; 
        arrA.print(); // Ожидается: 11, 22, 33

        arrA.sub(arrB);
        std::cout << "arrA после arrA.sub(arrB) (возврат к исходным): "; 
        arrA.print(); // Ожидается: 10, 20, 30

        arrA.add(arrC);
        std::cout << "arrA после arrA.add(arrC) (недостающие элементы arrC = 0): "; 
        arrA.print(); // Ожидается: 15, 25, 30

    } catch (const std::exception& e) {
        std::cerr << "Непредвиденная ошибка: " << e.what() << "\n";
    }

    return 0;
}