// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "Point3D.h"
#include "Normal.h"
#include "Polygon.h"
#include <vector>
using namespace std;

class ObjLoader
{
private:
	char name[20];
	vector<Point3D*> vertices;
	vector<Normal*> normals;

	int numVert;
	int numPoly;
	int numNorm;
	int scaleValue;

public:
	ObjLoader();
	ObjLoader(char* filename);
	~ObjLoader();

	vector<Polygon*> polygons;

	int loadObj(char* filename);
	int printInfo();
};