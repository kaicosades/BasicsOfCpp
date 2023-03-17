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
	std::cout << d << " грн ";
	i = i - d ;
	std::cout << i * 100 << " копеек";
#endif

#ifdef TASK_TWO
	float i;
	float c;
	int d;
	int b;
	std::cout << "Вычислите стоимость покупи.\n"
		"Введите цену тетради" << std::endl;
	std::cin >> i;
	std::cout << "Введите цену карандаша" << std::endl;
	std::cin >> c;
	std::cout << "Введите количество тетрадей\n";
	std::cin >> d;
	std::cout << "Введите количество карандашей\n";
	std::cin >> b;
	std::cout << i * d + c * b << " грн";
#endif

#ifdef TASK_THREE
	float i;
	float c;
	int d;
	std::cout << "Вычислите стоимость покупи.\n"
	"Введите цену тетради" << std::endl;
	std::cin >> i;
	std::cout << "Введите цену обложки" << std::endl;
	std::cin >> c;
	std::cout << "Введите количество компонентов \n";
	std::cin >> d;
	std::cout << "Стоимость покупки:" << (i + c) * d << " грн";
#endif

#ifdef TASK_FOUR
	float i;
	float c;
	float s;
	std::cout << "Вычислите стоимость поездки на дачу и обратно.\n"
		"Введите расстояние до дачи (км)" << std::endl;
	std::cin >> i;
	std::cout << "Введите Расход бензина (литров на 100 км пробега)" << std::endl;
	std::cin >> c;
	std::cout << "цена литра бензина (грн.) \n";
	std::cin >> s;
	std::cout << "Поездка на дачу и обратно обойдется в " << 0.02*i*c*s << " грн";
#endif
}