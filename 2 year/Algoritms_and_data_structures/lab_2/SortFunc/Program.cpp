#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "CallSort.h"
#include "Split.h"
#include "OutArray.h"


 // if this method not commented, so the Main() method
 // in file TimeMeasuring.cpp should be commmented
int main()
{
	setlocale(LC_ALL, "ru");

	std::string input;
	std::vector<std::string> inputs;
	std::vector<int> Array;
	short number;

	while (true)
	{
		std::cout << "Введите элементы массива через пробел: ";

		while (true)
		{
			getline(std::cin, input);
			inputs = Split(input, ' ');

			try
			{
				Array.clear();
				for (int i = 0; i < inputs.size(); i++)
					Array.push_back(stoi(inputs[i]));
				break;
			}
			catch (std::exception)
			{
				std::cout << "Не удалось считать элементы массива.\nПопробуйте еще раз: ";
			}
		}
		std::cout << "Введенный вами массив: ";
		OutArray(Array);

		std::cout << "Выберите тип сортировки:\n" <<
			"\t1) Сортировка выбором (SeletionSort);\n" <<
			"\t2) Сортировка вставками (InsertionSort);\n" <<
			"\t3) Сортировка пузырьком (BubbleSort);\n" <<
			"\t4) Сортировка слиянием (MergeSort);\n" <<
			"\t5) Быстрая сортировка (QuickSort);\n" <<
			"\t6) Сортировка Шелла 1 (ShellSort1);\n" <<
			"\t7) Сортировка Шелла 2 (ShellSort2);\n" <<
			"\t8) Сортировка Шелла 3 (ShellSort3);\n" <<
			"\t9) Пирамидальная сортировка (HeapSort);\n" <<
			"\t10) TimSort;\n" <<
			"\t11) IntroSort;\n";

		while (true)
		{
			try
			{
				getline(std::cin, input);
				number = stoi(input);
				if (number > 11 || number < 1)
					throw new std::exception();
				break;
			}
			catch (std::exception)
			{
				std::cout << "Введен некорректный номер.";
			}
		}

		CallSort(Array, number);
		OutArray(Array);
		std::cout << "Продолжить? (Yes/No)\nВаш ответ: ";
		while (true)
		{
			getline(std::cin, input);
			if (input != "Yes" && input != "yes" &&
				input != "No" && input != "no"
				)
			{
				std::cout << "Введен некорректный ответ. Попробуйте еще раз: ";
				continue;
			}
			else break;
		}
		if (input == "Yes" || input == "yes") continue;
		else break;
	}
}