#pragma once
#include "Tracer.h"

class MultipleObjects : public Tracer
{
public:
	MultipleObjects();
	MultipleObjects(World* _world_ptr);
	virtual ~MultipleObjects();

	virtual RGBColour traceRay(const Ray& ray) const;
};

