#include "Search.h"
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
		for (int l = i - 1; l >= 0; l--)// не учитывать повторени€ эл, которые уже были
		{
			if (arr[i] == arr[l])
				replay = 0;
		}
		if (replay > 0)
		{
			cout << "Ёлемент " << arr[i] << " повтор€етс€ " << replay << " раз(а). " << endl;
			not_replay++;
		}
	}
	if (replay == 0 && not_replay == 0) cout << "ѕовтор€ющихс€ элементов нет." << endl;
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
				cout << "Ёлемент " << arr[i][j] << " повтор€етс€ " << replay << " раз(а). " << endl;
				not_replay++;
			}
		}

	}
	if (replay == 0 && not_replay == 0) cout << "ѕовтор€ющихс€ элементов нет." << endl;
}
