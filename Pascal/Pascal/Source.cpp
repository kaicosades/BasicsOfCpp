#include <iostream>

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите высоту таблицы Паскаля : "; std::cin >> n;
	for(int i=1; i<=n; i++)
	{
		std::cout << "1 ";
		if (i - 1 != 0)
		std::cout << i - 1 << " ";
		
		if (i > 4) // для вывода третьего столбца
		{
			int p = 2 * (i - (i - 3));
			int z = 4;
			for (int j = 6; j <= i; j++)
			{
				p = p + i - (i - z);
				z++;
			}
			std::cout << p;
		}
		std::cout << "\n";
	}
}