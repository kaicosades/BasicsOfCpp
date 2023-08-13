#pragma once

#include<iostream>
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

std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);