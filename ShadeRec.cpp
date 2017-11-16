#include "Constants.h"
#include "ShadeRec.h"

ShadeRec::ShadeRec(World & wr) : hitObject(false), localHitPoint(), normal(), colour(black), w(wr)
{
}

ShadeRec::ShadeRec(const ShadeRec & sr) : hitObject(sr.hitObject), localHitPoint(sr.localHitPoint), colour(sr.colour), w(sr.w)
{
}
