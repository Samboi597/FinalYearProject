// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "BoundingVolume.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include <vector>
using namespace std;

class AccelerationStructure
{
public:
	AccelerationStructure();
	AccelerationStructure(vector<GeometricObject*>& objects);
	~AccelerationStructure();

	BoundingVolume* root;
	Tracer tr;
	int totalCol;
	int successCol;

	void build(vector<GeometricObject*>& objects);
	void search(const Ray& ray);
};