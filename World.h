// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include <vector>
#include "GraphicsWindow.h"
#include "Lighting.h"
#include "RGBColour.h"
#include "Tracer.h"
#include "Ray.h"
#include "GeometricObject.h"
#include "AccelerationStructure.h"
using namespace std;

class World
{
private:
	void deleteObjects();
	void deleteLights();
public:
	World();
	~World();

	vector<GeometricObject*> objects;
	vector<Lighting*> lights;
	RGBColour backgroundColour;
	AccelerationStructure bvh;

	void addObject(GeometricObject* objectPtr);
	void addLight(Lighting* lightPtr);
	void build();
	RGBColour objCollision(const Ray& ray);
};

inline void World::addObject(GeometricObject * objectPtr)
{
	objects.push_back(objectPtr);
}

inline void World::addLight(Lighting* lightPtr)
{
	lights.push_back(lightPtr);
}

