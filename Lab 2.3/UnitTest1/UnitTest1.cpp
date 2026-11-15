#include "pch.h"
#include "CppUnitTest.h"
#include "Money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест 1: Конструктор за замовчуванням
        TEST_METHOD(TestDefaultConstructor)
        {
            Money m;
            Assert::AreEqual(0L, m.Get500());
            Assert::AreEqual(0L, m.Get1());
            Assert::AreEqual(0L, m.GetC1());
        }

        // Тест 2: Конструктор ініціалізації
        TEST_METHOD(TestInitConstructor)
        {
            // Передаємо номінали: 500, 200, 100, 50, 20, 10, 5, 2, 1 грн та монети 50, 25, 10, 5, 2, 1 коп.
            Money m(1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 500 + 100 = 600 грн
            Assert::AreEqual(1L, m.Get500());
            Assert::AreEqual(1L, m.Get100());
            Assert::AreEqual(0L, m.Get200());
        }

        // Тест 3: Конструктор копіювання
        TEST_METHOD(TestCopyConstructor)
        {
            Money m1(0, 0, 2, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0); // 200 + 5 = 205 грн
            Money m2(m1);
            Assert::AreEqual(m1.Get100(), m2.Get100());
            Assert::AreEqual(m1.Get1(), m2.Get1());
        }

        // Тест 4: Арифметична операція додавання (+)
        TEST_METHOD(TestAddition)
        {
            Money m1(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 100 грн
            Money m2(0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 200 грн
            Money sum = m1 + m2; // 300 грн

            Money expected(0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            Assert::IsTrue(sum == expected);
        }

        // Тест 5: Арифметична операція віднімання (-)
        TEST_METHOD(TestSubtraction)
        {
            Money m1(0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 500 грн
            Money m2(0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 200 грн
            Money diff = m1 - m2; // 300 грн

            Money expected(0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            Assert::IsTrue(diff == expected);
        }

        // Тест 6: Множення суми на дробове число (*)
        TEST_METHOD(TestMultiplicationByDouble)
        {
            Money m(0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 200 грн
            Money res = m * 1.5; // 300 грн

            Money expected(0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            Assert::IsTrue(res == expected);
        }

        // Тест 7: Операції інкременту та декременту
        TEST_METHOD(TestIncrementDecrement)
        {
            Money m(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 100 грн

            ++m; // Додає 1 грн -> 101 грн
            Money expectedPreInc(0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
            Assert::IsTrue(m == expectedPreInc);

            --m; // Віднімає 1 грн -> 100 грн
            Money expectedPreDec(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            Assert::IsTrue(m == expectedPreDec);
        }

        // Тест 8: Фабрична функція makeMoney
        TEST_METHOD(TestMakeMoneyFunction)
        {
            Money m = makeMoney(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); // 200 грн
            Assert::AreEqual(1L, m.Get200());
        }
    };
}