#pragma once
class World;
#include "Point3D.h"
#include "Normal.h"
#include "RGBColour.h"

class ShadeRec
{
public:
	ShadeRec(World& wr);
	ShadeRec(const ShadeRec& sr);

	bool hitObject;
	Point3D localHitPoint;
	Normal normal;
	RGBColour colour;
	World &w;
};

