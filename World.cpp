// 2017-18 Samuel Mounter
// All rights reserved

//include opengl page

#include "World.h"
#include "Constants.h"

// geometric objects

#include "Plane.h"
#include "Sphere.h"
#include "Disk.h"

// tracer

#include "Tracer.h"

// lights

#include "Directional.h"

// utilities

#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Maths.h"
#include "Lambert.h"
#include <time.h>

World::World() : backgroundColour(black)
{
}

World::~World()
{
	printf("Total collisions: %d\n", bvh.totalCol);
	printf("Successful collisions: %d\n", bvh.successCol);
	deleteObjects();
	deleteLights();
}

void World::build()
{
	clock_t t = clock();
	backgroundColour = RGBColour(0.0);
	
	Sphere* sphere1 = new Sphere(Point3D(-150, 150, 0), 100);
	sphere1->shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	addObject(sphere1);
	
	Sphere* sphere2 = new Sphere(Point3D(0, 0, 0), 100);
	sphere2->shader = new Lambert(0.0, 1.0, 0.0, 0.18);
	addObject(sphere2);
	
	Sphere* sphere3 = new Sphere(Point3D(150, -150, 0), 100);
	sphere3->shader = new Lambert(0.0, 0.0, 1.0, 0.18);
	addObject(sphere3);
	
	Plane* plane = new Plane(Point3D(0.0, 0.0, -100.0), Normal(0.0, 0.0, 1.0));
	plane->shader = new Lambert(0.5, 0.5, 0.5, 0.18);
	addObject(plane);
	
	Disk* disk1 = new Disk(Point3D(150, 150, 0), Normal(1.0, -1.0, 1.0), 100);
	disk1->shader = new Lambert(1, 1, 0, 0.18);
	addObject(disk1);
	
	Disk* disk2 = new Disk(Point3D(-150, -150, 0), Normal(-1.0, 1.0, 1.0), 100);
	disk2->shader = new Lambert(1, 0, 1, 0.18);
	addObject(disk2);
	
	Directional* light = new Directional();
	light->setColour(1.0, 1.0, 1.0);
	light->setIntensity(6.0);
	light->setDirection(1.0, -1.0, -1.0);
	addLight(light);

	Directional* light2 = new Directional();
	light2->setColour(1.0, 1.0, 1.0);
	light2->setIntensity(6.0);
	light2->setDirection(-1.0, 1.0, -1.0);
	addLight(light2);

	bvh.build(objects);

	t = clock() - t;
	printf("Scene building time: %f ms\n", (float)(t));
}

RGBColour World::objCollision(const Ray & ray)
{
	Tracer tr;
	bvh.search(ray);
	tr = bvh.tr;

	RGBColour pixel = black;
	if (tr.hitObject)
	{
		int numLights = lights.size();
		for (int i = 0; i < numLights; i++)
		{
			pixel += (lights[i]->getLightInfo(tr) * tr.pixelColour);
		}
	}

	return pixel;
}

void World::deleteObjects()
{
	int numObjects = objects.size();
	for (int j = 0; j < numObjects; j++)
	{
		delete objects[j];
		objects[j] = NULL;
	}

	objects.erase(objects.begin(), objects.end());
}

void World::deleteLights()
{
	int numLights = lights.size();
	for (int j = 0; j < numLights; j++)
	{
		delete lights[j];
		lights[j] = NULL;
	}

	lights.erase(lights.begin(), lights.end());
}
