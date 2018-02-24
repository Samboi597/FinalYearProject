// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "ShadingInfo.h"

class Lambert : public ShadingInfo
{
public:
	Lambert();
	Lambert(float r, float g, float b, double reflect);
	Lambert(const Lambert& shade);
	Lambert(const RGBColour& _colour, double reflect);
	~Lambert();

	virtual RGBColour getReflectedColour(Tracer& t) const;
};