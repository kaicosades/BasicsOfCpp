#include<iostream>
#include<conio.h>
using namespace  std;

const int ROWS = 3;
const int COLS = 4;

void Fillrand(int arr[], const int n);
void FillrandTwo(int arr[ROWS][COLS], const int ROWS, const int COLS);

void UniqueRand(int arr[], int n);

void Print(const int arr[], const int n);
void PrintTwo(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Search(int arr[], int n);
int Sum(const int arr[], const int n);
double Avg(const int arr[], const int n);
int minValueIn(const int arr[], const int n);
int maxValueIn(const int arr[], const int n);



//int Print_a(const int arr[], const int ROWC, const int  COLS);

//#define ONE_MACC
#define TWO_MACC




//void shiftRight(int arr[], const int n);
//void shiftLeft(int arr[], const int n);


void main()
{
#ifdef ONE_MACC
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
#endif

#ifdef TWO_MACC
	{
		
		int arr[ROWS][COLS];
		FillrandTwo(arr, ROWS, COLS);
		PrintTwo(arr, ROWS, COLS);

	}
#endif
}


int Sum(const int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Avg(const int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}

int minValueIn(const int arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}

int maxValueIn(const int arr[], const int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}

void Search(int arr[], int n)
{
	int replay = 0;
	int not_replay = 0;
	for (int i = 0; i != n; i++)
	{
		replay = 0;
		for (int j = i + 1; j != n; j++)
		{
			if (arr[i] == arr[j])
				replay++;
		}
		for (int l = i - 1; l >= 0; l--)
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

void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void PrintTwo(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j <COLS; j++)
		cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void Fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillrandTwo(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		arr[i][j] = rand() % 100;
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

