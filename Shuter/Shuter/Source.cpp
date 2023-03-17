#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	char y;
	do
	{
		y = _getch();
		if (int(y) == 13)
			cout << "Огонь" << endl;
		switch (y)
		{
		case 'w':
		case 'W': cout << "Вперед" << endl; break;
		case 's':
		case 'S': cout << "Назад" << endl; break;
		case 'd':
		case 'D': cout << "Вправо" << endl; break;
		case 'a':
		case 'A': cout << "Назад" << endl; break;
		case ' ': cout << "Прыжок" << endl; break;
		}
	} while (int(y) != 27);
		
	



}

