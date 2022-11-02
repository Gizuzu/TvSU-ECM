#include "Point.h"
#include "Triangle.h"
#include <iostream>

Point::Point(const Point& p)
{
	x_ = p.x_;
	y_ = p.y_;
}

Point& Point::operator+=(const Point& p)
{
	x_ += p.x_;
	y_ += p.y_;

	return *this;
}

Point& Point::operator=(const Point& p)
{
	x_ = p.x_;
	y_ = p.y_;

	return *this;
}

void Point::ShowPoint()
{
	printf("(%f,%f)", x_, y_);
}