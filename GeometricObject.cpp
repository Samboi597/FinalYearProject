// 2017-18 Samuel Mounter
// All rights reserved

#include "Constants.h"
#include "GeometricObject.h"
#include <stdio.h>

GeometricObject::GeometricObject() : shader(NULL) //default constructor
{
}

GeometricObject::GeometricObject(const GeometricObject& object) : shader(object.shader)
{
}

GeometricObject& GeometricObject::operator= (const GeometricObject& rhs) 
{
	if (this == &rhs)
	{
		return *this;
	}

	shader = rhs.shader;
	return *this;
}

GeometricObject::~GeometricObject() //destructor
{
	if (shader != NULL)
	{
		delete shader;
		shader = NULL;
	}
}
