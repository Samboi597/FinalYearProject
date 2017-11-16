#include <math.h>
#include "Vector3D.h"
#include "Normal.h"
#include "Point3D.h"

Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) //default constructor
{
}

Vector3D::Vector3D(double a) : x(a), y(a), z(a)
{
}

Vector3D::Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

Vector3D::Vector3D(const Vector3D & v) : x(v.x), y(v.y), z(v.z)
{
}

Vector3D::Vector3D(const Normal & n) : x(n.x), y(n.y), z(n.z)
{
}

Vector3D::Vector3D(const Point3D & p) : x(p.x), y(p.y), z(p.z)
{
}

Vector3D::~Vector3D() //destructor
{
}

Vector3D& Vector3D::operator= (const Vector3D& rhs) //assignment operator
{
	if (this == &rhs)
	{
		return (*this);
	}

	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Vector3D& Vector3D::operator= (const Normal& rhs) //assign normal to vector
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Vector3D& Vector3D::operator= (const Point3D& rhs) //assign point to vector
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

double Vector3D::length(void) //vector length
{
	return (sqrt(x * x + y * y + z * z));
}

void Vector3D::normalise(void) //converts to unit vector
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}

Vector3D& Vector3D::hat(void) //converts to unit vector and returns it
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

Vector3D operator* (const Matrix& mat, const Vector3D& v) //multiplication by matrix on left
{
	return (Point3D(mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z,
		mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z,
		mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z));
}