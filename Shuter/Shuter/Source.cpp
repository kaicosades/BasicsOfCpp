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
			cout << "�����" << endl;
		switch (y)
		{
		case 'w':
		case 'W': cout << "������" << endl; break;
		case 's':
		case 'S': cout << "�����" << endl; break;
		case 'd':
		case 'D': cout << "������" << endl; break;
		case 'a':
		case 'A': cout << "�����" << endl; break;
		case ' ': cout << "������" << endl; break;
		}
	} while (int(y) != 27);
		
	



}

