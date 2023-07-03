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


		//Methods:


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

	bool operator==(Fraction left, Fraction right)
(
	left.to_improver();
	right.to_improver();
	return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
)

bool operator!=(const Fraction& left, const Fraction& right)
(
	return !(left==right);
)


bool operator<(Fraction left, Fraction right)
(
	left.to_improver();
	right.to_improver();
	return left.get_numerator()*right.get_denominator() < right.get_numerator()*left.get_denominator();
)


bool operator>(Fraction left, Fraction right)
(
	left.to_improver();
	right.to_improver();
	return left.get_numerator()*right.get_denominator() > right.get_numerator()*left.get_denominator();
)



bool operator>=(const Fraction& left, const Fraction& right)
(
	return left>right || left == right;
	//return !(left<right);
)


bool operator<=(const Fraction& left, const Fraction& right)
(
	return left<right || left == right;
	//return !(left>right);
)

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


Fraction operator/(const Fraction& left, const Fraction& right) //слож вычитание самим
{
	return left * right.inverted();
}

//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define DZ_26

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

	Fraction A(5, 10)
		A.print();
	A.reduce();
	A.print();

}