// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "RGBColour.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "Constants.h"
#include "ShadingInfo.h"
#include "Tracer.h"

class GeometricObject
{
protected:
	GeometricObject& operator= (const GeometricObject& rhs);
public:
	GeometricObject();
	GeometricObject(const GeometricObject& object);
	virtual GeometricObject* clone() const = 0;
	virtual ~GeometricObject();
	ShadingInfo* shader;

	virtual Point3D maxBoundCoords() const = 0;
	virtual Point3D minBoundCoords() const = 0;
	virtual bool hit(const Ray& ray, double& t, Tracer& tr) const = 0;
};
