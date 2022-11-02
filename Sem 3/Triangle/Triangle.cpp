#define _CRT_SECURE_NO_WARNINGS
#include "Triangle.h"
#include "Point.h"
#include <iostream>
#include <cmath>

int Triangle::count = 0;

Triangle::Triangle()
{
	name_ = new char[32];
	count++;
	sprintf(name_, "Треугольник_%d", count);
	v1_ = Point();
	v2_ = Point();
	v3_ = Point();
	a_ = 0;
	b_ = 0;
	c_ = 0;
}

Triangle::Triangle(const Triangle& obj)
{
	name_ = new char[32];
	count++;
	sprintf(name_, "Треугольник_%d", count);
	v1_ = obj.v1_;
	v2_ = obj.v2_;
	v3_ = obj.v3_;
	a_ = obj.a_;
	b_ = obj.b_;
	c_ = obj.c_;
}

Triangle::Triangle(Point& p1, Point& p2, Point& p3) : v1_(p1), v2_(p2), v3_(p3)
{
	name_ = new char[32];
	count++;
	sprintf(name_, "Треугольник_%d", count);
	//Вычисление длин сторон
	a_ = sqrt((v1_.x_ - v2_.x_) * (v1_.x_ - v2_.x_) + (v1_.y_ - v2_.y_) * (v1_.y_ - v2_.y_));
	b_ = sqrt((v2_.x_ - v3_.x_) * (v2_.x_ - v3_.x_) + (v2_.y_ - v3_.y_) * (v2_.y_ - v3_.y_));
	c_ = sqrt((v1_.x_ - v3_.x_) * (v1_.x_ - v3_.x_) + (v1_.y_ - v3_.y_) * (v1_.y_ - v3_.y_));
}

Triangle::~Triangle() 
{
	count--;
	delete[] name_;
}  

bool Triangle::operator>(Triangle& obj)
{
	if (this->GetArea() > obj.GetArea())
		return true;
	
	return false;
}

Triangle& Triangle::operator=(const Triangle& obj)
{
	v1_ = obj.v1_;
	v2_ = obj.v2_;
	v3_ = obj.v3_;
	a_ = obj.a_;
	b_ = obj.b_;
	c_ = obj.c_;

	return *this;
}


char* Triangle::GetName()
{
	return name_;
}

Point& Triangle::GetPoint(int& index)
{
	if (index == 1)
		return v1_;
	else if (index == 2)
		return v2_;
	else if (index == 3)
		return v3_;
}

void Triangle::Print()
{
	printf("%s -- точки:(%f, %f),(%f, %f),(%f, %f)\n", name_, v1_.x_, v1_.y_, v2_.x_, v2_.y_, v3_.x_, v3_.y_);
}

float Triangle::GetArea()
{
	float p = (a_ + b_ + c_) / 2;
	float s = sqrt(p * (p - a_) * (p - b_) * (p - c_));
	s = round(s * 10) / 10;
	
	return s;
}

void Triangle::Move(Point point)
{
	v1_ += point;
	v2_ += point;
	v3_ += point;
}

bool inTriangle(Triangle& obj, Point& p)
{
	int p1 = 1, p2 = 2, p3 = 3;

	Triangle t1(obj.GetPoint(p1), obj.GetPoint(p2), p);
	Triangle t2(obj.GetPoint(p1), obj.GetPoint(p3), p);
	Triangle t3(obj.GetPoint(p2), obj.GetPoint(p3), p);

	float area = t1.GetArea() + t2.GetArea() + t3.GetArea();

	if (round(obj.GetArea()*10)/10 == area)
		return true;

	return false;
}

bool Triangle::isIncluded(Triangle& obj)
{
	if (inTriangle(obj, v1_))
		if (inTriangle(obj, v2_))
			if (inTriangle(obj, v3_))
				return true;

	return false;
}