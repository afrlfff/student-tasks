/* Задание #5. Лабораторная работа #3.
*  Автор: Фролов Александр Эдуардович
*  Группа: 2302
*  Версия: 1.2
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus"); // русский язык в консоли
	unsigned i;
	double x, a, eps, S;
	fstream f;
	cout << "Автор: Фролов Александр Эдуардович \n\n";

	cout << "Enter х: ";
	cin >> x;

	cout << "Enter eps: ";
	cin >> eps;
	i = 1;
	while (((eps > (1e-10)) || (eps <= 0)) && (i < 3))
	{
		cout << "Incorrect eps. Enter again: ";
		cin >> eps;
		i++;
	}
	if (((eps > (1e-10)) || (eps <= 0))){
		cout << "Too many attempts.\n";
	}
	else { // Решение задачи
		f.open("result.txt", ios::out);
		i = 0; a = 1; S = a;
		cout << "\n При x = " << x << " и eps = " << eps << " таблица выглядит следующим образом: " << endl;
		cout << "|" << "________" << "i" << "_______" << "|" << "________" << "a"
			<< "_______" << "|" << "________" << "S" << "_______" << "|" << endl;
		f << "\n При x = " << x << " и eps = " << eps << " таблица выглядит следующим образом: " << endl;
		f << "|" << "________" << "i" << "_______" << "|" << "________" << "a"
			<< "_______" << "|" << "________" << "S" << "_______" << "|" << endl;

		cout << "|" << setw(9) << i << setw(8) << "|" << setw(13) << setprecision(5) << a
			<< setw(4) << "|" << setw(13) << setprecision(5) << S << setw(4) << "|" << endl;
		f << "|" << setw(9) << i << setw(8) << "|" << setw(13) << setprecision(5) << a
			<< setw(4) << "|" << setw(13) << setprecision(5) << S << setw(4) << "|" << endl;

		while (((abs(a)) >= eps) && (i < 1000)) // while a не пренадлежит [-eps; eps] AND i < 1000
		{
			a *= (x * (i + 2.0)) / (i + 1.0) / (i + 1.0); // a *= x(i+2) / (i+1)^2
			S += a;
			cout << "|" << setw(9) << (i+1) << setw(8) << "|" << setw(13) << setprecision(5) << a
				<< setw(4) << "|" << setw(13) << setprecision(5) << S << setw(4) << "|" << endl;
			f << "|" << setw(9) << (i+1) << setw(8) << "|" << setw(13) << setprecision(5) << a
				<< setw(4) << "|" << setw(13) << setprecision(5) << S << setw(4) << "|" << endl;
			i++;
		}
		cout << "\n Итогое количество шагов = " << i << '\n';
		f << "\n Итогое количество шагов = " << i << '\n';
		f.close();
	}

    return 0;
}