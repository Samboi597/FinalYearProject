#include "Constants.h"
#include "GeometricObject.h"

GeometricObject::GeometricObject() : colour(black) //default constructor
{
}

GeometricObject::GeometricObject(const GeometricObject& object) : colour(object.colour)
{
}

GeometricObject& GeometricObject::operator= (const GeometricObject& rhs) 
{
	if (this == &rhs)
	{
		return (*this);
	}

	colour = rhs.colour;
	return (*this);
}

GeometricObject::~GeometricObject() //destructor
{
}
