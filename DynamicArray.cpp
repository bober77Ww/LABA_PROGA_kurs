#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main() {

    cout << "ЧАСТЬ 2: ПРОВЕРКА ИСКЛЮЧЕНИЙ\n";
    
    cout << "--- Проверка invalid_arguments ---\n";
    DynamicArray arr(3);
    try{
        cout << "Пытаемся записать число > 100\n";
        arr.set(0, 500);
        cout << "Это сообщение не напечатается\n";
    }
    catch (invalid_argument& e) {
        cout << "Ошибка: " << e.what() << "\n";
    }
    cout << "\n";


    cout << "--- Проверка out_of_range ---\n";
    try{
        cout << "Пытаемся прочитать элемент c индексом 10\n";
        int value = arr.get(90);
        cout << "Значение: " << value << "\n";
    }
    catch (out_of_range& e) {
        cout << "Ошибка: " << e.what() << "\n";
    }
    cout << "\n";


    cout << "--- Проверка bad_alloc ---\n";
    try{
        cout << "Пытаемся создать массив на 2000000000 элементов\n";
        DynamicArray hugeArray(2000000000);
        cout << "Y вас мощный комп\n";
    }
    catch (bad_alloc& e) {
        cout << "Ошибка: He удалось выделить память (bad_alloc)\n";
    }
    cout << "\n";

    
    cout << "Программа продолжает работать: \n";
    arr.set(0,42);
    cout << "Успешно записали 42 в arr[0]\n";
    cout << "Массив: ";
    arr.print();

    return 0;
}