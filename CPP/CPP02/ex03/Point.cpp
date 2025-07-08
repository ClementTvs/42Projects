#include "Point.hpp"

Point::Point(){
	x = Fixed( 0 );
	y = Fixed( 0 );
};

Point::Point(const float f1, const float f2){
	x = Fixed( f1 );
	y = Fixed( f2 );
}

Point::Point( const Point& other ): x(other.x), y(other.y){};

Point &Point::operator=(const Point& other){
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
};

Fixed Point::getXValue() const{
	return this->x;
}

Fixed Point::getYValue() const{
	return this->y;
}

Point::~Point(){};