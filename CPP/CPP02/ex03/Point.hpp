#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(const float f1, const float f2);
		Point(const Point& other);
		Point &operator=(const Point& other);
		Fixed getXValue() const;
		Fixed getYValue() const;
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
