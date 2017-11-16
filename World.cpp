//include opengl page

#include "World.h"
#include "Constants.h"

// geometric objects

#include "Plane.h"
#include "Sphere.h"

// tracers

#include "SingleSphere.h"
#include "MultipleObjects.h"

// utilities

#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include "Maths.h"

World::World() : backgroundColor(black), tracerPtr(NULL)
{
}

World::~World()
{
	if (tracerPtr) 
	{
		delete tracerPtr;
		tracerPtr = NULL;
	}

	deleteObjects();
}

void World::build()
{
	/*
	backgroundColor = RGBColour(0.0);
	tracerPtr = new MultipleObjects(this);

	// colours

	RGBColour yellow(1, 1, 0);										// yellow
	RGBColour brown(0.71, 0.40, 0.16);								// brown
	RGBColour darkGreen(0.0, 0.41, 0.41);							// dark_green
	RGBColour orange(1, 0.75, 0);									// orange
	RGBColour green(0, 0.6, 0.3);									// green
	RGBColour lightGreen(0.65, 1, 0.30);							// light green
	RGBColour darkYellow(0.61, 0.61, 0);							// dark yellow
	RGBColour lightPurple(0.65, 0.3, 1);							// light purple
	RGBColour darkPurple(0.5, 0, 1);								// dark purple

																	// spheres

	Sphere*	spherePtr1 = new Sphere(Point3D(-250, -250, 0), 250);
	spherePtr1->setColour(1.0, 0, 0);	   								// yellow
	addObject(spherePtr1);

	Sphere* spherePtr2 = new Sphere(Point3D(250, 250, 0), 250);
	spherePtr2->setColour(0.0, 1.0, 0.0);
	addObject(spherePtr2);*/

	backgroundColor = RGBColour(0.0);
	tracerPtr = new SingleSphere(this);

	sphere.setCenter(0.0);
	sphere.setRadius(200);
}

ShadeRec World::hitBareBonesObjects(const Ray & ray)
{
	ShadeRec sr(*this);
	double t;
	float tmin = kHugeValue;
	int numObjects = objects.size();

	for (int j = 0; j < numObjects; j++)
	{
		if (objects[j]->hit(ray, t, sr) && (t < tmin))
		{
			sr.hitObject = true;
			tmin = t;
			sr.colour = objects[j]->getColour();
		}
	}
	return sr;
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
