#include<iostream>
#include<windows.h>
using std::cin;
using std::cout;
using std::endl;
//#define TASK_0
//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define TASK_5
//#define TASK_6
//#define TASK_7 // ƒл€ запуска кода закомментировать 17 строчку тк €зык не переключаетс€ обратно.
//#define TASK_8
#define tablica_pifagora

void main()
{
	setlocale(LC_ALL, "");
	//int n;
	//cout << "¬ведите размер фигуры:"; cin >> n;
#ifdef TASK_0
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
#endif

#ifdef TASK_1
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j != i; j++)
		{
			cout << "*";
		}
		cout << endl;

	}
#endif

#ifdef TASK_2
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j != n - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
#endif

#ifdef TASK_3
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 0; i <= n - 1; i++)
	{
		int y = 0;
		while (y != i)
		{
			cout << " ";
			y++;
		}
		for (int j = 0; j != n - i; j++)
		{

			cout << "*";
		}
		cout << endl;
	}
#endif

#ifdef TASK_4
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int y = 0;
		while (y != n - i)
		{
			cout << " ";
			y++;
		}
		for (int j = 0; j != i; j++)
		{
			cout << "*";
		}
		cout << endl;

	}
#endif

#ifdef TASK_5
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y = 0;
		while (y != n - i)
		{
			cout << " ";
			y++;
		}
		cout << "/";
		for (int j = 0; j != i; j++)
		{
			cout << "  ";
		}
		cout << "\\";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		int y = 0;
		while (y != i + 1)
		{
			cout << " ";
			y++;
		}
		cout << "\\";
		for (int j = 0; j != n - i - 1; j++)
		{
			cout << "  ";
		}
		cout << "/";
		cout << endl;
	}
#endif

#ifdef TASK_6
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j) % 2 == 0)
				cout << "+";
			else
				cout << "-";
		}
		cout << endl;
	}
#endif

#ifdef TASK_7
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	setlocale(LC_ALL, ".866");

	char ugol_left_up = 218;
	char ugol_left_down = 192;
	char white = 219;
	char gorizont = 196;
	char ugol_right_up = 191;
	char ugol_right_down = 217;
	char vertical = 179;
	cout << "\n" << "\t" << ugol_left_up;
	for (int i = 0; i < n * 2; i++)
	{
		cout << gorizont;
	}
	cout << ugol_right_up;
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		int y = 0;
		y++;
		cout << "\t" << vertical;
		for (int j = 0; j < n * 3; j = j + 3)
		{
			if ((i + j) % 2 == 0)
			{
				cout << white << white;
			}
			else
			{
				cout << "  ";
			}
		}
		cout << vertical;
		cout << endl;
	}
	cout << "\t" << ugol_left_down;
	for (int i = 0; i < n * 2; i++)
	{
		cout << gorizont;
	}
	cout << ugol_right_down;

#endif

#ifdef TASK_8
	int n;
	cout << "¬ведите размер фигуры:"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y = 0;
		while (y != 5)
		{
			y++;
			for (int j = 0; j < n * 3; j = j + 3)
			{
				if ((i + j) % 2 == 0)
				{
					cout << "* * * * *";
				}
				else
				{
					cout << "         ";
				}
			}
			cout << endl;
		}
		//cout << endl;
	}

#endif

#ifdef tablica_pifagora
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
	int h;
	cout << "¬ведите высоту треугольника: "; cin >> h;
	long long int nf = 1;
	for (int i = 0; i <= h; i++)
	{
		cout.width(4);
		cout << "";
	}
	cout.width(7);
	cout << "" << 1 << endl;
	for (int n = 1; n <= h; n++)
	{
		for (int i = n % 2 ? 1 : 0; i <= h - n; i++)cout << "    ";
		if (n % 2) cout << "    ";
		cout.width(8);
		cout << 1;// << " ";
		nf *= n;
		long long int kf = 1;


		for (int k = 1; k <= n; k++)
		{
			kf *= k;
			long long int nkf = 1;
			for (int i = 1; i <= n - k; i++)nkf *= i;
			cout.width(8);
			cout << nf / kf / nkf;// << " ";
		}
		cout << endl;
	}
	//n % 2 ? 1 : 0
#endif
}