
#include"UniqueRand.h"
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