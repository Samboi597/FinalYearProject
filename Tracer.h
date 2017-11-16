#pragma once
class World;
#include "Constants.h"
#include "Ray.h"
#include "RGBColour.h"

class Tracer
{
protected:
	World* worldPtr;
public:
	Tracer();
	Tracer(World* _world_ptr);
	virtual ~Tracer();

	virtual RGBColour traceRay(const Ray& ray) const;
	virtual RGBColour traceRay(const Ray ray, const int depth) const;
};

