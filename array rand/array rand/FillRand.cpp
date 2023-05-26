#include "FillRand.h"

void Fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void UniqueRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		for (int j = i; i < j; j++)
		{
			if (arr[j] == arr[i])
			{
				i--;
				break;
			}
		}
	}
	cout << endl;
}