#include "Sphere.h"
#include "math.h"
#include <stdio.h>
const double Sphere::kEpsilon = 0.001;

Sphere::Sphere() : GeometricObject(), center(0.0), radius(1.0) //default constructor
{
}

Sphere::Sphere(Point3D c, double r) : GeometricObject(), center(c), radius(r)
{
}

Sphere::Sphere(const Sphere & sphere) : GeometricObject(sphere), center(sphere.center), radius(sphere.radius)
{
}

Sphere * Sphere::clone() const
{
	return new Sphere(*this);
}

Sphere::~Sphere() //destructor
{
}

Sphere & Sphere::operator=(const Sphere & sphere) //assignment operator
{
	if (this == &sphere)
	{
		return *this;
	}

	GeometricObject::operator=(sphere);
	center = sphere.center;
	radius = sphere.radius;
	return *this;
}

bool Sphere::hit(const Ray & ray, double & tmin, Tracer & tr) const
{
	double t;
	Vector3D temp = ray.o - center;
	double a = ray.d * ray.d;
	double b = 2.0 * temp * ray.d;
	double c = temp * temp - radius * radius;
	double disc = b * b - 4.0 * a * c;

	if (disc < 0.0)
	{
		return false;
	}
	else 
	{
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;    // smaller root

		if (t > kEpsilon) 
		{
			tmin = t;
			tr.normal = (temp + t * ray.d) / radius;
			tr.hitPoint = ray.o + t * ray.d;
			return true;
		}

		t = (-b + e) / denom;    // larger root
		if (t > kEpsilon) 
		{
			tmin = t;
			tr.normal = (temp + t * ray.d) / radius;
			tr.hitPoint = ray.o + t * ray.d;
			return true;
		}
	}
	return false;
}
