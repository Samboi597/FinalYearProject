// 2017-18 Samuel Mounter
// All rights reserved

#include "BoundingVolume.h"
#include "Maths.h"

bool BoundingVolume::intersect(const Ray & ray) //test for an intersection between the ray and the bounding volume
{
	float tXmin = (minCoord.x - ray.o.x) / ray.d.x;
	float tXmax = (maxCoord.x - ray.o.x) / ray.d.x;

	float tYmin = (minCoord.y - ray.o.y) / ray.d.y;
	float tYmax = (maxCoord.y - ray.o.y) / ray.d.y;

	if (tXmin > tYmax || tYmin > tXmax) return false;

	float tmin;
	if (tXmin > tYmin)
		tmin = tXmin;
	else
		tmin = tYmin;

	float tmax;
	if (tXmax < tYmax)
		tmax = tXmax;
	else
		tmax = tYmax;

	float tZmin = (minCoord.z - ray.o.z) / ray.d.z;
	float tZmax = (maxCoord.z - ray.o.z) / ray.d.z;

	if (tmin > tZmax || tZmin > tmax) return false;

	if (tZmin > tmin) tmin = tZmin;
	if (tZmax < tmax) tmax = tZmax;
	return true;
}

BoundingVolume::BoundingVolume() : maxCoord(Point3D(0.0, 0.0, 0.0)), minCoord(Point3D(0.0, 0.0, 0.0)), left(NULL), right(NULL)
{
}

BoundingVolume::BoundingVolume(vector<GeometricObject*>& objects) : maxCoord(Point3D(0.0, 0.0, 0.0)), minCoord(Point3D(0.0, 0.0, 0.0)), 
left(NULL), right(NULL)
{
	build(objects);
}

BoundingVolume::~BoundingVolume()
{
	if (left == NULL && right == NULL)
	{
		int size = localObjs.size();
		for (int i = 0; i < size; i++)
		{
			delete localObjs[i];
			localObjs[i] = NULL;
		}
		localObjs.erase(localObjs.begin(), localObjs.end());
	}

	if (left != NULL)
	{
		delete left;
		left = NULL;
	}

	if (right != NULL)
	{
		delete right;
		right = NULL;
	}
}

void BoundingVolume::build(vector<GeometricObject*>& objects)
{
	for (int i = 0; i < objects.size(); i++)
	{
		//(250, 250, 100) is based upon the current dimention of the screen
		//i might want to consider making this more flexible in the future

		if (objects[i]->maxBoundCoords().x > maxCoord.x)	maxCoord.x = min(250, objects[i]->maxBoundCoords().x);
		if (objects[i]->maxBoundCoords().y > maxCoord.y)	maxCoord.y = min(250, objects[i]->maxBoundCoords().y);
		if (objects[i]->maxBoundCoords().z > maxCoord.z)	maxCoord.z = min(100, objects[i]->maxBoundCoords().z);

		if (objects[i]->minBoundCoords().x < minCoord.x)	minCoord.x = max(-250, objects[i]->minBoundCoords().x);
		if (objects[i]->minBoundCoords().y < minCoord.y)	minCoord.y = max(-250, objects[i]->minBoundCoords().y);
		if (objects[i]->minBoundCoords().z < minCoord.z)	minCoord.z = max(-100, objects[i]->minBoundCoords().z);
	}
	
	if (objects.size() > 2)
	{
		int xDiff = abs(maxCoord.x - minCoord.x), yDiff = abs(maxCoord.y - minCoord.y), zDiff = abs(maxCoord.z - minCoord.z);
		int size = objects.size();
		int indexSmall;

		if (xDiff >= yDiff && xDiff >= zDiff)
		{
			//add objects to localObjs in order of ascending x-position

			while (localObjs.size() < size)
			{
				indexSmall = 0;
				for (int i = 1; i < objects.size(); i++)
				{
					if (((objects[i]->maxBoundCoords().x + objects[i]->minBoundCoords().x) / 2) < 
						((objects[indexSmall]->maxBoundCoords().x + objects[indexSmall]->minBoundCoords().x) / 2)) indexSmall = i;
				}

				localObjs.push_back(objects[indexSmall]);
				objects.erase(objects.begin() + indexSmall);
			}
		}
		else if (yDiff >= zDiff)
		{
			//add objects to localObjs in order of ascending y-position

			while (localObjs.size() < size)
			{
				indexSmall = 0;
				for (int i = 1; i < objects.size(); i++)
				{
					if (((objects[i]->maxBoundCoords().y + objects[i]->minBoundCoords().y) / 2) <
						((objects[indexSmall]->maxBoundCoords().y + objects[indexSmall]->minBoundCoords().y) / 2)) indexSmall = i;
				}

				localObjs.push_back(objects[indexSmall]);
				objects.erase(objects.begin() + indexSmall);
			}
		}
		else
		{
			//add objects to localObjs in order of ascending z-position

			while (localObjs.size() < size)
			{
				indexSmall = 0;
				for (int i = 1; i < objects.size(); i++)
				{
					if (((objects[i]->maxBoundCoords().z + objects[i]->minBoundCoords().z) / 2) <
						((objects[indexSmall]->maxBoundCoords().z + objects[indexSmall]->minBoundCoords().z) / 2)) indexSmall = i;
				}

				localObjs.push_back(objects[indexSmall]);
				objects.erase(objects.begin() + indexSmall);
			}
		}		

		//use the positions of the objects in the scene
		//to find a splitting point
		//about half of the objects go into the left node
		//the other half to the right

		left = new BoundingVolume(vector<GeometricObject*>(localObjs.begin(), localObjs.begin() + (localObjs.size() / 2)));
		right = new BoundingVolume(vector<GeometricObject*>(localObjs.begin() + (localObjs.size() / 2), localObjs.end()));
	}
	else
	{
		//just add 'em to the bounding box

		int size = objects.size();
		for (int i = 0; i < size; i++)
		{
			localObjs.push_back(objects[0]);
			objects.erase(objects.begin());
		}
	}
}

void BoundingVolume::traverse(const Ray & ray, Tracer & tr, double& t, int& col, int& success)
{
	//col++;
	if (intersect(ray)) 
	{
		//success++;
		if (left == NULL && right == NULL) //if there are no child nodes
		{
			testCollisions(ray, tr, t, col, success);
		}
		else //if there are children
		{
			left->traverse(ray, tr, t, col, success);
			right->traverse(ray, tr, t, col, success);
		}
	}
}

void BoundingVolume::testCollisions(const Ray & ray, Tracer & tr, double& t, int& col, int& success)
{
	Tracer test = tr;
	double tmin;
	int numObjects = localObjs.size();
	for (int i = 0; i < numObjects; i++)
	{
		col++;
		if (localObjs[i]->hit(ray, tmin, test) && tmin < t)
		{
			success++;
			test.hitObject = true;
			t = tmin;
			test.pixelColour = localObjs[i]->shader->getReflectedColour(test);
			tr = test;
		}
	}
}
