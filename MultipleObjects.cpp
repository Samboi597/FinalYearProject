#include "MultipleObjects.h"
#include "World.h"

MultipleObjects::MultipleObjects() : Tracer()
{
}

MultipleObjects::MultipleObjects(World * _world_ptr) : Tracer(_world_ptr)
{
}

MultipleObjects::~MultipleObjects()
{
}

RGBColour MultipleObjects::traceRay(const Ray & ray) const
{
	ShadeRec sr(worldPtr->hitBareBonesObjects(ray)); // sr is copy constructed

	if (sr.hitObject)
		return (sr.colour);
	else
		return (worldPtr->backgroundColor);
}
