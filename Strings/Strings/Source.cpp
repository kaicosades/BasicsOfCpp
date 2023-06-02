#include <iostream>
#include <Windows.h>

int StringLenght(char* str); // * - указатель на ячейку памяти
using namespace  std;

//#define STR
void main()
{
	setlocale(LC_ALL, "");
	#ifdef STR
	{
		//cout << "Hello String"<< endl;
		//char  str[] = { 'H', 'e', 'l', 'l', 'o' , 0 }; // 0 - убирает мусор в конце
		char str[] = "Hello";
		str[1] = 'o'; // можно менять элементы
		cout << str << endl;

		const char* str2 = "World";
		//элементы нельзя менять потому что константа
		cout << str2 << endl;
	}
	#endif

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: "; //cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE); // getline знает размер строки
	//SetConsoleCP(866);// - вернуть для гарантированного варианта
	cout << str << endl;
	cout << "Размер введенной строки: " << StringLenght(str) << endl;

}

int StringLenght(char* str)
{
	int m = 0;
	for (m; str[m]; m++) {} // квадртаные скобки разименновывет массив
	return m;
}