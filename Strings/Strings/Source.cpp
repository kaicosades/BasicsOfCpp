#include <iostream>
#include <Windows.h>

int StringLenght(char* str); // * - ��������� �� ������ ������
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
		//char  str[] = { 'H', 'e', 'l', 'l', 'o' , 0 }; // 0 - ������� ����� � �����
		char str[] = "Hello";
		str[1] = 'o'; // ����� ������ ��������
		cout << str << endl;

		const char* str2 = "World";
		//�������� ������ ������ ������ ��� ���������
		cout << str2 << endl;
	}
	#endif

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "������� ������: "; //cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE); // getline ����� ������ ������
	//SetConsoleCP(866);// - ������� ��� ���������������� ��������
	cout << str << endl;
	cout << "������ ��������� ������: " << StringLenght(str) << endl;
	cout << "������ � ������ �������� : ";
	//to_lower(str);
	cout << str << endl;
	cout << "������ � ������� �������� : ";
	//to_upper(str);
	cout << str << endl;
	cout << "������ ��� ������ �������� : ";
	//shrink(str);
	cout << str << endl;
	cout << "������ ��������� ������: " << StringLenght(str) << endl;
	is_palindrome(str);
	is_int_number(str);
	
}

int StringLenght(char* str)
{
	int m = 0;
	for (m; str[m]; m++) {} // ���������� ������ �������������� ������
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
		int i = 1; //����� ���� ������� �� ������
		int whitespace = 0; //������� �������� �� ���� ����
		if(str[m] == ' ')
		{
			for (str[m + i]; str[m+i] == ' '; i++)
				whitespace++;
		}
		for(whitespace; whitespace > 0; whitespace--)
		{
			int n = m; //�������� ����� ������������ �������, ������� ����� �����������
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
		cout << "����� �� �������� �����������." << endl;
	else
		cout << "������ �������� �����������." << endl;
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
	if (integer > 0) cout << "������ �� �������� ����� ������.";
	else
	{
		cout << "������ �������� ����� ������.";
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