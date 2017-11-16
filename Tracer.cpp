#include "Tracer.h"

Tracer::Tracer() : worldPtr(NULL)
{
}

Tracer::Tracer(World * _world_ptr) : worldPtr(_world_ptr)
{
}

Tracer::~Tracer()
{
	if (worldPtr)
		worldPtr = NULL;
}

RGBColour Tracer::traceRay(const Ray & ray) const
{
	return black;
}

RGBColour Tracer::traceRay(const Ray ray, const int depth) const
{
	return black;
}
