#pragma once
#include "Function.h"

class Exp : public Function
{
private:
	int n;
	int Factorial(int num);
public:
	Exp();
	char* GetName();
	void Calculate();
	~Exp();
};