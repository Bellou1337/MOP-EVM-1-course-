/*
* ИКТИБ ЮФУ
* МОП ЭВМ
* СИАОД
* Тема 7 Вычислительная геометрия
* Задача B
* дата: 25.05.2024
* исполнитель: Иванов А.А, КТбо 1-7
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

using ll = long long;
using ull = unsigned long long;

/*
* Что принимает: ничего
* Что делает: решает задачу
* Что возвращает: ничего
*/
void solve()
{
	ll x1, y1, x2, y2, x3, y3,l;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> l;
	// вычисление длин векторов
	// (x1,y1) = A,(x2,y2) = B,(x3,y3) = C
	double lenAB = sqrt((double)pow((x2 - x1), 2) + (double)pow((y2 - y1), 2));
	double lenAC = sqrt((double)pow((x3 - x1), 2) + (double)pow((y3 - y1), 2));
	double lenCB = sqrt((double)pow((x3-x2),2)+(double)pow((y3-y2),2));
	//вычисление высоты прямоугольника
	//найдём площадь по теореме Герона
	// полупериметр
	double semiPerimeter = (lenAB + lenAC + lenCB) / 2;
	// находим площадь
	double square = sqrt(semiPerimeter*(semiPerimeter-lenAB)*(semiPerimeter - lenAC)*(semiPerimeter - lenCB));
	//находим высоту(по сути она и есть кратчайшее расстояние)
	double h = (square*2.0)/ lenAB;
	// теперь проверяем особые случаи
	// 1) что если перед нами прямоугольный треугольник
	if (max(lenAC,lenCB)*max(lenAC,lenCB)>min(lenAC,lenCB)*min(lenAC,lenCB)+ (double)pow(lenAB,2))
	{
		//переопределяем кратчайшее растояние
		//оно теперь минимум из длин AC и CB
		h = min(lenAC,lenCB);
	}
	// 2) если отрезок слился в одну точку
	// тогда lenAB == 0
	if (lenAB == 0.0)
	{
		// тут ответ только длина между AC или BC, расстояние будет одинаково
		h = lenAC;
	}
	// выводим ответ
	double firstAnswer = max(0.0,h-l);
	double secondAnswer = max(0.0,max(lenAC,lenCB)-l);
	cout << fixed << setprecision(2) << firstAnswer << endl;
	cout << fixed << setprecision(2) << secondAnswer << endl;
}

signed main()
{
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}