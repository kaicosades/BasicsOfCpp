
#include<iostream>
using namespace std;
//#define ASSIGNMENT_OPERATOR
//#define INCREMENT_DECREMENT
#define COMPOUND_ASSIGMENTS
#define COMPARISON_OPERATORS
#define LOGICAL_OPERATORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef ASSIGNMENT_OPERATOR	
	3;
	-3;		//unary minus
	8 - 3;	//binary minus
	8 * 3;	//binaty aster
	//*3  такой оператор может быть только бинарным

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
#endif

#ifdef INCREMENT_DECREMENT
	int i = 0;
	int j = i++;
	cout << i << endl;
	cout << j << endl;
#endif

#ifdef COMPOUND_ASSIGMENTS

#endif

#ifdef COMPARISON_OPERATORS

#endif

#ifdef LOGICAL_OPERATORS

#endif
}