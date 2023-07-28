#include<iostream>
#include<Windows.h>
//#include<cmath>
#include<math.h>
using namespace std;

CONST double PI = 3.1415926535;

enum Color
{
	console_red = 0xCC, //0x - hexadecimal 
	console_green = 0xAA,
	console_blue = 0x99,
	console_default = 0x07
};

class Shape
{
protected:
	Color color;

public:
	Shape(Color color) :color(color) {}
	virtual ~Shape() {}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;

};

class Square :public Shape
{
	static const int MIN_SIDE = 2;
	static const int MAX_SIDE = 50;
	double side;
public:

	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}

	~Square() {}

	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side < MIN_SIDE)side = MIN_SIDE;
		if (side > MAX_SIDE)side = MAX_SIDE;
		this->side = side;
		//return side;
	}
	double get_area()const override //override используется для переопеределение метода, обязательно
	{
		return side * side;
	}
	double get_perimeter()const override //ctrl+ space
	{
		return side * 4;
	}
	void draw()const override
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
				cout << "* ";
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::console_default);
	}
};

class Triangle : public Shape
{

	static const int MIN_LENGTH = 2;
	static const int MAX_LENGTH = 30;
	static const int MAX_CORNER = 175;
	static const int MIN_CORNER = 5;


	double length_a;
	double length_b;
	double corner;
	double length_c; // Для того, чтобы return area был короче. Третья сторона находится по треореме косинуса


public:

	Triangle(double length_a, double length_b,double corner) :Shape(color)
	{
		set_length_a(length_a);
		set_length_b(length_b);
		set_corner(corner);
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Triangle() {}

	double get_length_a()const
	{
		return length_a;
	}
	void set_length_a(double length_a)
	{
		if (length_a < MIN_LENGTH)length_a = MIN_LENGTH;
		if (length_a > MAX_LENGTH)length_a = MAX_LENGTH;
		this->length_a = length_a;
	}

	
	double get_length_b()const
	{
		return length_b;
	}
	void set_length_b(double length_b)
	{
		if (length_b < MIN_LENGTH)length_b = MIN_LENGTH;
		if (length_b > MAX_LENGTH)length_b = MAX_LENGTH;
		this->length_b = length_b;
	}


	double get_corner()const
	{
		return corner;
	}
	void set_corner(double corner)
	{
		if (corner < MIN_CORNER)corner = MIN_CORNER;
		if (corner > MAX_CORNER)corner = MAX_CORNER;
		this->corner = corner;
	}
	
	double get_length_c()const
	{
		return length_c;
	}
	void set_length_c(double length_c)
	{
		//this->length_c = sqrt(pow(length_a,2) + pow(length_b,2) - 2 * length_a * length_b * cos(corner)); // Теорема Косинуса
		this->length_c = sqrt(length_a* length_a + length_b* length_b - 2 * length_a * length_b * cos(corner * PI / 180)); // Теорема Косинуса
	}

	double get_perimeter()const override //ctrl+ space
	{
		return length_a+ length_b+ length_c;
	}

	double get_area()const override //override используется для переопеределение метода, обязательно
	{
		return sqrt(get_perimeter()/2 * (get_perimeter() / 2-length_a) *(get_perimeter()/2 - length_b)*(get_perimeter()/2- length_c)); //Вычисляется по форме Герона
	}
	void draw()const override
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		for (int i = 0; i < length_a; i++)
		{
			for (int j = 0; j < length_a; j++)
				cout << "* ";
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::console_default);
	}

};

class Circle : public Shape
{
	static const int MIN_RADIUS = 2;
	static const int MAX_RADIUS = 30;

	double radius;

public:

	Circle(double radius, Color color) :Shape(color)
	{
		set_radius(radius);
	}
	~Circle() {}

	double get_radius()const
	{
		return radius;
	}
	void set_radius(double radius)
	{
		if (radius < MIN_RADIUS)radius = MIN_RADIUS;
		if (radius > MAX_RADIUS)radius = MAX_RADIUS;
		this->radius = radius;
	}

	double get_perimeter()const override //ctrl+ space
	{
		return 2*radius*PI;
	}

	double get_area()const override //override используется для переопеределение метода, обязательно
	{
		return PI * radius * radius;
	}

	void draw()const override
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
		for (int i = 0; i < radius; i++)
		{
			for (int j = 0; j < radius; j++)
				cout << "* ";
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::console_default);
	}
};






void main()
{
	setlocale(LC_ALL, "");

	//Shape shape(Color::console_blue);
	Square square(5, Color::console_red);
	cout << "Длинна стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();

	Triangle triangle(3,4,90);
	triangle.set_length_c(0);
	cout << "Периметр треугольника: " << triangle.get_perimeter() << endl;
	//cout << "Третья сторона треугольника: " << triangle.get_length_c() << endl;
	cout << "Площадь треугольника: " << triangle.get_area() << endl;

	Circle circle(5,Color::console_blue);
	cout << "Периметр окружности: " << circle.get_perimeter() << endl;
	cout << "Площадь окружности: " << circle.get_area() << endl;
	
}