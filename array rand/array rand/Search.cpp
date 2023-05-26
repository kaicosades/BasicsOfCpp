#include"stdafx.h"
#include"constants.h"
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
			cout << "Ёлемент " << arr[i] << " повтор€етс€ " << replay << " раз(а). " << endl;
			not_replay++;
		}
	}
	if (replay == 0 && not_replay == 0) cout << "ѕовтор€ющихс€ элементов нет." << endl;
}