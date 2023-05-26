#include"stdafx.h"
#include"constants.h"
#include"FillRand.h"
#include"Print.h"
#include"Statistics.h"
#include"Sort.h"
#include"Search.h"




//void shiftRight(int arr[], const int n);
//void shiftLeft(int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	Fillrand(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(arr, n) << endl;
	cout << "Сумма всех элементов в массиве: " << Sum(arr, n) << endl;
	cout << "Среднее арифметическое элементов в массиве: " << Avg(arr, n) << endl;
	Search(arr, n);
	UniqueRand(arr, n);
	cout << "Массив с уникальными элементами: ";
	Print(arr, n);
}





































//void shiftRight(int arr[], const int n)
	//{
	//	//Fillrand(arr, n)
	//	const int s = 5;
	//	int arr_2[s];
	//	int a; cout << "Введите размер сдвига: "; cin >> a;
	//	//a %= n;
	//	int f;
	//	for (int i = 0; i < n; i++)
	//	{
	//		arr_2[i] = arr[i];
	//		cout << arr_2[i] << "\t";
	//	}
	//	cout << endl;
	//
	//	for (int i = 0; i < n; i++)
	//	{
	//		if (0 - a + i >= 0)
	//			a = 0;
	//		arr[i] = arr_2[i+1-a];
	//		cout << arr[i] << "\t";
	//	}




//void shiftRight(int arr[], const int n)
//{
//	int a; cout << "Введите размер сдвига: "; cin >> a;
//	a %= n;
//	if (a == 0)
//		a = -1;
//	int f = arr[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (i + 5 - a == 5)
//			a = 6;
//		arr[i] = arr[i +5 - a];
//		cout << arr[i] << "\t";
//	}

		/*for (int i = n; i > 0; i--)
		{
			f = arr[i];
			arr[i] = arr[i - a];
			arr[a] = f;
		}*/

		/*for (int i=0; i < n; i++)
		{
			if (n - a + i>n)
			{
				a -= 4;
			}
			f = arr[i];
			arr[i] = arr[n-a+i];
			arr[a + i] = f;
		}*/
	//return (void)Print(arr, n);
//}
	//void shiftLeft(int arr[], const int n)

