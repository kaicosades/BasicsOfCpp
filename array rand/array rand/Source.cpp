#include<iostream>
#include<conio.h>
using namespace  std;

const int ROWS = 3;
const int COLS = 4;

template<typename T>void Fillrand(T arr[], const int n);
template<typename T>void Fillrand(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void UniqueRand(T arr[], int n);
template<typename T>void UniqueRand(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void Shift(T arr[], int n);
template<typename T>T ShiftLeft(T arr[], const int n);
template<typename T>T ShiftRight(T arr[], const int n);

template<typename T>void Shift(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>T ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>T ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void Search(T arr[], int n);
template<typename T>void Search(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T Sum(T arr[], const int n); //const t arr
template<typename T>T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T Avg(T arr[], const int n);
template<typename T>T Avg(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T MinValueIn(T arr[], const int n);
template<typename T>T MinValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T MaxValueIn(T arr[], const int n);
template<typename T>T MaxValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void Sort(T arr[], const int n);
template<typename T>void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS);

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

template<typename T> void Fillrand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
template<typename T>void Fillrand(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			arr[i][j] = rand() % 100;
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}


template<typename T>void UniqueRand(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		for (int j = 0; j < i; j++)
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
template<typename T>void UniqueRand(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
			for (int Unique_1 = 0; Unique_1 <= i; Unique_1++)
			{
				for (int Unique_2 = 0; (Unique_2 < COLS && Unique_1 < i) || (i == Unique_1 && Unique_2 < j); Unique_2++)
				{
					if (arr[i][j] == arr[Unique_1][Unique_2])
					{
						if (j == 0)
						{
							i--;
							j = COLS - 1;
						}
						else
							j--;
						break;
					}

				}

			}
		}
	}
	cout << endl;
}

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

template<typename T>void Search(T arr[], int n)
{
	int replay = 0;
	int not_replay = 0;
	for (int i = 0; i != n; i++)
	{
		replay = 0;
		for (int j = i + 1; j != n; j++)// сравнение всех элементов с текущим
		{
			if (arr[i] == arr[j])
				replay++;
		}
		for (int l = i - 1; l >= 0; l--)// не учитывать повторения эл, которые уже были
		{
			if (arr[i] == arr[l])
				replay = 0;
		}
		if (replay > 0)
		{
			cout << "Элемент " << arr[i] << " повторяется " << replay << " раз(а). " << endl;
			not_replay++;
		}
	}
	if (replay == 0 && not_replay == 0) cout << "Повторяющихся элементов нет." << endl;
}
template<typename T>void Search(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int replay;
	int not_replay = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			replay = 0;
			for (int ii = i; ii < ROWS; ii++)
			{
				int jj = 0;
				if (i == ii) jj = j + 1;
				if ((j == COLS - 1) && (i == ii))
				{
					jj = 0;
					ii++;
				}
				for (jj; jj < COLS; jj++)
				{
					if (arr[i][j] == arr[ii][jj])
						replay++;
				}
			}
			if (replay > 0)
			{
				for (int l = i; l >= 0; l--)
				{
					int m = j - 1;
					if ((j == 0) && (l == i))
					{
						l--;
						m = COLS - 1;
					}
					if (l < i) m = COLS - 1;
					for (m; m >= 0; m--)
						if (arr[l][m] == arr[i][j])
							replay = 0;
				}
			}
			if (replay > 0)
			{
				cout << "Элемент " << arr[i][j] << " повторяется " << replay << " раз(а). " << endl;
				not_replay++;
			}
		}

	}
	if (replay == 0 && not_replay == 0) cout << "Повторяющихся элементов нет." << endl;
}

template<typename T>T Sum(T arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template<typename T>T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			sum += arr[i][j];
	}
	return sum;
}

template<typename T>T Avg(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
template<typename T>T Avg(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

template<typename T>T MinValueIn(T arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
template<typename T>T MinValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			if (arr[i][j] < min)min = arr[i][j];
	}
	return min;
}

template<typename T>T MaxValueIn(T arr[], const int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
template<typename T>T MaxValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			if (arr[i][j] > max)max = arr[i][j];
	}
	return max;
}

template<typename T>void Sort(T arr[], const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				arr[i] = arr[i] + arr[j];
				arr[j] = arr[i] - arr[j];
				arr[i] = arr[i] - arr[j];
			}
		}
	}
}
template<typename T>void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					if (arr[i][j] > arr[k][l])
					{
						arr[i][j] = arr[k][l] + arr[i][j];
						arr[k][l] = arr[i][j] - arr[k][l];
						arr[i][j] = arr[i][j] - arr[k][l];
					}
				}
			}
		}
	}
}