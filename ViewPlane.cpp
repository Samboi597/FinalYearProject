#include "ViewPlane.h"

ViewPlane::ViewPlane() : hres(400), vres(400), s(1.0), gamma(1.0), invGamma(1.0), ifOutOfGamut(false)
{
}

ViewPlane::ViewPlane(const ViewPlane & vp) : hres(vp.hres), vres(vp.vres), s(vp.s), gamma(vp.gamma), invGamma(vp.invGamma), 
ifOutOfGamut(vp.ifOutOfGamut)
{
}

ViewPlane::~ViewPlane()
{
}

ViewPlane & ViewPlane::operator=(const ViewPlane & rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}

	hres = rhs.hres;
	vres = rhs.vres;
	s = rhs.s;
	gamma = rhs.gamma;
	invGamma = rhs.invGamma;
	ifOutOfGamut = rhs.ifOutOfGamut;
	return (*this);
}
