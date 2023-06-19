#include <iostream>
using namespace std;


class Point //struct
{
public: // - для класса обратная
	double get_x(void)const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;//указатель чтобы обратиться к объекту зис
	}
	void set_y(double y)
	{
		this->y = y;
	}
//private: // - для структуры обраная
	double x;
	double y;


	double distance(Point other)//внутренняя переменная внутри функции
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(Point A, Point B)//прототип не нужен из за того, что функция вызывается до мейна
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	//return sqrt(pow(A.get_x() - B.get_x(),2) + pow(A.get_y() - B.get_y() , 2));
	//return pow(pow(A.get_x() - B.get_x(),2) + pow(A.get_y() - B.get_y() , 0.5));
}
//#define STRUCT_POINT
//#define DISTANCE_CHECK



void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A; // Объявление переменной А типа Point
			 // Создание объекта А структуры Point
			 // Создания экземпляра А структуры Point

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif


#ifdef DISTANCE_CHECK 
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;


	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки 'A' до точки 'B' :\t" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A' :\t" << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'В' :\t" << distance(A, B) << endl;
	cout << "Расстояние между точками 'A' и 'В' :\t" << distance(B, A) << endl;
#endif

	Point A; //default constructor
	A.print();
}

