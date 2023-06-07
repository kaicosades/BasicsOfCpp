//#include"stdafx.h"
//#include"constants.h"
#include"FillRand.cpp"
#include"Print.cpp"
#include"Search.cpp"
#include"Shift.cpp"
#include"Sort.cpp"
#include"Statistics.cpp"
#include"UniqueRand.cpp"

//#define ONE_MACC
#define TWO_MACC

void main()
{
#ifdef ONE_MACC
	{
		setlocale(LC_ALL, "");
		const int n = 5;
		int arr[n];
		Fillrand(arr, n);
		Print(arr, n);
		cout << "Минимальное значение в массиве: " << MinValueIn(arr, n) << endl;
		cout << "Максимальное значение в массиве: " << MaxValueIn(arr, n) << endl;
		cout << "Сумма всех элементов в массиве: " << Sum(arr, n) << endl;
		cout << "Среднее арифметическое элементов в массиве: " << Avg(arr, n) << endl;
		Search(arr, n);
		cout << "Массив с уникальными элементами: " << endl;
		UniqueRand(arr, n);
		Print(arr, n);
		Shift(arr, n);
		Print(arr, n);
		cout << "Сортировка массива по возрастанию: " << endl;
		Sort(arr, n);
		Print(arr, n);

	}
#endif

#ifdef TWO_MACC
	{
		setlocale(LC_ALL, "");
		int arr[ROWS][COLS];
		Fillrand(arr, ROWS, COLS);
		Print(arr, ROWS, COLS);
		Search(arr, ROWS, COLS);
		cout << "Сумма всех элементов в массиве: " << Sum(arr, ROWS, COLS) << endl;
		cout << "Среднее арифметическое элементов в массиве: " << Avg(arr, ROWS, COLS) << endl;
		cout << "Минимальное значение в массиве: " << MinValueIn(arr, ROWS, COLS) << endl;
		cout << "Максимальное значение в массиве: " << MaxValueIn(arr, ROWS, COLS) << endl;
		Shift(arr, ROWS, COLS);
		Print(arr, ROWS, COLS);
		cout << "Массив с уникальными элементами: " << endl;
		UniqueRand(arr, ROWS, COLS);
		Print(arr, ROWS, COLS);
		cout << "Сортировка массива по возрастанию: " << endl;
		Sort(arr, ROWS, COLS);
		Print(arr, ROWS, COLS);

	}
#endif
}


