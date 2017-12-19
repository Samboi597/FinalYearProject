#include "Ray.h"

Ray::Ray() : o(0.0), d(0.0, 0.0, 1.0) //default constructor
{
}

Ray::Ray(const Point3D& origin, const Vector3D& dir): o(origin),  d(dir)
{
}

Ray::Ray(const Ray& ray) : o(ray.o), d(ray.d)
{
}

Ray::~Ray() //destructor
{
}

Ray& Ray::operator= (const Ray& rhs) //assignment operator
{
	if (this == &rhs)
	{
		return (*this);
	}

	o = rhs.o;
	d = rhs.d;
	return (*this);
}
