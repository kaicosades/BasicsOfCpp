#include<iostream>
using namespace std;

void main()
{
	//Fillrand(arr, n)

	const int n = 5;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}

	int a; cout << "Введите размер сдвига: "; cin >> a;
		a %= n;
		if (a == 0)
			a = -1;
		int f = arr[0];
		for (int i = 0; i < n; i++)
		{
			if (i + 5 - a == 5)
				a = 6;
			arr[i] = arr[i + 5 - a];
			cout << arr[i] << "\t";
		}
		//Прога правильно работает!!! просто 1 элемент сразу меняется поэтому они дублируются

	
}