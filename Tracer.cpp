// 2017-18 Samuel Mounter
// All rights reserved

#include "Tracer.h"

Tracer::Tracer() : hitObject(false), hitPoint(), normal(), pixelColour(black)
{
}

Tracer::Tracer(const Tracer & _tracer) : hitObject(_tracer.hitObject), hitPoint(_tracer.hitPoint), 
normal(_tracer.normal), pixelColour(_tracer.pixelColour)
{
}

Tracer::~Tracer()
{
}
