#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;	// = 5; //������������ �������
						//cin >> n;
	int arr[n];
						//arr[2] = 123;
						//cout << arr[2] << endl;
	cout << "������� �������� �������: ";
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
	cout << "���������� ������� �������: " << max << endl;

	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "���������� ������� �������: " << min << endl;

	float sum= arr[0];
	for (int i = 1; i < n; i++)
	{
		sum += arr[i];
	}
	cout <<"������� �������������� �������: "<< sum / n << endl;
	cout <<"����� �������: "<< sum << endl;

	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}*/
	cout << endl;
}