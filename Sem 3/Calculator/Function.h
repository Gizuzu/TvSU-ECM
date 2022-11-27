#pragma once
#include <iostream>

class Function
{
protected:
	int x;
	char name[30];
public:
	virtual void Calculate() = 0;
	virtual char* GetName() = 0;
};