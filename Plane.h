#pragma once
#include "GeometricObject.h"

class Plane : public GeometricObject
{
private:
	Point3D a;
	Normal n;
	static const double kEpsilon;
public:
	Plane();
	Plane(const Point3D& point, const Normal& normal);
	Plane(const Plane& plane);
	virtual Plane* clone() const;
	virtual ~Plane();

	Plane& operator= (const Plane& rhs);
	virtual bool hit(const Ray& ray, double& tmin, Tracer& tr) const;
};

