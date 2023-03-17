#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	
	int h;
	cin >> h;
	int nf = 1;
	for (int n = 0; n < h; n++)
	{
		nf *= n;
		int kf = 1;
		for (int k = 1; k <= n; k++)
		{
			kf *= k;
			int nkf = 1;
			for (int i = 1; i <= n - k; i++)nkf *= i;
		}
	}
}