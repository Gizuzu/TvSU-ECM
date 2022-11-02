#pragma once

class Point
{
public:
	float x_;
	float y_;
public:
	Point(float x = 0, float y = 0) : x_(x), y_(y) {}
	Point(const Point& p);
	void ShowPoint();
	Point& operator=(const Point& p);
	Point& operator+=(const Point &p);
};