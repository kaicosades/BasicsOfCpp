#include<iostream>
using namespace std;

class String
{
	int size; //Размер строки в байтах
	char* str; //Адресс строки в динамической памяти
public:
	//	Constructors:

	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {}; //фигурные скобки здесь заполняют нулями строку. Иначе мусор будет.
		cout << "DefConstructor:\t" << this << endl;

	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//	Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}


};


void main()
{
	setlocale(LC_ALL, "");
	cout << sizeof("Hello") << endl;

	String str;
	str.print();

	// cout << str << endl;
}