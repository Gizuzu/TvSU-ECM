#include "Exp.h"

Exp::Exp()
{
	name[0] = 0;
	strcpy(name, "Exp");
	n = 0; x = 0;
}

Exp::~Exp()
{
	delete[] name;
}

char* Exp::GetName()
{
	return name;
}

void Exp::Calculate()
{
	std::cout << "Калькулятор работает..." << std::endl;
	std::cout << "Введите n: ";
	std::cin >> n;
	std::cout << "Введите аргумент (x): ";
	std::cin >> x;

	double res = 0;
	for (int i = 0; i <= n; i++) {
		res += pow(x, i)/Factorial(i);
	}
	std::cout << "e^x= " << 10 << std::endl;
}

int Exp::Factorial(int num)
{
	int res = 1;
	for (int i = 1; i <= num; i++) {
		res = res * i;
	}
	return res;
}