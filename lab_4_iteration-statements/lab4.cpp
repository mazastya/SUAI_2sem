﻿//Циклические вычисления с заданной точностью. Пример.
//Вычислить предел последовательности {y[n]}.
//Значения y[0], y[1], y[2] и точность eps вводятся с клавиатуры.
//Вычисления закончить при |y[n]-y[n-1]| <= eps.
//Вывести результат и число итераций.
# include <iostream>
# include <cmath>
# include <climits>

using namespace std;
double predel_1(double, double, double, double, int& n);
double predel_2(double, double, double, double, int& n);
double predel_3(double, double, double, double, int& n);

//main_begin
int main()
{
    setlocale(LC_ALL, "Russian");
    int var,
        n1, n2, n3;		//число итераций для разных циклов
    double re1, re2, re3,	//результаты расчетов
        y,			//значение предела
        y0, y1, y2;	//текущие значения элементов последовательности
    double eps;		//точность вычисления предела
    for (;;)
    {//Ввод исходных данных
        cout << " Вид действия:" << endl;
        cout << " 1 - вычисление предела последовательности" << endl;
        cout << " 2 - завершение задачи" << endl;
        cout << " Введите вид действия -> ";
        cin >> var;
        switch (var)
        {
        case 1:
            //Ввод исходных данных
            cout << " Введите значения y0, y1, y2 -> ";
            cin >> y0 >> y1 >> y2;
            cout << " Введите точность вычисления -> ";
            cin >> eps;
            if (eps <= 0 || eps > .1)
            {
                cout << "Ошибка ввода. Значение eps д.б. >0 и  <=0.1" << endl;
                continue;
            }
            //Решение циклом while
            re1 = predel_1(y0, y1, y2, eps, n1 = 3);
            if (n1 != INT_MAX)
            {
                cout.precision(4); 	//число знаков после десятичной точки
                cout << "Для цикла WHILE результат     = " << re1 << " n = " << n1 << endl;
            }
            else cout << "Для цикла WHILE точность не достигнута" << endl;
            //Решение циклом do..while
            re2 = predel_2(y0, y1, y2, eps, n2 = 2);
            if (n2 != INT_MAX)
            {
                cout.precision(4); 	//число знаков после десятичной точки
                cout << "Для цикла DO..WHILE результат = " << re2 << " n = " << n2 << endl;
            }
            else cout << "Для цикла DO..WHILE точность не достигнута" << endl;
            //Решение циклом for
            re3 = predel_3(y0, y1, y2, eps, n3 = 3);
            if (n3 != INT_MAX)
            {
                cout.precision(4); 	//число знаков после десятичной точки
                cout << "Для цикла FOR результат       = " << re3 << " n = " << n3 << endl;
            }
            else cout << "Для цикла FOR точность не достигнута" << endl;
            break;
        default: return 0;
        }//switch
    }//for
}
//main_end

//predel_1_beg
//вычисление предела последовательности циклом while
double predel_1(double y0, double y1, double y2, double eps, int& n)
{
    double y = (1.5 * y2 + 2.5 * y1 - 4) / (n * n * (sin(n) + 1.1 * y0));
    while (fabs(y - y2) > eps && n < INT_MAX)
    {
        y0 = y1;
        y1 = y2;
        y2 = y;
        n++;
        y = (1.5 * y2 + 2.5 * y1 - 4) / (n * n * (sin(n) + 1.1 * y0));
    }
    return y;
}
//predel_1_end

//predel_2_beg
//вычисление предела последовательности циклом do..while
double predel_2(double y1, double y2, double y, double eps, int& n)
{
    double y0;
    do {
        y0 = y1;
        y1 = y2;
        y2 = y;
        n++;
        y = (1.5 * y2 + 2.5 * y1 - 4) / (n * n * (sin(n) + 1.1 * y0));
    } while (fabs(y - y2) > eps && n < INT_MAX);
    return y;
}
//predel_2_end

//predel_3_beg
//вычисление предела последовательности циклом for
double predel_3(double y0, double y1, double y2, double eps, int& n)
{
    double y = (1.5 * y2 + 2.5 * y1 - 4) / (n * n * (sin(n) + 1.1 * y0));
    for (; fabs(y - y2) > eps && n < INT_MAX; )
    {
        y0 = y1;
        y1 = y2;
        y2 = y;
        n++;
        y = (1.5 * y2 + 2.5 * y1 - 4) / (n * n * (sin(n) + 1.1 * y0));
    }
    return y;
}
//predel_3_end
