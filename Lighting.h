#pragma once
#include "RGBColour.h"
#include "Tracer.h"

class Lighting
{
protected:
	double intensity;
	RGBColour colour;

public:
	Lighting();
	Lighting(RGBColour& _c, double intense);
	Lighting(double _r, double _g, double _b, double intense);
	virtual ~Lighting();

	virtual Lighting* clone() const = 0;
	void setColour(RGBColour& _c);
	void setColour(double _r, double _g, double _b);
	void setIntensity(double intense);
	virtual RGBColour getLightInfo(Tracer& tracer) = 0;
};

inline void Lighting::setColour(RGBColour& _c)
{
	colour = _c;
}

inline void Lighting::setColour(double _r, double _g, double _b)
{
	colour.r = _r;
	colour.g = _g;
	colour.b = _b;
}

inline void Lighting::setIntensity(double intense)
{
	intensity = intense;
}