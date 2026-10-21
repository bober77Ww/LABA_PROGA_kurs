#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

int main() {
    cout << "ЧАСТЬ 4: ОПЕРАТОРЫ\n";

    cout << "--- Оператор [] ---\n";
    DynamicArray<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << "   arr: " << arr << "\n";
    cout << "   arr[1] равно: " << arr[1] << "\n";
    try {
        cout << "Пытаемся записать arr[0] = 150 (должна быть ошибка)\n";
        arr[0] = 150; 
    } catch (const invalid_argument& e) {
        cout << "Поймано " << e.what() << "\n";
    }
    cout << "\n";


    cout << "--- Операторы == и != ---\n";
    DynamicArray<int> arr2(3);
    arr2[0] = 10;
    arr2[1] = 20;
    arr2[2] = 30;
    DynamicArray<int> arr3(3);
    arr3[0] = 10;
    arr3[1] = 20;
    arr3[2] = 99;
    cout << "   arr == arr2: " << (arr == arr2) << "\n"; // true
    cout << "   arr != arr3: " << (arr != arr3) << "\n"; // true
    cout << "\n";


    cout << "--- Операторы += и -= ---\n";
    DynamicArray<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    DynamicArray<int> b(3);
    b[0] = 5;
    b[1] = 5;
    b[2] = 5;
    
    a += b;
    cout << "   a += b" << a << "\n";
    a -= b;
    cout << "   a -= b" << a << "\n";
    cout << "\n";


    cout << "--- Итераторы (цикл for) ---\n";
    DynamicArray<int> nums(4);
    nums[0] = 1;
    nums[1] = 2; 
    nums[2] = 3; 
    nums[3] = 4;
    cout << "Чтение (const auto&):  ";
    for (const auto& x : nums) {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Изменение (auto&): прибавим 100 \n";
    for (auto& x : nums) {
        x = x + 100;
    }
    cout << "Результат: " << nums << "\n";


    return 0;
}