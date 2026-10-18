#include <iostream>
#include "part1.h"
using namespace std;

int main() {

    cout << "--- Task 1 ---\n";
    DynamicArray arr1(5);
    arr1.set(0, 10);        
    arr1.set(1, -50);
    arr1.set(2, 100);
    arr1.set(3, -100);
    arr1.set(4, 0);
    cout << "arr1: ";
    arr1.print();
    cout << "Element witn index 2: " << arr1.get(2) << "\n";

    arr1.set(7, 5);
    arr1.set(0, 500);
    cout << "After errors arr1 intact: ";
    arr1.print();
    cout << "\n";


    cout << "--- Task 2: ---\n";
    DynamicArray arr2 = arr1;
    cout << "arr2 (copy): ";
    arr2.print();
    arr2.set(0, 99);
    cout << "arr2 after ..: ";
    arr2.print();
    cout << "arr1 не изменился:   ";
    arr1.print();
    cout << "\n";


    cout << "--- Task 3 ---\n";
    cout << "Размер arr1 был:  " << arr1.getSize() << "\n";
    arr1.append(42);
    cout << "Размер arr1 стал: " << arr1.getSize() << "\n";
    cout << "arr1: ";
    arr1.print();
    arr1.append(200);
    cout << "\n";


    cout << "--- Task 4 ---\n";
    DynamicArray arrA(3);
    arrA.set(0, 10);
    arrA.set(1, 20);
    arrA.set(2, 30);

    DynamicArray arrB(5);
    arrB.set(0, 1);
    arrB.set(1, 2);
    arrB.set(2, 3);
    arrB.set(3, 4);
    arrB.set(4, 5);
    cout << "arrA: "; arrA.print();
    cout << "arrB: "; arrB.print();
    arrA.add(arrB);
    cout << "arrA + arrB: "; arrA.print();
    arrA.sub(arrB);
    cout << "arrA - arrB: "; arrA.print();

    DynamicArray arrC(2);
    arrC.set(0, 5);
    arrC.set(1, 5);
    cout << "arrC: "; arrC.print();
    arrA.add(arrC);
    cout << "arrA + arrC: "; arrA.print();


    return 0;
}