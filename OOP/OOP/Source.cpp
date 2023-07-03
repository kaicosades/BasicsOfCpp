#include <iostream>
using namespace std;

#define delimiter "\n------------------------\n"

class Point		//struct
{
public:			// - для класса обратная
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
		this->x = x;		//указатель чтобы обратиться к объекту зис
	}
	
	void set_y(double y)
	{
		this->y = y;
	}
				//private: // - для структуры обраная
	double x;
	
	double y;


				// constructors:

	/*Point()
	{
		x = y = double(); //type() - то значение по умолчанию для заданного типа
		// таким образом якобы вызывается конструктор по умолчанию для заданного типа

		cout << "DefaultConstructor:\t" << this << endl;
	}*/

	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/

	Point(double x = 0, double y = 0) //универсальный параметр отрабатывает во всех случаях - без других.
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

			// operators:

	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}

	Point& operator++(int)
	{
		Point old = *this; // сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}

			// methods:

	double distance(const Point& other)const//внутренняя переменная внутри функции
	{
		//other.x *= 10;
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


Point operator+(const Point& left, const Point& right)
{
	//Point result;
	//result.set_x(left.get_x() + right.get_x());
	//result.set_y(left.get_y() + right.get_y());

	//Point result// можно в строчку писать
	//(
	//	left.get_x() + right.get_x(), 
	//	left.get_y() + right.get_y()
	//);
	//return result;

	return Point
	(
		left.get_x() + right.get_x(),
		left.get_y() + right.get_y()
	);
}

ostream& operator << (ostream& os, const Point& obj)
{
	return	os << " X= " << obj.get_x() << "\tY = " << obj.get_y();
}

double distance(const Point& A,const Point& B)//прототип не нужен из за того, что функция вызывается до мейна. Указаель ставиться для того, чтобы не вызывался конструктор
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	//return sqrt(pow(A.get_x() - B.get_x(),2) + pow(A.get_y() - B.get_y() , 2));
	//return pow(pow(A.get_x() - B.get_x(),2) + pow(A.get_y() - B.get_y() , 0.5));
}


//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define CONSTRUCTORS_CHECK
//#define INCREMENT_CHECK

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
	cout << delimiter << endl;

	cout << "Расстояние от точки 'A' до точки 'B' :\t" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A' :\t" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'В' :\t" << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'В' :\t" << distance(B, A) << endl;
	cout << delimiter << endl;
#endif

#ifdef ASSIGNMENT_CHECK
	Point A; //default constructor
	A.print();

	Point B = 5; //singe argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C; //copyConstructor
	D.print(); //По идеедолжен быть CONSTRUCTORS_CHECK, но из за пропущенной пары где то пропустил

	Point E;
	E = D; // copyAssignemtn
	E.print();


#endif

#ifdef INCREMENT_CHECK
		int a = 2;
		int b = 3;
		int c = a + b;
		cout << c << endl;

		Point A(2, 3);
		Point B(7, 8);
		Point C = A + B;
		C.print();

		A = ++B;
		A.print();
		B.print();
		//cout << typeid(cout).name() << endl;
		cout << A << endl;
#endif
	
		Point A(2, 3);
		A.print();

		Point B(7, 8);
		B.print();

		A += B;
		A.print();

}

