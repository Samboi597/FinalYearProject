#include "ShadingInfo.h"

ShadingInfo::ShadingInfo() : colour(0.0, 0.0, 0.0), albedo(0.18)
{
}

ShadingInfo::ShadingInfo(float r, float g, float b, double reflect) : colour(r, g, b), albedo(reflect)
{
}

ShadingInfo::ShadingInfo(const ShadingInfo & shade) : colour(shade.colour), albedo(shade.albedo)
{
}

ShadingInfo::ShadingInfo(const RGBColour & _colour, double reflect) : colour(_colour), albedo(reflect)
{
}

ShadingInfo::~ShadingInfo()
{
}