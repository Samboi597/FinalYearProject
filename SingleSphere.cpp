#include "SingleSphere.h"
#include "World.h"
#include "ShadeRec.h"

SingleSphere::SingleSphere() : Tracer()
{
}

SingleSphere::SingleSphere(World * _worldPtr) : Tracer(_worldPtr)
{
}

SingleSphere::~SingleSphere()
{
}

RGBColour SingleSphere::traceRay(const Ray & ray) const
{
	ShadeRec sr(*worldPtr); 	
	double t;  				

	if (worldPtr->sphere.hit(ray, t, sr))
		return (red);
	else
		return (black);
}
