#include<iostream>
using namespace std;

#define delimeter "\n---------------------------------------\n"

int Sum(int a, int b);
int Dif(int a, int b);
int Product(int a, int b);
double Quotient(double a, double b);
int Reminder(int a, int b);
int Factorial(int a);
float Power(float a, float b);


void main()
{
	setlocale(LC_ALL, "");
	int a, b;
	cout << "¬ведите два числа: "; cin >> a >> b;

	int c = Sum(a, b);
	cout << a << " + " << b << " = " << c << endl;
	cout << a << " - " << b << " = " << Dif(a, b) << endl;
	cout << a << " * " << b << " = " << Product(a, b) << endl;
	cout << a << " / " << b << " = " << Quotient(a, b) << endl;
	cout << a << " % " << b << " = " << Reminder(a, b) << endl;
	cout << "‘акториал " << a << " = " << Factorial(a) << endl;
	cout << a << " ^ " << b << " = " << Power(a, b) << endl;


}

int Sum(int a, int b)
{
	int c = a + b;
	return c;
}
int Dif(int a, int b)
{
	//difference - разность
	return a - b;
}
int Product(int a, int b) // произведение
{
	return a * b;
}
double Quotient(double a, double b) // частное
{
	return a / b;
}
int Reminder(int a, int b)
{
	return a % b;
}

int Factorial(int a)
{
	for (int i = a; i > 1; i--) a *= i - 1;
	return a;
}

float Power(float a, float b)
{
	if (b < 0)
	{
		a = 1 / a;
		b *= -1;
	}
	if (b == 0) a = 1;
	float n = a;
	for (b; b > 1; b--)n *= a;
	return n;
}