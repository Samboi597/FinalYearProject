#pragma once
#include <vector>
#include "GraphicsWindow.h"
#include "RGBColour.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "Ray.h"
using namespace std;

class World
{
private:
	void deleteObjects();
public:
	World();
	~World();

	Sphere sphere; //delete this in a later iteration
	Tracer* tracerPtr;
	vector<GeometricObject*> objects;
	RGBColour backgroundColor;

	void addObject(GeometricObject* objectPtr);
	void build();
	ShadeRec hitBareBonesObjects(const Ray& ray);
};

inline void World::addObject(GeometricObject * objectPtr)
{
	objects.push_back(objectPtr);
}

