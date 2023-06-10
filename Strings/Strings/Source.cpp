#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <ctype.h>

int StringLenght(char* str); // * - указатель на ячейку памяти
void to_lower(char* str);
void to_upper(char* str);
void shrink(char* str);
void is_palindrome(char* str);
void is_int_number(char* str);

char* remove_symbol(char str[], char symbol);
char* to_upper_OA(char str[]);
char* to_upper_OA_2(char str[]); //tolower в обратной функции
char* shrink_OA(char str[]);
bool is_palindrome_OA(const char str[]);

bool is_int_number_TWO(const char str[]);
char* to_int_number(char str[]);

bool is_bin_number(const char str[]);
int to_bin_number(char str[]);

bool is_hex_number(const char str[]);
int to_hex_number(const char str[]);

using namespace  std;

//#define STR
//#define STR_2

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
	char str[SIZE] = "abc"; //{} -для объявления пустой

#ifdef STR_2
	{
		cout << "Введите строку: "; //cin >> str;
		SetConsoleCP(1251);
		cin.getline(str, SIZE); // getline знает размер строки
		//SetConsoleCP(866);// - вернуть для гарантированного варианта
	}
#endif

	cout << str << endl;
	cout << "Размер введенной строки: " << StringLenght(str) << endl;
	//cout << "Строка в нижнем регистре : ";
	//to_lower(str);
	//cout << str << endl;
	//cout << "Строка в верхнем регистре : ";
	//to_upper(str);
	//cout << str << endl;
	//cout << "Строка без лишних пробелов : ";
	//shrink(str);
	//cout << str << endl;
	//cout << "Размер введенной строки: " << StringLenght(str) << endl;
	//is_palindrome(str);
	//is_int_number(str);
	//cout << to_upper_OA(str) << endl;
	cout << shrink_OA(str) << endl;
	cout << typeid(str).name() << endl;
	//is_palindrome_OA(str);
	cout << "Строка " << (is_palindrome_OA(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	//is_int_number_TWO(str);
	cout << "Строка " << (is_int_number_TWO(str) ? "" : "НЕ ") << "является целым числом" << endl;
	cout << (is_int_number_TWO(str) ? to_int_number(str) : "") << endl;
	cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	//cout << (is_bin_number(str) ? to_bin_number(str) : "") << endl;										//	-Не компилится
	if (is_bin_number(str))
	{
		cout << to_bin_number(str) << endl;
	}
	cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является шестнадцатиричным числом" << endl;
	if (is_hex_number(str))
	{
		cout << to_hex_number(str) << endl;
	}
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
		if ((int)str[m] < 48 || (int)str[m] > 57)
			integer++;
	}
	if (integer > 0) cout << "Строка не является целым числом.";
	else
	{
		cout << "Строка является целым числом.";
		to_int_number(str);
	}
}

char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)for (int j = i; str[j]; j++) str[j] = str[j + 1];
	}
	return str;
}
char* to_upper_OA(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;
		if (str[i] == 'ё')str[i] -= 16;
	}
	return str;
}
char* to_upper_OA_2(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}
char* shrink_OA(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')for (int j = i + 1; str[j]; j++) str[j] = str[j + 1];
	}
	while(str[0] == ' ')for (int i = 0; str[i]; i++) str[i] = str[i + 1];
	return str;
}
bool is_palindrome_OA(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);// - копирует в буфер строку
	to_upper_OA(buffer);
	remove_symbol(buffer, ' ');
	//cout << str;
	n = strlen(buffer);
	//cout << buffer;
	for (int i = 0; i<n/2; i++)
	{
		if (buffer[i] != buffer[n - i - 1])
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}

bool is_int_number_TWO(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	n = strlen(buffer);
	for (int i=0; buffer[i]; i++)
	{
		int m = (int)buffer[i];
		if ((int)buffer[i] < 48 || (int)buffer[i] > 57)
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}
char* to_int_number(char str[])
{
	return str;
}

bool is_bin_number(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	n = strlen(buffer);
	for (int i = 0; buffer[i]; i++)
	{
		int m = (int)buffer[i];
		if ((int)buffer[i] < 48 || (int)buffer[i] > 49)
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}
int to_bin_number(char str[])
{
	int n = StringLenght(str);
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int pow = 1;
		for (int j = 0; j < n - i - 1; j++)pow *= 2;
		result += ((int)str[i] - 48) * pow;
	}
	return result;
}

bool is_hex_number(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	to_upper_OA(buffer);
	n = strlen(buffer);
	for (int i = 0; buffer[i]; i++)
	{
		int m = (int)buffer[i];
		if (((int)buffer[i] < 48 || (int)buffer[i] > 70) || ((int)buffer[i] > 57 && ((int)buffer[i] < 65)))
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}
int to_hex_number(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	to_upper_OA(buffer);
	n = strlen(buffer);
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int k = (int)buffer[i] - 48; //Коэфицент который нужно умножить на степень
		int pow = 1;
		if ((int)buffer[i] > 64 && (int)buffer[i] < 71)
		{
			k = (int)buffer[i] - 55;
		}
		for (int j = 0; j < n - i - 1; j++)
		{
			pow *= 16;
		}
		result += k * pow;
	}
	delete buffer;
	return result;
}