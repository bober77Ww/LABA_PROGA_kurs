#include <iostream>
#include <string>
#include <utility>
#include "DynamicArray.h"
using namespace std;

void processArray(DynamicArray<int> arr) {
    cout << "   Внутри функции. Размер переданного массива: " << arr.getSize() << "\n";
}

int main() {
    cout << "ЧАСТЬ 5: ПРАВИЛО ТРЁХ/ПЯТИ\n\n";

    DynamicArray<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    cout << "--- 1. Исходный массив ---" << original << "\n\n";


    cout << "--- 2. Передача по значению (Копирование) ---\n";
    cout << "   Вызываем processArray(original)...\n";
    processArray(original);
    cout << "   После вызова original цел: " << original << "\n\n";


    cout << "--- 3. Передача c перемещением (std::move) ---\n";
    cout << "   Вызываем processArray(std::move(original))...\n";
    processArray(std::move(original));
    cout << "   После вызова original 'опустошен'. Размер: " << original.getSize() << "\n\n";


    cout << "--- 4. Move-присваивание ---\n";
    DynamicArray<int> arrA(2);
    arrA[0] = 1;
    arrA[1] = 2;
    
    DynamicArray<int> arrB(4);
    arrB[0] = 9;
    arrB[1] = 9;
    arrB[2] = 9;
    arrB[3] = 9;

    cout << "   До: arrA = " << arrA << ", arrB = " << arrB << "\n";
    arrB = std::move(arrA);
    cout << "   После arrB = std::move(arrA):\n";
    cout << "   arrB (забрал ресурсы): " << arrB << "\n";
    cout << "   arrA (опустошен): размер = " << arrA.getSize() << "\n\n";


    cout << "--- 5. Защита от самоприсваивания ---\n";
    DynamicArray<int> selfArr(2);
    selfArr[0] = 5;
    selfArr[1] = 5;
    selfArr = selfArr; 
    cout << "   После selfArr = selfArr: " << selfArr << " (всё безопасно)\n";

    return 0;
}