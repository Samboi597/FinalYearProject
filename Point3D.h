// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "Matrix.h"
#include "Vector3D.h"

class Point3D
{
public:
	Point3D();
	Point3D(const double a);
	Point3D(const double a, const double b, const double c);
	Point3D(const Point3D& p);
	~Point3D();

	double x, y, z;
	Point3D& operator= (const Point3D& p);
	Point3D operator- () const;
	Vector3D operator- (const Point3D& p) const;
	Point3D operator+ (const Vector3D& v) const;
	Point3D operator- (const Vector3D& v) const;
	Point3D operator* (const double a) const;
	double dSquared(const Point3D& p) const;
	double distance(const Point3D& p) const;
};

inline Point3D Point3D::operator- (void) const //minus point
{
	return Point3D(-x, -y, -z);
}

inline Vector3D Point3D::operator- (const Point3D& p) const //vector between two points
{
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

inline Point3D Point3D::operator+ (const Vector3D& v) const //addition of vector and point
{
	return Point3D(x + v.x, y + v.y, z + v.z);
}

inline Point3D Point3D::operator- (const Vector3D& v) const //subtraction of vector from point
{
	return Point3D(x - v.x, y - v.y, z - v.z);
}

inline Point3D Point3D::operator* (const double a) const //multiplication by double on right
{
	return Point3D(x * a, y * a, z * a);
}

inline double Point3D::dSquared(const Point3D& p) const //squared distance between two points
{
	return ((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
}

Point3D operator* (double a, const Point3D& p);

inline Point3D operator* (double a, const Point3D& p) //multiplication by double on left
{
	return Point3D(a * p.x, a * p.y, a * p.z);
}

Point3D operator* (const Matrix& mat, const Point3D& p);