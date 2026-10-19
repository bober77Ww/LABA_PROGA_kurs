#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

int main() {
    cout << "ЧАСТЬ 3: ШАБЛОНЫ\n";

    cout << "--- Числовой массив (int) ---\n";
    DynamicArray<int> intArr(3);
    intArr.set(0, 10);
    intArr.set(1, 50);
    intArr.set(2, -100);
    cout << "intArr: " << intArr << "\n";
    try {
        cout << "Пытаемся записать 150 (должна быть ошибка)\n";
        intArr.set(0, 150); 
    } catch (const invalid_argument& e) {
        cout << "Ошибка" << e.what() << "\n";
    }
    cout << "\n";


    cout << "--- Нечисловой массив (string) ---\n";
    DynamicArray<string> strArr(2);
    strArr.set(0, "hello");
    strArr.set(1, "world");
    cout << "strArr: " << strArr << "\n";
    cout << "\n";


    cout << "--- Расстояние между числовыми массивами ---\n";
    DynamicArray<int> arrA(3);
    arrA.set(0, 0); arrA.set(1, 0); arrA.set(2, 0);
    DynamicArray<int> arrB(3);
    arrB.set(0, 3); arrB.set(1, 4); arrB.set(2, 0);   
    cout << "arrA: " << arrA << "\n";
    cout << "arrB: " << arrB << "\n";
    cout << "Расстояние (должно быть 5): " << arrA.dist(arrB) << "\n";
    cout << "\n";


    cout << "--- Ошибка dist при разных размерах ---\n";
    DynamicArray<int> arrC(2);
    try {
        arrA.dist(arrC);
    } catch (const invalid_argument& e) {
        cout << "Ошибка " << e.what() << "\n";
    }
    cout << "\n";


    cout << "--- Ошибка dist для нечислового типа (string) ---\n";
    DynamicArray<string> strArr2(2);
    strArr2.set(0, "a"); 
    strArr2.set(1, "b");
    try {
        strArr.dist(strArr2); // Должно выбросить bad_typeid
    } catch (const bad_typeid& e) {
        cout << "Ошибка std::bad_typeid: нельзя считать расстояние между строками\n";
    } catch (const exception& e) {
        cout << "Ошибка (другое исключение): " << e.what() << "\n";
    }

    return 0;
}