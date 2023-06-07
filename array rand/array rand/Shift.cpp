#include"Shift.h"

template<typename T>void Shift(T arr[], int n)
{
	cout << "Выберете смещение: <-     ->" << endl;

	int code = _getch();
	//cout << code << endl;
	if (code == 0 || code == 224)
		code = _getch();
	//cout << code;
	switch (code)
	{
	case 75: ShiftLeft(arr, n);
		break;
	case 77: ShiftRight(arr, n);
		break;
	}
}
template<typename T>T ShiftLeft(T arr[], const int n)
{
	int m;
	cout << "Введите смещение: "; cin >> m;
	m = m % n;
	for (m; m != 0; m--)
	{
		int a = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = a;


	}
	return arr[n];
}
template<typename T>T ShiftRight(T arr[], const int n)
{
	int m;
	cout << "Введите смещение: "; cin >> m;
	m = m % n;
	for (m; m != 0; m--)
	{
		int a = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = a;

	}
	return arr[n];
}

template<typename T>void Shift(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	cout << "Выберете смещение: <-     ->" << endl;

	int code = _getch();
	//cout << code << endl;
	//if (code != 0 || code != 224)
	//{
	//	cout << "Выберите клавишу стрелок: " << endl; //Как заного запустить функцию для выбора направления?
	//	//Shift(arr, n);
	//}
	if (code == 0 || code == 224)
		code = _getch();
	//cout << code;
	switch (code)
	{
	case 75: ShiftLeft(arr, ROWS, COLS);
		break;
	case 77: ShiftRight(arr, ROWS, COLS);
		break;
	}
}
template<typename T>T ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int m;
	cout << "Введите смещение: "; cin >> m;
	m = m % (ROWS * COLS);
	for (m; m > 0; m--)
	{
		int i = 0;
		int j = 0;
		int a = arr[0][0];
		for (i = 0; i < ROWS; i++)
		{
			for (j = 0; j < COLS - 1; j++)
			{
				arr[i][j] = arr[i][j + 1];
			}
			if (i < ROWS - 1)
				arr[i][j] = arr[i + 1][0];
			else
				arr[i][COLS - 1] = a;
		}
	}
	return arr[ROWS][COLS];
}
template<typename T>T ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int m;
	cout << "Введите смещение: "; cin >> m;
	m = m % (ROWS * COLS);
	m = ROWS * COLS - m;
	for (m; m > 0; m--)
	{
		int i = 0;
		int j = 0;
		int a = arr[0][0];
		for (i = 0; i < ROWS; i++)
		{
			for (j = 0; j < COLS - 1; j++)
			{
				arr[i][j] = arr[i][j + 1];
			}
			if (i < ROWS - 1)
				arr[i][j] = arr[i + 1][0];
			else
				arr[i][COLS - 1] = a;
		}
	}
	return arr[ROWS][COLS];
}