// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "Matrix.h"
class Normal;
class Point3D;

class Vector3D
{
public:
	Vector3D();
	Vector3D(double a);
	Vector3D(double _x, double _y, double _z);
	Vector3D(const Vector3D& v);
	Vector3D(const Normal& n);
	Vector3D(const Point3D& p);
	~Vector3D();

	double x, y, z;
	Vector3D& operator= (const Vector3D& rhs);
	Vector3D& operator= (const Normal& rhs);
	Vector3D& operator= (const Point3D& rhs);
	Vector3D operator- () const;
	double length();
	double lengthSquared();
	Vector3D operator* (const double a) const;
	Vector3D operator/ (const double a) const;
	Vector3D operator+ (const Vector3D& v) const;
	Vector3D& operator+= (const Vector3D& v);
	Vector3D operator- (const Vector3D& v) const;
	double operator* (const Vector3D& b) const;
	Vector3D operator^ (const Vector3D& v) const;
	void normalise();
	Vector3D& hat();
};

inline Vector3D Vector3D::operator- (void) const //minus vector
{
	return Vector3D(-x, -y, -z);
}

inline double Vector3D::lengthSquared(void) //square of the length
{
	return (x * x + y * y + z * z);
}

inline Vector3D Vector3D::operator* (const double a) const //mulitplication by double on right
{
	return Vector3D(x * a, y * a, z * a);
}

inline Vector3D Vector3D::operator/ (const double a) const //division by a double
{
	return Vector3D(x / a, y / a, z / a);
}

inline Vector3D Vector3D::operator+ (const Vector3D& v) const //vector addition
{
	return Vector3D(x + v.x, y + v.y, z + v.z);
}

inline Vector3D Vector3D::operator- (const Vector3D& v) const //vector subtraction
{
	return Vector3D(x - v.x, y - v.y, z - v.z);
}

inline double Vector3D::operator* (const Vector3D& v) const //dot product
{
	return (x * v.x + y * v.y + z * v.z);
}

inline Vector3D Vector3D::operator^ (const Vector3D& v) const //cross product
{
	return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

inline Vector3D& Vector3D::operator+= (const Vector3D& v) //compund addition
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

Vector3D operator* (const double a, const Vector3D& v);

inline Vector3D operator* (const double a, const Vector3D& v) //mulitiplication by double oon left
{
	return Vector3D(a * v.x, a * v.y, a * v.z);
}

Vector3D operator* (const Matrix& mat, const Vector3D& v); //multiplication by matrix on left