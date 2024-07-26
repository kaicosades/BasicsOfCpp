#include <iostream>

//#define UMNOZHENIE
//#define PIFAGOR

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef UMNOZHENIE
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}
		std::cout << std::endl;
	}
#endif 

#ifdef PIFAGOR
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if(i*j<10)
			std::cout << i * j << "  ";
			else
			std::cout << i * j << " ";
		}
		std::cout << std::endl;
	}
#endif

}