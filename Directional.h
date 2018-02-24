// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "Lighting.h"

class Directional :	public Lighting
{
private:
	Vector3D direction;

public:
	Directional();
	Directional(RGBColour& _c, double intense, Vector3D& d);
	Directional(double _r, double _g, double _b, double intense, Vector3D& d);
	virtual ~Directional();

	virtual Directional* clone() const;
	void setDirection(const Vector3D& d);
	void setDirection(double _x, double _y, double _z);
	virtual RGBColour getLightInfo(Tracer& tracer);
};

inline void Directional::setDirection(const Vector3D& d)
{
	direction = d;
}

inline void Directional::setDirection(double _x, double _y, double _z)
{
	direction.x = _x;
	direction.y = _y;
	direction.z = _z;
}