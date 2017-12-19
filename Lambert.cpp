#include "Lambert.h"

Lambert::Lambert() : ShadingInfo()
{
}

Lambert::Lambert(float r, float g, float b, double reflect) : ShadingInfo(r, g, b, reflect)
{
}

Lambert::Lambert(const Lambert & shade) : ShadingInfo(shade.colour, shade.albedo)
{
}

Lambert::Lambert(const RGBColour & _colour, double reflect) : ShadingInfo(_colour, reflect)
{
}

Lambert::~Lambert()
{
}

RGBColour Lambert::getReflectedColour(Tracer & t) const
{
	return colour * albedo;
}
