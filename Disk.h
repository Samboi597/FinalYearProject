#pragma once
#include "GeometricObject.h"

class Disk : public GeometricObject
{
private:
	Point3D center;
	Normal n;
	double radius;
	double radiusSquared;

public:
	Disk();
	Disk(const Point3D& _p, const Normal& _n, double _r);
	Disk(const Disk& disk);
	virtual ~Disk();

	virtual Disk* clone() const;
	void setRadius(const double r);
	virtual bool hit(const Ray& ray, double& tmin, Tracer& tr) const;
	Disk& operator=(const Disk& rightSide);
};

inline void Disk::setRadius(const double r)
{
	radius = r;
	radiusSquared = radius * radius;
}