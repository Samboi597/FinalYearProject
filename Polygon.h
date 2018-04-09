// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "GeometricObject.h"
#include "Lambert.h"

class Polygon : public GeometricObject
{
private:
	Point3D p0, p1, p2;
	Normal n0, n1, n2;

	bool isInsidePoly(Point3D point, Normal _n) const;
	virtual Polygon* clone() const { return new Polygon(*this); } //no need to clone a polygon

public:
	Polygon();
	Polygon(Point3D, Point3D, Point3D, Normal, Normal, Normal);
	virtual ~Polygon();

	virtual bool hit(const Ray& ray, double& tmin, Tracer& tr) const;
	virtual Point3D maxBoundCoords() const;
	virtual Point3D minBoundCoords() const;
};