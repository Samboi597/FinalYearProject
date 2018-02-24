// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "Point3D.h"
#include "BoundingVolume.h"
#include "GeometricObject.h"
#include <vector>
using namespace std;

class BoundingVolume
{
private:
	Point3D maxCoord;
	Point3D minCoord;
	vector<GeometricObject*> localObjs;
	BoundingVolume* left;
	BoundingVolume* right;

	bool intersect(const Ray& ray);

public:
	BoundingVolume();
	BoundingVolume(vector<GeometricObject*>& objects);
	~BoundingVolume();

	void build(vector<GeometricObject*>& objects);
	void traverse(const Ray& ray, Tracer& tr, double& t, int& col, int& success);
	void testCollisions(const Ray& ray, Tracer& tr, double& t, int& col, int& success);
};