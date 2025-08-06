#include "Fixed.hpp"
#include "Point.hpp"
#include "cmath"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY()); // Area of triangle ABC
	Fixed areaPAB = (a.getX() - point.getX()) * (b.getY() - point.getY()) - (b.getX() - point.getX()) * (a.getY() - point.getY()); // Area of triangle PAB
	Fixed areaPBC = (b.getX() - point.getX()) * (c.getY() - point.getY()) - (c.getX() - point.getX()) * (b.getY() - point.getY()); // Area of triangle PBC
	Fixed areaPCA = (c.getX() - point.getX()) * (a.getY() - point.getY()) - (a.getX() - point.getX()) * (c.getY() - point.getY()); // Area of triangle PCA

	if (areaABC == 0)
	{
		// If the area of triangle ABC is zero, the points are collinear.
		return false;
	}
	if ((areaPAB > 0 && areaPBC > 0 && areaPCA > 0) || (areaPAB < 0 && areaPBC < 0 && areaPCA < 0))
	{
		// If all areas are positive or all are negative, the point is inside the triangle.
		return true;
	}
	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
	{
		// If any area is zero, the point is on the edge of the triangle.
		return true;
	}
	if ((areaPAB < 0 && areaPBC > 0 && areaPCA > 0) || (areaPAB > 0 && areaPBC < 0 && areaPCA < 0))
	{
		// If the point is outside the triangle.
		return false;
	}
	return (false);
}
