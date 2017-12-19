#pragma once
#include "GeometricObject.h"
#include "Tracer.h"

class Sphere : public GeometricObject
{
private:
	Point3D center;
	double radius;
	static const double kEpsilon; //for shadows and secondary rays
public:
	Sphere();
	Sphere(Point3D c, double r);
	Sphere(const Sphere& sphere);
	virtual Sphere* clone() const;
	virtual ~Sphere();
	Sphere& operator= (const Sphere& sphere);
	void setCenter(const Point3D& c);
	void setCenter(const double x, const double y, const double z);
	void setRadius(const double r);
	virtual bool hit(const Ray& ray, double& tmin, Tracer& tr) const;
};

inline void Sphere::setCenter(const Point3D& c) 
{
	center = c;
}

inline void Sphere::setCenter(const double x, const double y, const double z) 
{
	center.x = x;
	center.y = y;
	center.z = z;
}

inline void Sphere::setRadius(const double r) 
{
	radius = r;
}