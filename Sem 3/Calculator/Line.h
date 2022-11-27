#pragma once
#include "Function.h"

class Line : public Function
{
private:
	int a, b;
public:
	Line();
	char* GetName();
	void Calculate();
	~Line();
};