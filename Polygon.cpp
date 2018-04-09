// 2017-18 Samuel Mounter
// All rights reserved

#include "Polygon.h"
#include <math.h>

Polygon::Polygon()
{
	shader = new Lambert(1.0, 1.0, 1.0, 0.18);
}

Polygon::Polygon(Point3D one, Point3D two, Point3D three, Normal nOne, Normal nTwo, Normal nThree) 
	: GeometricObject(), p0(one), p1(two), p2(three), n0(nOne), n1(nTwo), n2(nThree)
{
	shader = new Lambert(1.0, 1.0, 1.0, 0.18);
}

Polygon::~Polygon()
{
}

bool Polygon::isInsidePoly(Point3D point, Normal _n) const
{
	Vector3D perp, edge, p;

	//edge 1
	edge = p1 - p0;
	p = point - p0;
	perp = edge^p;
	if ((_n*perp) < 0) return false; //outside triangle boundaries

	//edge 2
	edge = p2 - p1;
	p = point - p1;
	perp = edge^p;
	if ((_n*perp) < 0) return false; //outside triangle boundaries

	//edge 3
	edge = p0 - p2;
	p = point - p2;
	perp = edge^p;
	if ((_n*perp) < 0) return false; //outside triangle boundaries

	return true;
}

bool Polygon::hit(const Ray & ray, double & tmin, Tracer & tr) const
{
	//find a temporary planar normal
	//just to find the intersection point
	//between the ray and the plane

	Vector3D v1, v2;
	v1 = p1 - p0;
	v2 = p2 - p0;

	Normal n = v1^v2; //cross product
//	n.normalise();

	double dotProduct = n*(-ray.d);
	if (fabs(dotProduct) < 0.0001)
	{
		return false;
	}
	//if (dotProduct <= 0.0f) //if the angle between ray and normal is larger than 180
	//{
		//return false;
	//}

	double d = n*p0;
	double t = ((n*ray.o) - d) / dotProduct;
	if (t >= 0) //if polygon is within view
	{
		Point3D p = ray.o + t*(ray.d);

		if (isInsidePoly(p, n))
		{
			float u, v;
			u = n*((p2 - p1)^(p - p1));
			v = n*((p0 - p2)^(p - p2));

			float nSquared = (n.x*n.x) + (n.y*n.y) + (n.z*n.z);
			u /= nSquared;
			v /= nSquared;

			//interpolate normal
			n = (u * n0) + (v * n1) + ((1 - u - v) * n2);
			n.normalise();

			tr.hitObject = true;
			tr.hitPoint = p;
			tr.normal = n;
			tmin = t;

			return true;
		}
	}

	return false;
}

Point3D Polygon::maxBoundCoords() const
{
	double maxX = -100000.0, maxY = -100000.0, maxZ = -100000.0;

	if (p0.x > maxX) maxX = p0.x;
	if (p0.y > maxY) maxY = p0.y;
	if (p0.z > maxZ) maxZ = p0.z;

	if (p1.x > maxX) maxX = p1.x;
	if (p1.y > maxY) maxY = p1.y;
	if (p1.z > maxZ) maxZ = p1.z;

	if (p2.x > maxX) maxX = p2.x;
	if (p2.y > maxY) maxY = p2.y;
	if (p2.z > maxZ) maxZ = p2.z;

	return Point3D(maxX, maxY, maxZ);
}

Point3D Polygon::minBoundCoords() const
{
	double minX = 100000.0, minY = 100000.0, minZ = 100000.0;

	if (p0.x < minX) minX = p0.x;
	if (p0.y < minY) minY = p0.y;
	if (p0.z < minZ) minZ = p0.z;

	if (p1.x < minX) minX = p1.x;
	if (p1.y < minY) minY = p1.y;
	if (p1.z < minZ) minZ = p1.z;

	if (p2.x < minX) minX = p2.x;
	if (p2.y < minY) minY = p2.y;
	if (p2.z < minZ) minZ = p2.z;

	return Point3D(minX, minY, minZ);
}
