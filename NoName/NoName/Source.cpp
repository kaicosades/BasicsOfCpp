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
		/*for (int i = 0; i < n; i++)
		{
			if (i + 5 - a == 5)
				a = 6;
			arr[i] = arr[i + 5 - a];
			cout << arr[i] << "\t";
		}*/
		for (int i = 0; i < number_of_shifts; i++)
		{
			int buffer = arr[n - 1];
			for (int i = n - 1; i > 0: i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[0] = buffer;
		}


		//Прога правильно работает!!! просто 1 элемент сразу меняется поэтому они дублируются

	
}

const int SIZE = 8;
double d_arr[SIZE];
FillRand(d_arr, SIZE);
Print(d_arr, SIZE);


Sort(arr, n);
Print(arr, n);
void Sort(int att[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}