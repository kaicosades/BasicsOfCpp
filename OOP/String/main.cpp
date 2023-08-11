#include "String.h"

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