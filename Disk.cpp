#include "Disk.h"

Disk::Disk() : GeometricObject(), center(0.0), n(0.0, 1.0, 0.0), radius(1.0), radiusSquared(1.0)
{
}

Disk::Disk(const Point3D & _p, const Normal & _n, double _r) : GeometricObject(), center(_p), n(_n), radius(_r), radiusSquared(_r * _r)
{
	n.normalise();
}

Disk::Disk(const Disk & disk) : GeometricObject(disk), center(disk.center), n(disk.n), radius(disk.radius), radiusSquared(disk.radiusSquared)
{
}

Disk::~Disk()
{
}

Disk * Disk::clone() const
{
	return new Disk(*this);
}

bool Disk::hit(const Ray & ray, double & tmin, Tracer & tr) const
{
	float t = (center - ray.o) * n / (ray.d * n); //test plane on which the disk lies
	if (t > kEpsilon) //if there is an intersection
	{
		Point3D point = ray.o + t * ray.d;
		Vector3D v = point - center;
		if (v * v <= radiusSquared)
		{
			tmin = t;
			tr.normal = n;
			tr.hitPoint = point;
			return true;
		}

		return false;
	}

	return false;
}

Disk & Disk::operator=(const Disk & rightSide)
{
	if (this == &rightSide)
	{
		return *this;
	}

	GeometricObject::operator=(rightSide);
	center = rightSide.center;
	radius = rightSide.radius;
	radiusSquared = rightSide.radiusSquared;
	n = rightSide.n;
	return *this;
}