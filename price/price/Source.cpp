#include<iostream>
//#define TASK_ONE
//#define TASK_TWO
//#define TASK_THREE
//#define TASK_FOUR

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TASK_ONE
	float i;
	int d;
	std::cin >> i;
	d = i;
	std::cout << d << " ��� ";
	i = i - d ;
	std::cout << i * 100 << " ������";
#endif

#ifdef TASK_TWO
	float i;
	float c;
	int d;
	int b;
	std::cout << "��������� ��������� ������.\n"
		"������� ���� �������" << std::endl;
	std::cin >> i;
	std::cout << "������� ���� ���������" << std::endl;
	std::cin >> c;
	std::cout << "������� ���������� ��������\n";
	std::cin >> d;
	std::cout << "������� ���������� ����������\n";
	std::cin >> b;
	std::cout << i * d + c * b << " ���";
#endif

#ifdef TASK_THREE
	float i;
	float c;
	int d;
	std::cout << "��������� ��������� ������.\n"
	"������� ���� �������" << std::endl;
	std::cin >> i;
	std::cout << "������� ���� �������" << std::endl;
	std::cin >> c;
	std::cout << "������� ���������� ����������� \n";
	std::cin >> d;
	std::cout << "��������� �������:" << (i + c) * d << " ���";
#endif

#ifdef TASK_FOUR
	float i;
	float c;
	float s;
	std::cout << "��������� ��������� ������� �� ���� � �������.\n"
		"������� ���������� �� ���� (��)" << std::endl;
	std::cin >> i;
	std::cout << "������� ������ ������� (������ �� 100 �� �������)" << std::endl;
	std::cin >> c;
	std::cout << "���� ����� ������� (���.) \n";
	std::cin >> s;
	std::cout << "������� �� ���� � ������� ��������� � " << 0.02*i*c*s << " ���";
#endif
}