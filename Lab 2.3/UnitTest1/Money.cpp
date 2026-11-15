#include "Money.h"
#include <sstream>
#include <cmath>
#include <iomanip>

// Переведення всього в копійки
long long Money::toTotalKopecks() const
{
    long long total = 0;
    total += (long long)nominal500 * 50000;
    total += (long long)nominal200 * 20000;
    total += (long long)nominal100 * 10000;
    total += (long long)nominal50 * 5000;
    total += (long long)nominal20 * 2000;
    total += (long long)nominal10 * 1000;
    total += (long long)nominal5 * 500;
    total += (long long)nominal2 * 200;
    total += (long long)nominal1 * 100;
    total += (long long)coin50 * 50;
    total += (long long)coin25 * 25;
    total += (long long)coin10 * 10;
    total += (long long)coin5 * 5;
    total += (long long)coin2 * 2;
    total += (long long)coin1 * 1;
    return total;
}

// Заповнення купюр і монет із загальної кількості копійок оптимальним способом
void Money::fromTotalKopecks(long long kopecks)
{
    if (kopecks < 0) kopecks = 0;

    nominal500 = kopecks / 50000; kopecks %= 50000;
    nominal200 = kopecks / 20000; kopecks %= 20000;
    nominal100 = kopecks / 10000; kopecks %= 10000;
    nominal50 = kopecks / 5000;  kopecks %= 5000;
    nominal20 = kopecks / 2000;  kopecks %= 2000;
    nominal10 = kopecks / 1000;  kopecks %= 1000;
    nominal5 = kopecks / 500;   kopecks %= 500;
    nominal2 = kopecks / 200;   kopecks %= 200;
    nominal1 = kopecks / 100;   kopecks %= 100;
    coin50 = kopecks / 50;    kopecks %= 50;
    coin25 = kopecks / 25;    kopecks %= 25;
    coin10 = kopecks / 10;    kopecks %= 10;
    coin5 = kopecks / 5;     kopecks %= 5;
    coin2 = kopecks / 2;     kopecks %= 2;
    coin1 = kopecks;
}

// Конструктори
Money::Money()
{
    nominal500 = nominal200 = nominal100 = nominal50 = nominal20 = nominal10 =
        nominal5 = nominal2 = nominal1 = coin50 = coin25 = coin10 = coin5 = coin2 = coin1 = 0;
}

Money::Money(long n500, long n200, long n100, long n50, long n20, long n10,
    long n5, long n2, long n1, long c50, long c25, long c10, long c5, long c2, long c1)
{
    Set500(n500); Set200(n200); Set100(n100); Set50(n50); Set20(n20); Set10(n10);
    Set5(n5); Set2(n2); Set1(n1); SetC50(c50); SetC25(c25); SetC10(c10); SetC5(c5); SetC2(c2); SetC1(c1);
}

Money::Money(const Money& m)
{
    nominal500 = m.nominal500;
    nominal200 = m.nominal200;
    nominal100 = m.nominal100;
    nominal50 = m.nominal50;
    nominal20 = m.nominal20;
    nominal10 = m.nominal10;
    nominal5 = m.nominal5;
    nominal2 = m.nominal2;
    nominal1 = m.nominal1;
    coin50 = m.coin50;
    coin25 = m.coin25;
    coin10 = m.coin10;
    coin5 = m.coin5;
    coin2 = m.coin2;
    coin1 = m.coin1;
}

Money::~Money() {}

// Методи запису з перевіркою на невід'ємність
void Money::Set500(long val) { nominal500 = (val >= 0) ? val : 0; }
void Money::Set200(long val) { nominal200 = (val >= 0) ? val : 0; }
void Money::Set100(long val) { nominal100 = (val >= 0) ? val : 0; }
void Money::Set50(long val) { nominal50 = (val >= 0) ? val : 0; }
void Money::Set20(long val) { nominal20 = (val >= 0) ? val : 0; }
void Money::Set10(long val) { nominal10 = (val >= 0) ? val : 0; }
void Money::Set5(long val) { nominal5 = (val >= 0) ? val : 0; }
void Money::Set2(long val) { nominal2 = (val >= 0) ? val : 0; }
void Money::Set1(long val) { nominal1 = (val >= 0) ? val : 0; }
void Money::SetC50(long val) { coin50 = (val >= 0) ? val : 0; }
void Money::SetC25(long val) { coin25 = (val >= 0) ? val : 0; }
void Money::SetC10(long val) { coin10 = (val >= 0) ? val : 0; }
void Money::SetC5(long val) { coin5 = (val >= 0) ? val : 0; }
void Money::SetC2(long val) { coin2 = (val >= 0) ? val : 0; }
void Money::SetC1(long val) { coin1 = (val >= 0) ? val : 0; }

// Операція присвоєння
Money& Money::operator = (const Money& m)
{
    if (this != &m)
    {
        nominal500 = m.nominal500;
        nominal200 = m.nominal200;
        nominal100 = m.nominal100;
        nominal50 = m.nominal50;
        nominal20 = m.nominal20;
        nominal10 = m.nominal10;
        nominal5 = m.nominal5;
        nominal2 = m.nominal2;
        nominal1 = m.nominal1;
        coin50 = m.coin50;
        coin25 = m.coin25;
        coin10 = m.coin10;
        coin5 = m.coin5;
        coin2 = m.coin2;
        coin1 = m.coin1;
    }
    return *this;
}

// Перетворення у рядок (дробова частина відокремлена комою)
Money::operator string () const
{
    long long total = toTotalKopecks();
    long long hryvnias = total / 100;
    long long kopecks = total % 100;

    stringstream ss;
    ss << hryvnias << "," << setfill('0') << setw(2) << kopecks << " UAH";
    return ss.str();
}

// Префіксний інкремент (збільшує суму на 1 грн = 100 коп.)
Money& Money::operator ++()
{
    long long total = toTotalKopecks() + 100;
    fromTotalKopecks(total);
    return *this;
}

// Префіксний декремент (зменшує суму на 1 грн = 100 коп.)
Money& Money::operator --()
{
    long long total = toTotalKopecks() - 100;
    if (total < 0) total = 0;
    fromTotalKopecks(total);
    return *this;
}

// Постфіксний інкремент (збільшує суму на 1 копійку)
Money Money::operator ++(int)
{
    Money tmp(*this);
    long long total = toTotalKopecks() + 1;
    fromTotalKopecks(total);
    return tmp;
}

// Постфіксний декремент (зменшує суму на 1 копійку)
Money Money::operator --(int)
{
    Money tmp(*this);
    long long total = toTotalKopecks() - 1;
    if (total < 0) total = 0;
    fromTotalKopecks(total);
    return tmp;
}

// Додавання сум
Money operator + (const Money& a, const Money& b)
{
    Money res;
    long long total = a.toTotalKopecks() + b.toTotalKopecks();
    res.fromTotalKopecks(total);
    return res;
}

// Віднімання сум
Money operator - (const Money& a, const Money& b)
{
    Money res;
    long long total = a.toTotalKopecks() - b.toTotalKopecks();
    if (total < 0) total = 0;
    res.fromTotalKopecks(total);
    return res;
}

// Множення суми на дробове число
Money operator * (const Money& m, double val)
{
    Money res;
    long long total = (long long)round(m.toTotalKopecks() * val);
    if (total < 0) total = 0;
    res.fromTotalKopecks(total);
    return res;
}

Money operator * (double val, const Money& m)
{
    return m * val;
}

// Порівняння
bool operator == (const Money& a, const Money& b)
{
    return a.toTotalKopecks() == b.toTotalKopecks();
}

bool operator != (const Money& a, const Money& b)
{
    return !(a == b);
}

bool operator > (const Money& a, const Money& b)
{
    return a.toTotalKopecks() > b.toTotalKopecks();
}

bool operator < (const Money& a, const Money& b)
{
    return a.toTotalKopecks() < b.toTotalKopecks();
}

// Потокове виведення
ostream& operator << (ostream& out, const Money& m)
{
    out << string(m);
    return out;
}

// Потокове введення
istream& operator >> (istream& in, Money& m)
{
    long n500, n200, n100, n50, n20, n10, n5, n2, n1, c50, c25, c10, c5, c2, c1;
    cout << "Enter quantity of banknotes (500, 200, 100, 50, 20, 10, 5, 2, 1 UAH):\n";
    in >> n500 >> n200 >> n100 >> n50 >> n20 >> n10 >> n5 >> n2 >> n1;
    cout << "Enter quantity of coins (50, 25, 10, 5, 2, 1 kop.):\n";
    in >> c50 >> c25 >> c10 >> c5 >> c2 >> c1;

    m.Set500(n500); m.Set200(n200); m.Set100(n100); m.Set50(n50); m.Set20(n20); m.Set10(n10);
    m.Set5(n5); m.Set2(n2); m.Set1(n1); m.SetC50(c50); m.SetC25(c25); m.SetC10(c10); m.SetC5(c5); m.SetC2(c2); m.SetC1(c1);

    return in;
}

// Фабрична функція
Money makeMoney(long n500, long n200, long n100, long n50, long n20, long n10,
    long n5, long n2, long n1, long c50, long c25, long c10, long c5, long c2, long c1)
{
    return Money(n500, n200, n100, n50, n20, n10, n5, n2, n1, c50, c25, c10, c5, c2, c1);
}