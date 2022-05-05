//Для введенного с клавиатуры значения m вычислить
//значение суммы заданного вида, если значение x вычисляется
//по формуле x = - 0.4*i + ((3 * m) / 5).
#include <iostream>
#include <cmath>
using namespace std;

double recur1(int m);
double recur2(int m);
double recur3(int m);

int main()
{
    int m;  //конечное значение номера слагаемого
    int var;    //выбор действия
    double rec1, rec2, rec3;    // Результаты решения задачи
    setlocale(LC_ALL, "Russian");
    for (;;)
    {   //Выбор действия
        cout << "\n  Вид действия:" << endl;
        cout << " 1 - Вычисление суммы по рекуррентной формуле" << endl;
        cout << " 2 - Завершение программы" << endl;
        cout << " Введите вид действия -> ";
        cin >> var;
        switch (var)
        {
        case 1: //Ввод исходных данных
            cout << " Введите m  ->  ";
            cin >> m;
            rec1 = recur1(m);
            rec2 = recur2(m);
            rec3 = recur3(m);
            //Вывод результата
            cout.precision(5);  //число знаков после запятой при выводе
            cout << " Для цикла WHILE результат     = " << rec1 << endl;
            cout << " Для цикла DO..WHILE результат = " << rec2 << endl;
            cout << " Для цикла FOR результат       = " << rec3 << endl;
            break;
        default: return 1;
        }
    }
}

double recur1(int m) {
    int i = 2;  //начальное значение номера слагаемого
    double denom = 1,   //значение знаменателя аргумента тангенса
        sum = 0,  //исходное значение суммы
        x = (-0.4 * 1 + ((3. * m) / 5))*1.;
    double sl1 = tan((0.2 * x * x + (2. * 1) / 1) / denom); // отдело посчитанное 1 слагаемое
    while (i <= m) {
        denom *= (2. * i - 1) * (2 * i - 2);
        x = (-0.4 * i + ((3 * m) / 5));
        sum += tan((0.2 * x * x + (2. * i) / m) / denom);
        i++;
    }
    sum += sl1;
    return sum;
}

double recur2(int m) {
    int i = 2;  //начальное значение номера слагаемого
    double denom = 1,   //значение знаменателя аргумента тангенса
        sum = 0,  //исходное значение суммы
        x = (-0.4 * 1 + ((3. * m) / 5))*1.;
    double sl1 = tan((0.2 * x * x + (2. * 1) / 1) / denom)*1.; // отдельно посчитанное 1 слагаемое
    do {
        if (m == 1) {
            break;
        }
        denom *= (2. * i - 1) * (2 * i - 2);
        x = (-0.4 * i + ((3 * m) / 5));
        sum += tan((0.2 * x * x + (2. * i) / m) / denom);
        i++;
    } while (i <= m);
    sum += sl1;
    return sum;
}

double recur3(int m) {
    double denom = 1,   //значение знаменателя аргумента тангенса
        sum = 0,  //исходное значение суммы
        x = (-0.4 * 1 + ((3. * m) / 5));
    double sl1 = tan((0.2 * x * x + (2. * 1) / 1) / denom); // отдело посчитанное 1 слагаемое
    for (int i = 2; i <= m; i++) {
        denom *= (2. * i - 1) * (2 * i - 2);
        x = (-0.4 * i + ((3 * m) / 5));
        sum += tan((0.2 * x * x + (2. * i) / m) / denom);

    }
    sum += sl1;
    return sum;
}


