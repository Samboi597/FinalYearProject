#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Ray
{
public:
	Ray();
	Ray(const Point3D& origin, const Vector3D& dir);
	Ray(const Ray& ray);
	~Ray();

	Point3D o; //origin
	Vector3D d; //direction
	Ray& operator= (const Ray& rhs);
};

