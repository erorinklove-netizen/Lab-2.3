#pragma once
#include <iostream>
#include <string>

using namespace std;

class Money
{
private:
    long nominal500;
    long nominal200;
    long nominal100;
    long nominal50;
    long nominal20;
    long nominal10;
    long nominal5;
    long nominal2;
    long nominal1;
    long coin50;
    long coin25;
    long coin10;
    long coin5;
    long coin2;
    long coin1;

    // Допоміжний метод для переведення всього в копійки для зручності розрахунків
    long long toTotalKopecks() const;
    // Оновлення полів з загальної кількості копійок
    void fromTotalKopecks(long long kopecks);

public:
    // Конструктори
    Money();
    Money(long n500, long n200, long n100, long n50, long n20, long n10, 
          long n5, long n2, long n1, long c50, long c25, long c10, long c5, long c2, long c1);
    Money(const Money& m);
    ~Money();

    // Методи доступу (з контролем невід'ємних значень)
    long Get500() const { return nominal500; }
    long Get200() const { return nominal200; }
    long Get100() const { return nominal100; }
    long Get50() const { return nominal50; }
    long Get20() const { return nominal20; }
    long Get10() const { return nominal10; }
    long Get5() const { return nominal5; }
    long Get2() const { return nominal2; }
    long Get1() const { return nominal1; }
    long GetC50() const { return coin50; }
    long GetC25() const { return coin25; }
    long GetC10() const { return coin10; }
    long GetC5() const { return coin5; }
    long GetC2() const { return coin2; }
    long GetC1() const { return coin1; }

    void Set500(long val);
    void Set200(long val);
    void Set100(long val);
    void Set50(long val);
    void Set20(long val);
    void Set10(long val);
    void Set5(long val);
    void Set2(long val);
    void Set1(long val);
    void SetC50(long val);
    void SetC25(long val);
    void SetC10(long val);
    void SetC5(long val);
    void SetC2(long val);
    void SetC1(long val);

    // Операція присвоєння
    Money& operator = (const Money& m);

    // Приведення типу до рядка (з комою між гривнями та копійками)
    operator string() const;

    // Інкремент та декремент (префіксні збільшують/зменшують загальну суму на 1 грн, постфіксні — на 1 коп.)
    Money& operator ++();       
    Money& operator --();       
    Money operator ++(int);     
    Money operator --(int);     

    // Дружні бінарні операції (згідно з таблицею варіанта, решта бінарних — зовнішні дружні функції)
    friend Money operator + (const Money& a, const Money& b);
    friend Money operator - (const Money& a, const Money& b);
    friend Money operator * (const Money& m, double val); // Множення суми на дробове число
    friend Money operator * (double val, const Money& m);

    // Операції порівняння
    friend bool operator == (const Money& a, const Money& b);
    friend bool operator != (const Money& a, const Money& b);
    friend bool operator > (const Money& a, const Money& b);
    friend bool operator < (const Money& a, const Money& b);

    // Дружні функції вводу / виводу
    friend ostream& operator << (ostream& out, const Money& m);
    friend istream& operator >> (istream& in, Money& m);
};

// Зовнішня фабрична функція
Money makeMoney(long n500, long n200, long n100, long n50, long n20, long n10, 
                long n5, long n2, long n1, long c50, long c25, long c10, long c5, long c2, long c1);
