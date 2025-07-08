#include "Point.hpp"

static Fixed crossProduct( Point const a, Point const b, Point const c)
{
	Fixed abx = b.getXValue() - a.getXValue();
	Fixed aby = b.getYValue() - a.getYValue();
	Fixed acx = c.getXValue() - a.getXValue();
	Fixed acy = c.getYValue() - a.getYValue();
	return abx * acy - acx * aby; 
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed s1 = crossProduct(a, b, point);
	Fixed s2 = crossProduct(c, a, point);
	Fixed s3 = crossProduct(b, c, point);

	if ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0))
		return true;
	return false;
}