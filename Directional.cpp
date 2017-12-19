#include "Directional.h"

Directional::Directional() : Lighting(), direction(0.0f, 1.0f, 0.0f)
{
}

Directional::Directional(RGBColour & _c, double intense, Vector3D & d) : Lighting(_c, intense), direction(d)
{
}

Directional::Directional(double _r, double _g, double _b, double intense, Vector3D & d) : Lighting(_r, _g, _b, intense), direction(d)
{
}

Directional::~Directional()
{
}

Directional * Directional::clone() const
{
	return new Directional(*this);
}

RGBColour Directional::getLightInfo(Tracer & tracer)
{
	if (direction.lengthSquared() - 1.0f > 0.1f || direction.lengthSquared() + 1.0f < -0.1f) //if light direction hasn't been normalised
	{
		direction.normalise();
	}
	
	double dotProduct = tracer.normal*(-direction);
	if (dotProduct > 0.0f)
	{
		return colour * (intensity * dotProduct);
	}
	else
	{
		return black;
	}
}
