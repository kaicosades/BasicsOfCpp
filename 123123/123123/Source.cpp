#include<iostream>
using namespace std;

void main()
{
	//Fillrand(arr, n)
	const int s = 5;
	const int n = 5;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	int arr_2[s];
	int a; cout << "¬ведите размер сдвига: "; cin >> a;
	a %= n;
	//int f;
	for (int i = 0; i < n; i++)
	{
		arr_2[i] = arr[i];
		cout << arr_2[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (i - a == 0)
			a = n+i;
		arr[i] = arr_2[i + n - a];
		cout << arr[i] << "\t";
	}
}