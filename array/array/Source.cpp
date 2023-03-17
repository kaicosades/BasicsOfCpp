#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;	// = 5; //обязательное условие
						//cin >> n;
	int arr[n];
						//arr[2] = 123;
						//cout << arr[2] << endl;
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "Наибольший элемент массива: " << max << endl;

	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "Наименьший элемент массива: " << min << endl;

	float sum= arr[0];
	for (int i = 1; i < n; i++)
	{
		sum += arr[i];
	}
	cout <<"Среднее арифмитеческое массива: "<< sum / n << endl;
	cout <<"Сумма массива: "<< sum << endl;

	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}*/
	cout << endl;
}