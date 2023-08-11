﻿#include<iostream>
using namespace std;

#define RAB "\t"
#define DELIMITER "\n---------------------------------------------\n"

class String
{
	int size; //Размер строки в байтах
	char* str; //Адресс строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;// т к после гетера стоит конст и возвращается ссылка на указатель, то чар тоже должен быть конст
	char* get_str();
	
	//	Constructors:
	explicit String(int size = 80);//this - инициализация в теле конструктора, можно в конструкторе
	String(const char* str);//звездочка в данном случае это строка(массив это указатель)
	String(const String& other); // конструктор копирования
	String(String&& other);
	~String();
	String& operator=(String&& other);
	// Operetors:

	String& operator=(const String& other);//оператор присваивания возвращает ссылку на объкт, принимает конст ссылку на объект
	char operator[](int i)const;
	char& operator[](int i); // Ссылка - разыменнованый указатель
//	Methods:
	void print()const;
};


int String::get_size()const
{
	return size;
}
const char* String::get_str()const// т к после гетера стоит конст и возвращается ссылка на указатель, то чар тоже должен быть конст
{
	return str;
}

char* String::get_str()
{
	return str;
}
//	Constructors:

 String::String(int size /*= 80*/) :size(size), str(new char[size] {})//this - инициализация в теле конструктора, можно в конструкторе
{
	//this->size = size;
	//this->str = new char[size] {}; //фигурные скобки здесь заполняют нулями строку. Иначе мусор будет.
	cout << "DefConstructor:\t" << this << endl;
	//выделять память два раза нельзя

	//со всеми изменениями выделяет память
}

String::String(const char* str) :String(strlen(str) + 1)//звездочка в данном случае это строка(массив это указатель)
{
	//	this->size = strlen(str) + 1;
	//	this->str = new char[size] {};//выделение динамической памяти, потому что мы не знаем какой размер на входе
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;

	//со всеми изменениями заполняет память
}

String::String(const String& other) :String(other.str) // конструктор копирования
{
	//deep copy - побитовое копирование
//  this->size = other.size;
//	this->str = new char[size] {}; //выделение новой памяти
//	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}


String::String(String&& other) :size(other.size), str(other.str)
{
	//shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = 0;
	cout << "MoveConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}



String& String::operator=(String&& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;

	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
// Operetors:

String& String::operator=(const String& other)//оператор присваивания возвращает ссылку на объкт, принимает конст ссылку на объект
{
	if (this == &other)return *this; //other - объект переданный в функцию
	int a = 2;
	int b = 3;
	a = b;
	delete[] this->str;
	//*this = other;
	this->size = other.size;
	this->str = new char[size] {}; //выделение новой памяти
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i) // Ссылка - разыменнованый указатель
{
	return str[i];
}


//	Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}



std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	//const int a = 2;
	//a = 3;
	//String cat();
	String cat(left.get_size() + right.get_size() -1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i]; //квадратные скобки разыменовывают указатель
	for (int i = 0; i < right.get_size(); i++)
		cat[i+left.get_size()-1]=right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}


#define BASE_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK

	cout << sizeof("Hello") << endl;

	String str;
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	cout << DELIMITER << endl;
	String str3 = str1 + " " + str2;
	cout << DELIMITER << endl;
	cout << str3 << endl;

	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;
	// cout << str << endl;
#endif

#ifdef CALLING_CONSTRUCTORS
	String str1;	//defailt constructor
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";	//single-argument constructor
	str3.print();

	String str4();	//Таким образом объект не создается и не вызывается конструктор по умолчанию
					//Таким образом объявляется функция str4(), которая ничего не принимает и возвращает значение типа string

	//str4.print();

	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();
#endif

	String str5 = str4;
	cout << str5 << endl;

}