#pragma once
#include "RGBColour.h"
#include "Tracer.h"

class ShadingInfo
{
protected:
	RGBColour colour;
	double albedo;

public:
	ShadingInfo();
	ShadingInfo(float r, float g, float b, double reflect);
	ShadingInfo(const ShadingInfo& shade);
	ShadingInfo(const RGBColour& _colour, double reflect);
	~ShadingInfo();

	void setColour(const RGBColour& c);
	void setColour(float r, float g, float b);
	RGBColour getColour();
	void setAlbedo(double a);
	double getAlbedo();
	virtual RGBColour getReflectedColour(Tracer& t) const = 0;
};

inline void ShadingInfo::setColour(const RGBColour& c)
{
	colour = c;
}

inline void ShadingInfo::setColour(float r, float g, float b)
{
	colour.r = r;
	colour.g = g;
	colour.b = b;
}

inline RGBColour ShadingInfo::getColour()
{
	return colour;
}

inline void ShadingInfo::setAlbedo(double a)
{
	albedo = a;
}

inline double ShadingInfo::getAlbedo()
{
	return albedo;
}