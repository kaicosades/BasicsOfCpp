#include <iostream>
#include <Windows.h>

int StringLenght(char* str); // * - ��������� �� ������ ������
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

}

int StringLenght(char* str)
{
	int m = 0;
	for (m; str[m]; m++) {} // ���������� ������ �������������� ������
	return m;
}