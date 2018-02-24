// 2017-18 Samuel Mounter
// All rights reserved

#include "Lighting.h"

Lighting::Lighting() : intensity(1.0f), colour(white)
{
}

Lighting::Lighting(RGBColour & _c, double intense) : intensity(intense), colour(_c)
{
}

Lighting::Lighting(double _r, double _g, double _b, double intense) : colour(_r, _g, _b), intensity(intense)
{
}

Lighting::~Lighting()
{
}