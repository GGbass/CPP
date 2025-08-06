#include "Fixed.hpp"
#include "Point.hpp"
#include "cmath"

static bool bspAreas(Fixed areaABC, Fixed areaPAB, Fixed areaPBC, Fixed areaPCA)
{
	if (areaABC == 0) // If the area of triangle ABC is zero, the points are collinear.
		return (false);
	if ((areaPAB > 0 && areaPBC > 0 && areaPCA > 0) || (areaPAB < 0 && areaPBC < 0 && areaPCA < 0)) // If all areas are positive or all are negative, the point is inside the triangle.
		return (true);
	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0) // If any area is zero, point is on the edge
		return (true);
	if ((areaPAB < 0 && areaPBC > 0 && areaPCA > 0) || (areaPAB > 0 && areaPBC < 0 && areaPCA < 0)) // If the point is outside the triangle.
		return (false);
	return (false);
}

// formula Signed Area = x₁(y₂ - y₃) + x₂(y₃ - y₁) + x₃(y₁ - y₂)
// area abc = (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)
// area pab = (a.x - point.x) * (b.y - point.y) - (b.x - point.x) * (a.y - point.y)
// area pbc = (b.x - point.x) * (c.y - point.y) - (c.x - point.x) * (b.y - point.y)
// area pca = (c.x - point.x) * (a.y - point.y) - (a.x - point.x) * (c.y - point.y)

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
	Fixed	areaPAB = (a.getX() - point.getX()) * (b.getY() - point.getY()) - (b.getX() - point.getX()) * (a.getY() - point.getY());
	Fixed	areaPBC = (b.getX() - point.getX()) * (c.getY() - point.getY()) - (c.getX() - point.getX()) * (b.getY() - point.getY());
	Fixed	areaPCA = (c.getX() - point.getX()) * (a.getY() - point.getY()) - (a.getX() - point.getX()) * (c.getY() - point.getY());
	return (bspAreas(areaABC, areaPAB, areaPBC, areaPCA));
}
