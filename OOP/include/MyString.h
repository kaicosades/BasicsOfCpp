#pragma once

#include<iostream>
using namespace std;

#define RAB "\t"
#define DELIMITER "\n---------------------------------------------\n"

class String
{
	int size; //������ ������ � ������
	char* str; //������ ������ � ������������ ������
public:
	int get_size()const;
	const char* get_str()const;// � � ����� ������ ����� ����� � ������������ ������ �� ���������, �� ��� ���� ������ ���� �����
	char* get_str();

	//	Constructors:
	explicit String(int size = 80);//this - ������������� � ���� ������������, ����� � ������������
	String(const char* str);//��������� � ������ ������ ��� ������(������ ��� ���������)
	String(const String& other); // ����������� �����������
	String(String&& other);
	~String();
	String& operator=(String&& other);
	// Operetors:

	String& operator=(const String& other);//�������� ������������ ���������� ������ �� �����, ��������� ����� ������ �� ������
	char operator[](int i)const;
	char& operator[](int i); // ������ - �������������� ���������
	//	Methods:
	void print()const;
};

std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);