// 2017-18 Samuel Mounter
// All rights reserved

#include <math.h>
#include "Normal.h"

Normal::Normal() : x(0.0), y(0.0), z(0.0) // default constructor
{
}

Normal::Normal(double a) : x(a), y(a), z(a)
{
}

Normal::Normal(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

Normal::Normal(const Normal & n) : x(n.x), y(n.y), z(n.z) //copy constructor
{
}

Normal::Normal(const Vector3D & v) : x(v.x), y(v.y), z(v.z) //construct a normal from a vector
{
}

Normal::~Normal() //destructor
{
}

Normal & Normal::operator=(const Normal & rhs) //assignment operator
{
	if (this == &rhs)
	{
		return *this;
	}

	x = rhs.x; y = rhs.y; z = rhs.z;
	return *this;
}

Normal & Normal::operator=(const Vector3D & rhs) //assignment of vector to normal
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return *this;
}

Normal & Normal::operator=(const Point3D & rhs) //assignment of point to normal
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return *this;
}

void Normal::normalise() //convert vector length to 1
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}

Normal operator* (const Matrix& mat, const Normal& n) //multiplication by matrix on left
{
	return Normal(mat.m[0][0] * n.x + mat.m[1][0] * n.y + mat.m[2][0] * n.z,
		mat.m[0][1] * n.x + mat.m[1][1] * n.y + mat.m[2][1] * n.z,
		mat.m[0][2] * n.x + mat.m[1][2] * n.y + mat.m[2][2] * n.z);
}
