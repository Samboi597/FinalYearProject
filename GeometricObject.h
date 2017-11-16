#pragma once
#include "RGBColour.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"

class GeometricObject
{
protected:
	RGBColour colour;
	GeometricObject& operator= (const GeometricObject& rhs);
public:
	GeometricObject();
	GeometricObject(const GeometricObject& object);
	virtual GeometricObject* clone() const = 0;
	virtual ~GeometricObject();

	virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const = 0;
	void setColour(const RGBColour& c);
	void setColour(const float r, const float g, const float b);
	RGBColour getColour();
};

inline void GeometricObject::setColour(const RGBColour& c) 
{
	colour = c;
}

inline void GeometricObject::setColour(const float r, const float g, const float b) 
{
	colour.r = r;
	colour.b = b;
	colour.g = g;
}

inline RGBColour GeometricObject::getColour(void) {
	return (colour);
}
