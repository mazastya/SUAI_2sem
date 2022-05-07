#include<iostream>
#include<math.h>
#include<limits.h>
#include<locale.h>
using namespace std;
double riad(double, double, int& n);
//main_beg
int main()
{
    int vid,
        n;			//число слагаемых, попавших в сумму
    double x, xn, xk, 	//текущее, начальное и конечное значения аргумента
        h;			//шаг изменения значения аргумента
    double eps,		//точность вычисления суммы
        rez;			//результат вычисления суммы ряда
    setlocale(LC_ALL, "Russian");
    for (;;)
    {//Ввод исходных данных
        cout << "\n                      Вид действия:" << endl;
        cout << "                  1 - получение таблицы значений" << endl;
        cout << "                  2 - завершение работы программы" << endl;
        cout << "                  Выберите вид действия -> ";
        cin >> vid;
        if (vid == 1)
        {
            cout << " Введите начальное значение аргумента ";
            cin >> xn;
            if (fabs(xn) >= 1)
            {
                cout << " Ошибка! Значение д.б. 0<xn<1";
                continue;
            }
            cout << " Введите конечное значение аргумента ";
            cin >> xk;
            if ((fabs(xk) >= 1) || (xk < xn))
            {
                cout << " Ошибка! Значение д.б. 0<xk<1 и xk>=xn";
                continue;
            }
            cout << " Введите шаг изменения аргумента h ";
            cin >> h;
            if (h <= 0)
            {
                cout << " Ошибка! Значение h д.б. >0";
                continue;
            }
            cout << " Введите точность вычисления eps ";
            cin >> eps;
            if ((eps <= 0) || (eps > 0.1))
            {
                cout << " Ошибка! Значение eps д.б. >0 и <=0.1";
                continue;
            }
            //Вывод заголовка
            cout << "\n Аргумент|  Сумма |Кол.слаг.|Контрольное значение" << endl;
            x = xn;
            do {
                n = 1;
                rez = riad(x, eps, n);
                cout.width(7); cout.precision(2); cout << x;
                if (n < INT_MAX)
                {
                    cout.width(11); cout.precision(4); cout << rez;
                    cout.width(6); 			   cout << n;
                    cout.width(15); cout.precision(4); cout << asin(x) << endl;
                }
                else cout << " Точность не достигнута" << endl;
                x += h;
            } while (x <= xk + eps);
        }
        else break;
    }
    return 1;
}
//main_end

//riad_beg
//Вычисление суммы
double riad(double x, double eps, int& n)
{
    double rez = x;	//результат вычисления
    double pr = ((x * x * x) / 6);		//величина текущего слагаемого
    n = 1;			//номер текущего слагаемого
    while (fabs(pr) > eps && n < INT_MAX)
    {
        rez += pr;
        n++;
        pr *= ((2 * n - 1) * (2 * n - 1) * x * x) / ((2 * n + 1) * (2 * n)); //надо домножить на x*x?? ПЕРЕСЧЕТ
    }
    pr += x; // тут прибаляем?? ДУМАЙ
    return rez;
}
//riad_end
