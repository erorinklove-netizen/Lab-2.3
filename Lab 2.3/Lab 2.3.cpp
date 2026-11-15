#include <iostream>
#include "Money.h"

using namespace std;

// Структура для демонстрації розміру класу в режимі #pragma pack(1)
#pragma pack(push, 1)
class MoneyPacked {
    long nominal500, nominal200, nominal100, nominal50, nominal20, nominal10, nominal5, nominal2, nominal1;
    long coin50, coin25, coin10, coin5, coin2, coin1;
};
#pragma pack(pop)

int main()
{
    cout << "=== LAB 2.3: DEMONSTRATION OF Money CLASS ===\n\n";

    // 1. Демонстрація розміру класу
    cout << "--- 1. Class Size Demonstration ---" << endl;
    cout << "Size of Money (default alignment): " << sizeof(Money) << " bytes" << endl;
    cout << "Size of MoneyPacked (with #pragma pack(1)): " << sizeof(MoneyPacked) << " bytes" << endl << endl;

    // 2. Створення об'єктів різними способами
    cout << "--- 2. Object Creation Ways ---" << endl;
    Money m1;                                           // Конструктор за замовчуванням
    Money m2(1, 0, 2, 0, 1, 0, 0, 1, 5, 1, 0, 1, 0, 0, 0); // Конструктор ініціалізації
    Money m3 = m2;                                      // Конструктор копіювання
    Money m4 = makeMoney(0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // Фабрична функція

    cout << "m1 (default): " << m1 << endl;
    cout << "m2 (init):    " << m2 << endl;
    cout << "m3 (copy):    " << m3 << endl;
    cout << "m4 (factory): " << m4 << endl << endl;

    // 3. Інтерактивне введення з клавіатури
    cout << "--- 3. Interactive Input from Keyboard ---" << endl;
    Money mCustom;
    cin >> mCustom;
    cout << "You entered: " << mCustom << endl << endl;

    // 4. Арифметичні операції та множення на дробове число
    cout << "--- 4. Arithmetic Operations & Multiplication ---" << endl;
    Money sum = m2 + m4;
    Money diff = m4 - m2;
    Money mult = m2 * 1.5; // Множення суми на дробове число

    cout << "m2 + m4 = " << sum << endl;
    cout << "m4 - m2 = " << diff << endl;
    cout << "m2 * 1.5 = " << mult << endl << endl;

    // 5. Інкременти та декременти
    cout << "--- 5. Increments and Decrements ---" << endl;
    cout << "Initial m2: " << m2 << endl;
    cout << "++m2 (adds 1 UAH): " << ++m2 << endl;
    cout << "--m2 (subtracts 1 UAH): " << --m2 << endl;
    cout << "m2++ (adds 1 kop.): " << m2++ << endl;
    cout << "After post-increment m2: " << m2 << endl;
    cout << "m2-- (subtracts 1 kop.): " << m2-- << endl;
    cout << "After post-decrement m2: " << m2 << endl << endl;

    // 6. Робота з динамічним масивом об'єктів
    cout << "--- 6. Dynamic Array of Objects ---" << endl;
    int n = 2;
    Money* arr = new Money[n];
    arr[0] = Money(0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 500 грн
    arr[1] = Money(0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0); // 50.50 грн

    for (int i = 0; i < n; i++)
    {
        cout << "Dynamic array element #" << i + 1 << ": " << arr[i] << endl;
    }
    delete[] arr;

    cout << "\nProgram finished successfully." << endl;
    return 0;
}