#include <math.h>
#include "RGBColour.h"

RGBColour::RGBColour() : r(0.0), g(0.0), b(0.0) //default constructor
{
}

RGBColour::RGBColour(float c) : r(c), g(c), b(c)
{
}

RGBColour::RGBColour(float _r, float _g, float _b) : r(_r), g(_g), b(_b)
{
}

RGBColour::RGBColour(const RGBColour & c) : r(c.r), g(c.g), b(c.b)
{
}

RGBColour::~RGBColour() //destructor
{
}

RGBColour& RGBColour::operator= (const RGBColour& rhs) //assignment operator
{
	if (this == &rhs)
	{
		return (*this);
	}

	r = rhs.r; g = rhs.g; b = rhs.b;
	return (*this);
}

RGBColour RGBColour::powc(double p) const //raise to specified power
{
	return (RGBColour(pow(r, p), pow(g, p), pow(b, p)));
}