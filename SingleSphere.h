#pragma once
#include "Tracer.h"

class SingleSphere : public Tracer
{
public:
	SingleSphere();
	SingleSphere(World* _worldPtr);
	~SingleSphere();

	virtual RGBColour traceRay(const Ray& ray) const;
};

