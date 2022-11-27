#include "Line.h"

Line::Line()
{
	name[0] = 0;
	strcpy(name, "Line");
	a = 0; b = 0; x = 0;
}

Line::~Line()
{
	delete[] name;
}

char* Line::GetName()
{
	return name;
}

void Line::Calculate()
{
	std::cout << "Калькулятор работает..." << std::endl;
	std::cout << "Введите a, b: ";
	std::cin >> a >> b;
	std::cout << "Введите аргумент (x): ";
	std::cin >> x;
	std::cout << "y= " << (a * x + b) << std::endl;
}