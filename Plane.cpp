// 2017-18 Samuel Mounter
// All rights reserved

#include "Plane.h"
const double Plane::kEpsilon = 0.001;

Plane::Plane() : GeometricObject(), a(0.0), n(0, 1, 0)
{
}

Plane::Plane(const Point3D & point, const Normal & normal) : GeometricObject(), a(point), n(normal)
{
	n.normalise();
}

Plane::Plane(const Plane & plane) : GeometricObject(plane), a(plane.a), n(plane.n)
{
}

Plane * Plane::clone() const
{
	return new Plane(*this);
}

Plane::~Plane()
{
}

Plane & Plane::operator=(const Plane & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	GeometricObject::operator= (rhs);
	a = rhs.a;
	n = rhs.n;
	return *this;
}

bool Plane::hit(const Ray & ray, double & tmin, Tracer & tr) const
{
	float t = (a - ray.o) * n / (ray.d * n);
	if (t > kEpsilon) 
	{
		tmin = t;
		tr.normal = n;
		tr.hitPoint = ray.o + t * ray.d;
		return true;
	}

	return false;
}

//plane is infinite
//so there is almost no use in trying to
//calculate a bounding volume for it

Point3D Plane::maxBoundCoords() const
{
	return Point3D(250, 250, 100);
	//hardwired in
	//based upon the screen resolution
	//and the pixel ray's origin along the z-axis
}

Point3D Plane::minBoundCoords() const
{
	return Point3D(-250, -250, -100);
	//hardwired in
	//based upon the screen resolution
	//and the pixel ray's origin along the z-axis
}
