#pragma once
#include "Point.h"

class Triangle
{
	char* name_;
	Point v1_, v2_, v3_;
	double a_, b_, c_;
public:
	static int count;
public:
	Triangle();
	Triangle(const Triangle& obj);
	Triangle(Point& p1, Point& p2, Point& p3);
	~Triangle();
	bool operator>(Triangle& obj);
	Triangle& operator=(const Triangle& obj);
	char* GetName();
	Point& GetPoint(int& index);
	void Print();
	float GetArea();
	void Move(Point point);
	bool isIncluded(Triangle& obj);
};
 