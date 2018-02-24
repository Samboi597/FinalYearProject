// 2017-18 Samuel Mounter
// All rights reserved

#include "AccelerationStructure.h"

AccelerationStructure::AccelerationStructure() : root(NULL), totalCol(0), successCol(0)
{
}

AccelerationStructure::AccelerationStructure(vector<GeometricObject*>& objects) : root(NULL), totalCol(0), successCol(0)
{
	build(objects);
}

AccelerationStructure::~AccelerationStructure()
{
	if (root != NULL)
	{
		delete root;
		root = NULL;
	}
}

void AccelerationStructure::build(vector<GeometricObject*>& objects)
{
	root = new BoundingVolume(objects);
}

void AccelerationStructure::search(const Ray & ray)
{
	if (root != NULL)
	{
		tr.hitObject = false;
		tr.hitPoint = Point3D(0.0);
		tr.normal = Normal(0.0);
		tr.pixelColour = black;

		double t = 1000;
		root->traverse(ray, tr, t, totalCol, successCol);
	}
}
