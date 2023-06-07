#include <iostream>
#include <Windows.h>

int StringLenght(char* str); // * - указатель на ячейку памяти
void to_lower(char* str);
void to_upper(char* str);
void shrink(char* str);
void is_palindrome(char* str);
void is_int_number(char* str);
int to_int_number(char* str);

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
	cout << "Строка в нижнем регистре : ";
	//to_lower(str);
	cout << str << endl;
	cout << "Строка в верхнем регистре : ";
	//to_upper(str);
	cout << str << endl;
	cout << "Строка без лишних пробелов : ";
	//shrink(str);
	cout << str << endl;
	cout << "Размер введенной строки: " << StringLenght(str) << endl;
	is_palindrome(str);
	is_int_number(str);
	
}

int StringLenght(char* str)
{
	int m = 0;
	for (m; str[m]; m++) {} // квадртаные скобки разименновывет массив
	return m;
}
void to_lower(char* str)
{
	int m = 0;
	for (m; str[m]; m++)
	{
		if (((int)str[m] >= 65 && (int)str[m] <= 90) || ((int)str[m] >= -64 && (int)str[m] <= -33))
			str[m] = (int)str[m] + 32;
		//cout << (int)str[m];
	}
	//return str[256];
}
void to_upper(char* str)
{
	int m = 0;
	for (m; str[m]; m++)
	{
		if (((int)str[m] >= 97 && (int)str[m] <= 122) || ((int)str[m] >= -32 && (int)str[m] <= -1))
			str[m] = (int)str[m] - 32;
		//cout << (int)str[m];
	}
}
void shrink(char* str)
{
	int m = 0;
	for (m; str[m];m++)
	{
		int i = 1; //Когда след элемент не пробел
		int whitespace = 0; //Сколько пробелов за один цикл
		if(str[m] == ' ')
		{
			for (str[m + i]; str[m+i] == ' '; i++)
				whitespace++;
		}
		for(whitespace; whitespace > 0; whitespace--)
		{
			int n = m; //элементы после проверенного массива, которые нужно передвинуть
			for (n; str[n]; n++)
				str[n] = str[n + 1];
		}
	}
}
void is_palindrome(char* str)
{
	int m = 0;
	int sum = StringLenght(str);
	int end = sum;
	int p = 0;
	for (m; m < sum/2; m++)
	{
		if (str[m] == str[end-1])
			end--;
		else
			p++;
	} 
	if (p > 0)
		cout << "Срока не является полиндромом." << endl;
	else
		cout << "Строка является полиндромом." << endl;
}
void is_int_number(char* str)
{
	int m = 0;
	int integer = 0;
	for (m; str[m]; m++) 
	{
		if ((int)str[m] < 48 && (int)str[m] > 57)
			integer++;
	}
	if (integer > 0) cout << "Строка не является целым числом.";
	else
	{
		cout << "Строка является целым числом.";
		to_int_number(str);
	}
}
int to_int_number(char* str)
{
	return *str;
}















//void shrink(char* str)
//{
//	int m = 0;
//	for (m; str[m];)
//	{
//		int i = 0;
//		if ((str[m] == ' ') && (str[m + 1] == ' '))
//		{
//			for (i = m+ 1; str[i] == ' '; i++)
//				str[i] = str[i + 1];
//		}
//		else
//			m++;
//		//cout << (int)str[m];
//	}
//}