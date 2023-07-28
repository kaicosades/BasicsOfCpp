#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:

	int get_integer()const
	{
		return integer;
	}

	int get_numerator()const
	{
		return numerator;
	}

	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void set_numerator(int numenator)
	{
		this->numerator = numenator;
	}
	
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

		//constuctors:

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstruction:\t" << this << endl;
	}

	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9; //точность всегда будет 9 знаков после запятой
		numerator = decimal * denominator;
		reduce();
		cout << "1ArgDConstructor:\t" << this << endl;
	}


	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor :\t" << this << endl;
	}

	Fraction(int integer , int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor :\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

		//Type-cast operators:

	explicit operator int() //тип возвращаемого значения не указывается
	{
		return integer; //метод позволяет писать а=А, где А - объект
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}


		//Methods:

	Fraction& reduce()
	{
		//int more, less, rest;
		//if (numerator ) denominator)more = numerator, less = denominator;
		//else less = numerator, more = denominator;
		to_proper();
		int less = numerator;
		int more = denominator;
		int rest;
		if (less == 0)return *this;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // greatest common divisor (наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}


	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	//Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other) // прототип в начале строк и объявить класс - class Fraction; после прототипа функции
	{
		return *this = *this * other;
	}


};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}


//Fraction operator/(Fraction left, Fraction right) //у ОА нет в коде, сделал ниже
//{
//	left.to_improper();
//	right.to_improper();
//	return Fraction
//	(
//		left.get_numerator() * right.get_denominator(),
//		left.get_denominator() * right.get_numerator()
//	).to_proper();
//}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}


bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}


bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}



bool operator>=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
	//return !(left<right);
}


bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
	//return !(left>right);
}

Fraction operator/(const Fraction& left, const Fraction& right) //слож вычитание самим
{
	return left * right.inverted();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}


std::istream& operator>>(std::istream& is, Fraction& obj)
{

	const int SIZE = 256;
	char buffer[SIZE] = {};
	is >> buffer;
	//is.getline(buffer, SIZE);//был cin вмессто is
	int number[3] = {};
	int n = 0; //счетчик введенных чисел
	char delimiters[] = "()/ ";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))//перед первой итерацией инициализация и присваивание pch срабатывает один раз
		number[n++] = std::atoi(pch);
	//atoi() - ASCII-string to 'int', принимает строку и возвращает целое число, которое содержится в этой строке
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;//obj.set_integer(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]);break;
		/*obj.set_numerator(number[0]); 
		obj.set_denominator(number[1]);
		break;*/
	case 3: obj = Fraction(number[0], number[1], number[2]);
		/*obj.set_integer(number[0]); 
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);*/
		
		
			/*int integer, numerator, denominator;
			is >> integer >> numerator >> denominator;
			obj.set_integer(integer);
			obj.set_numerator(numerator);
			obj.set_denominator(denominator);
			*/

	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define DZ_26
//#define DZ_30
//#define IMPUT_CHECK_1
//#define IMPUT_CHECK_2
//#define CONVERTION_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C; //Copy constructor
	E.print();

	Fraction F;
	F = D;
	F.print();
#endif

#ifdef DZ_26
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	A.to_improper();
	A.print();

	A.to_proper();
	A.print();

	Fraction C = A * B; //закоментить с и д
	C.print();

	Fraction D = A / B;
	D.print();

	A *= B;
	A.print();
#endif

#ifdef COMPARISON_OPERATORS_CHECK

		Fraction A(1, 2);
	Fraction B(5, 11);
	cout << (A > B) << endl;

#endif


#ifdef DZ_30
	Fraction A(5, 10);
	A.print();
	A.reduce();
	A.print();
#endif

#ifdef INPUT_CHECK_1
	Fraction A(5, 10);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
	A.reduce();
	cout << A << endl;
#endif

#ifdef INPUT_CHECK_2
	Fraction A, B, C;
	cout << "Введите три простые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B << "\t" << C << endl;
#endif

#ifdef CONVERTION_FROM_CLASS_TO_OTHER

	Fraction A(2, 1, 2);
	cout << A << endl;
	double a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;

#endif

	Fraction A = 2.76;
	std::cout << A << std::endl;
 }