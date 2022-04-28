#include<iostream>
#include<corecrt_math_defines.h>
#include<locale.h>
using namespace std;

int main() {
	int i = 0;					//номер области на рисунке
	float x, y,					//координаты точки
		s1, s2, s3, s4, s5;		//площади областей	
	setlocale(LC_ALL, "Russian");
	cout << "\nВведите координаты точки: x, y ";
	cin >> x >> y;

	if (x * x + (y - 1) * (y - 1) < 1 && (x - 1) * (x - 1) + (y - 1) * (y - 1) < 1 && x * x + y * y > 1 && (x - 1) * (x - 1) + y * y > 1)
	{
		cout << "Точка находится в области М1. "; i = 1;
	}
	else if ((x + 1) * (x + 1) + y * y < 1 && (x + 1) * (x + 1) + (y - 1) * (y - 1) < 1 && x * x + y * y > 1)
	{
		cout << "Точка находится в области М2. "; i = 2;

	}
	else if (x * x + y * y < 1 && (x + 1) * (x + 1) + y * y < 1 && (x + 1) * (x + 1) + (y + 1) * (y + 1) < 1 && (x * x + (y + 1) * (y + 1) < 1))
	{
		cout << "Точка находится в области М3. "; i = 3;
	}
	else if ((x - 1) * (x - 1) + (y + 1) * (y + 1) < 1 && x * x + y * y > 1 && x * x + (y + 1) * (y + 1) > 1)
	{
		cout << "Точка находится в области М4. "; i = 4;
	}
	else if ((x * x + (y + 1) * (y + 1) < 1 && (x < 0) && (y < -1) && (x + 1) * (x + 1) + (y + 1) * (y + 1) > 1))
	{
		cout << "Точка находится в области М5. "; i = 5;
	}
	else cout << "Точка вне выделенных областей";
	cout.precision(4);					//число знаков после десятичной точки
	switch (i) {
	case 1: cout << "S1 = " << (s1 = M_PI / 3 - (sqrt(3) / 4) + (1 - ((sqrt(3) / 4) + M_PI / 6)));
		break;
	case 2: cout << "S2 = " << (s2 = M_PI / 4);
		break;
	case 3: cout << "S3 = " << (s3 = 2 * (M_PI / 4 - 0.5) - 2 * ((1 - M_PI / 4) - 2 * (1 - (M_PI / 6 + (sqrt(3) / 4)))));
		break;
	case 4: cout << "S4 = " << (s4 = 2 * M_PI / 4 + (1 - ((sqrt(3) / 4) + M_PI / 6)) + (1 - M_PI / 4) - (1 - (M_PI / 6 + (sqrt(3) / 4))));
		break;
	case 5: cout << "S5 = " << (s5 = (1 - M_PI / 4) - (1 - (M_PI / 6 + (sqrt(3) / 4))));
		break;
	}
	cout << "\n Повторить - 1, Выход - 2: ";
	cin >> i;
	if (i == 1) main();

	return 0;

}