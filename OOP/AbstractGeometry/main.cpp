#include<iostream>
#include<Windows.h>
//#include<cmath>
#include<math.h>
using namespace std;

CONST double PI = 3.1415926535;

namespace Geometry// пространство имен
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		console_red = 0xCC, //0x - hexadecimal.Для консоли задается одним байтом. Для true collor - 4 байта.
		console_green = 0xAA,
		console_blue = 0x99,
		console_default = 0x07
	};

#define SHAPE_TAKE_PARAMETERS int start_x, int start_y, int line_width,Color color
#define SHAPE_GIVE_PARAMETERS  start_x, start_y, line_width, color
	class Shape
	{
		static const int MIN_START_X = 10;
		static const int MIN_START_Y = 10;
		static const int MAX_START_X = 500;
		static const int MAX_START_Y = 400;
		static const int MIN_LINE_WIDTH = 5;
		static const int MAX_LINE_WIDTH = 25;
	protected:
		int start_x;
		int start_y;
		int line_width;
		Color color;

	public:
		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		int get_start_x()const
		{
			return start_x;
		}

		int get_start_y()const
		{
			return start_y;
		}

		int line_width()const
		{
			return line_width;
		}

		/*void set_start_x(int start_x)
		{

		}*/

		void set_start_x(int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
		}

		void set_start_y(int start_y)
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
		}

		void set_line_width(int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << "Площадь фигруры: " << get_area() <<endl;
			cout << "Периметр фигруры: " << get_perimeter() <<endl;
			draw();
		}
	};

	//class Square :public Shape
	//{
	//	static const int MIN_SIDE = 2;
	//	static const int MAX_SIDE = 50;
	//	double side;
	//public:

	//	Square(double side, Color color) :Shape(color)
	//	{
	//		set_side(side);
	//	}

	//	~Square() {}

	//	double get_side()const
	//	{
	//		return side;
	//	}
	//	void set_side(double side)
	//	{
	//		if (side < MIN_SIDE)side = MIN_SIDE;
	//		if (side > MAX_SIDE)side = MAX_SIDE;
	//		this->side = side;
	//		//return side;
	//	}
	//	double get_area()const override //override используется для переопеределение метода, обязательно
	//	{
	//		return side * side;
	//	}
	//	double get_perimeter()const override //ctrl+ space
	//	{
	//		return side * 4;
	//	}
	//	void draw()const override
	//	{
	//		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//		SetConsoleTextAttribute(hConsole, color);
	//		for (int i = 0; i < side; i++)
	//		{
	//			for (int j = 0; j < side; j++)
	//				cout << "* ";
	//			cout << endl;
	//		}
	//		SetConsoleTextAttribute(hConsole, Color::console_default);
	//	}

	//	void info()const override
	//	{
	//		cout << typeid(*this).name() << endl;
	//		cout << "Длинна стороны: " << side << endl;
	//		Shape::info();
	//	}
	//};

	class Rectangle :public Shape
	{

		static const int MIN_SIDE = 2;
		static const int MAX_SIDE = 50;

		double side_a;
		double side_b;
	public:
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		void set_side_a(double side_a)
		{
			if (side_a < MIN_SIDE)side_a = MIN_SIDE;
			if (side_a > MAX_SIDE)side_a = MAX_SIDE;
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			if (side_b < MIN_SIDE)side_b = MIN_SIDE;
			if (side_b > MAX_SIDE)side_b = MAX_SIDE;
			this->side_b = side_b;
		}
		Rectangle(double side_a, double side_b, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~Rectangle() {}

		double get_area()const override
		{
			return side_a * side_b;
		}
		double get_perimeter()const override
		{
			return (side_a + side_b) * 2;
		}
		void draw()const override
		{
			// 1) получаем окно консоли
			HWND hwnd = GetConsoleWindow(); //Функция getConsoleWindow() возвращает hwnd окна консоли из текущего потока
			//HWND - Hander to Wondow (Обработчик окна)
			// К переменной можно обратиться по имени, к окну можно обратиться через hwnd этого окна
			// 
			// 2) создаем контекст устройства
			HDC hdc = GetDC(hwnd);
			// контекст устройства есть абсолютно у каждого окна.
			// рисовать можно только на контексте устройства
			// функция GetDC(hwnd) возвращает контекст устройства заданного окна
			// 
			// 3) создаем кисть и карандаш 
			HPEN hPen = CreatePen(PS_SOLID, 5, color); //карандаш рисует контур фигуры, второй параметр - толщина линии.
			HBRUSH hBrush = CreateSolidBrush(color); //кисть заливает цветом фигуру
			// 4) выбираем чем и на чем будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			// 5) рисуем фигуру. Координаты идут от левого верхнего угла. Вправо - х, вниз - у
			::Rectangle(hdc, start_x, start_y, start_x+side_a, start_y+side_b); // координаты верхней левого угла и нижнего правого, двоиточие - глобальное пространство имен.

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}

		

		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона 'a' : " << side_a << endl;
			cout << "Сторона 'b' : " << side_b << endl;
			Shape::info();
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

		Triangle(double length_a, double length_b, double corner) :Shape(color)
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
			this->length_c = sqrt(length_a * length_a + length_b * length_b - 2 * length_a * length_b * cos(corner * PI / 180)); // Теорема Косинуса
		}

		double get_perimeter()const override //ctrl+ space
		{
			return length_a + length_b + length_c;
		}

		double get_area()const override //override используется для переопеределение метода, обязательно
		{
			return sqrt(get_perimeter() / 2 * (get_perimeter() / 2 - length_a) * (get_perimeter() / 2 - length_b) * (get_perimeter() / 2 - length_c)); //Вычисляется по форме Герона
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
			return 2 * radius * PI;
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

	class Square : public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) : Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
}





void main()
{
	setlocale(LC_ALL, "");

	//Shape shape(Color::console_blue);
	Geometry::Square square(5, 100,100,5,Geometry::Color::console_red);
	square.info();
	/*cout << "Длинна стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/

	//Geometry::Triangle triangle(3,4,90);
	//triangle.set_length_c(0);
	//cout << "Периметр треугольника: " << triangle.get_perimeter() << endl;
	////cout << "Третья сторона треугольника: " << triangle.get_length_c() << endl;
	//cout << "Площадь треугольника: " << triangle.get_area() << endl;

	//Geometry::Circle circle(5, Geometry::Color::console_blue);
	//cout << "Периметр окружности: " << circle.get_perimeter() << endl;
	//cout << "Площадь окружности: " << circle.get_area() << endl;
	
	Geometry::Rectangle rect(30, 15,100,300,5, Geometry::Color::blue);
	/*cout << "Строна 'a' : " << rect.get_side_a() << endl;
	cout << "Строна 'b' : " << rect.get_side_b() << endl;
	cout << "Площадь прямоугольника: " << rect.get_area() << endl;
	cout << "Периметр прямоугольника: " << rect.get_perimeter() << endl;
	rect.draw();*/
	rect.info();


}