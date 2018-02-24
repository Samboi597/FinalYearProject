// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "Constants.h"
#include "Ray.h"
#include "RGBColour.h"
#include "Normal.h"

class Tracer
{
public:
	Tracer();
	Tracer(const Tracer& _tracer);
	~Tracer();

	bool hitObject;
	RGBColour pixelColour;
	Point3D hitPoint;
	Normal normal;
};

