// ProjectTesting.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "gtest/gtest.h"
#include "Matrix.h"
#include "RGBColour.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "ShadeRec.h"
#include "World.h"
#include "Plane.h"
#include "SingleSphere.h"
#include "MultipleObjects.h"
#include "GraphicsWindow.h"

/*testing Matrix.h*/

TEST(matrixFunc, constructor)
{
	Matrix matrix;
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (matrix.m[i][i] > 0.9995 && matrix.m[i][i] < 1.0005)
		{
			count++;
		}
	}

	EXPECT_EQ(count, 4);
}

TEST(matrixFunc, copyConstructor)
{
	Matrix matrix;
	for (int i = 0; i < 4; i++)
	{
		matrix.m[i][i] = (double)(i + 1);
	}

	Matrix m2(matrix);
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (abs(m2.m[i][i] - matrix.m[i][i]) < 0.0005)
		{
			count++;
		}
	}

	EXPECT_EQ(count, 4);
}

TEST(matrixFunc, assignmentOperator)
{
	Matrix matrix;
	for (int i = 0; i < 4; i++)
	{
		matrix.m[i][i] = (double)(i + 1);
	}

	Matrix m2;
	m2.operator=(matrix);
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (abs(m2.m[i][i] - matrix.m[i][i]) < 0.0005)
		{
			count++;
		}
	}

	EXPECT_EQ(count, 4);
}

TEST(matrixFunc, multiOperator)
{
	Matrix matrix;
	for (int i = 0; i < 4; i++)
	{
		matrix.m[i][i] = 2.5f;
	}

	Matrix m2;
	matrix.operator*(m2);

	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (abs(matrix.m[i][i] - 2.5f) < 0.0005)
		{
			count++;
		}
	}

	EXPECT_EQ(count, 4);
}

TEST(matrixFunc, divideOperator)
{
	Matrix matrix;
	matrix.operator/(0.25f);

	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (abs(matrix.m[i][i] - 4.0f) < 0.0005)
		{
			count++;
		}
	}

	EXPECT_EQ(count, 4);
}

TEST(matrixFunc, identity)
{
	Matrix matrix;
	matrix.setIdentity();

	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (abs(matrix.m[i][i] - 1.0f) < 0.0005)
		{
			count++;
		}
	}

	EXPECT_EQ(count, 4);
}

/*testing RGBColour.h*/

TEST(colourFunc, constructor)
{
	RGBColour colour;

	int count = 0;
	if (abs(colour.r) < 0.0005)
		count++;
	if (abs(colour.g) < 0.0005)
		count++;
	if (abs(colour.b) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, singularConstructor)
{
	RGBColour colour(0.4f);

	int count = 0;
	if (abs(colour.r - 0.4f) < 0.0005)
		count++;
	if (abs(colour.g - 0.4f) < 0.0005)
		count++;
	if (abs(colour.b - 0.4f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, tripleConstructor)
{
	RGBColour colour(0.6f, 0.2f, 0.5f);

	int count = 0;
	if (abs(colour.r - 0.6f) < 0.0005)
		count++;
	if (abs(colour.g - 0.2f) < 0.0005)
		count++;
	if (abs(colour.b - 0.5f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, copyConstructor)
{
	RGBColour colour(0.6f, 0.2f, 0.5f);
	RGBColour c2(colour);

	int count = 0;
	if (abs(c2.r - 0.6f) < 0.0005)
		count++;
	if (abs(c2.g - 0.2f) < 0.0005)
		count++;
	if (abs(c2.b - 0.5f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, assignmentOperator)
{
	RGBColour colour(0.6f, 0.2f, 0.5f);
	RGBColour c2;

	c2.operator=(colour);
	int count = 0;
	if (abs(c2.r - 0.6f) < 0.0005)
		count++;
	if (abs(c2.g - 0.2f) < 0.0005)
		count++;
	if (abs(c2.b - 0.5f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, addOperator)
{
	RGBColour colour(0.2f, 0.4f, 0.1f);
	RGBColour c2(0.1f, 0.5f, 0.6f);

	RGBColour c3;
	c3 = c2 + colour;
	int count = 0;
	if (abs(c3.r - 0.3f) < 0.0005)
		count++;
	if (abs(c3.g - 0.9f) < 0.0005)
		count++;
	if (abs(c3.b - 0.7f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, compoundAdd)
{
	RGBColour colour(0.2f, 0.4f, 0.1f);
	RGBColour c2(0.1f, 0.5f, 0.6f);

	colour += c2;
	int count = 0;
	if (abs(colour.r - 0.3f) < 0.0005)
		count++;
	if (abs(colour.g - 0.9f) < 0.0005)
		count++;
	if (abs(colour.b - 0.7f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, multiOperator)
{
	RGBColour colour(1.0f, 1.0f, 1.0f);
	RGBColour c2 = colour * 0.2f;

	int count = 0;
	if (abs(c2.r - 0.2f) < 0.0005)
		count++;
	if (abs(c2.g - 0.2f) < 0.0005)
		count++;
	if (abs(c2.b - 0.2f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, compoundMulti)
{
	RGBColour colour(1.0f, 1.0f, 1.0f);
	colour *= 0.2f;

	int count = 0;
	if (abs(colour.r - 0.2f) < 0.0005)
		count++;
	if (abs(colour.g - 0.2f) < 0.0005)
		count++;
	if (abs(colour.b - 0.2f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, divideOperator)
{
	RGBColour colour(1.0f, 1.0f, 1.0f);
	RGBColour c2 = colour / 2.0f;

	int count = 0;
	if (abs(c2.r - 0.5f) < 0.0005)
		count++;
	if (abs(c2.g - 0.5f) < 0.0005)
		count++;
	if (abs(c2.b - 0.5f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, compoundDivide)
{
	RGBColour colour(1.0f, 1.0f, 1.0f);
	colour /= 2.0f;

	int count = 0;
	if (abs(colour.r - 0.5f) < 0.0005)
		count++;
	if (abs(colour.g - 0.5f) < 0.0005)
		count++;
	if (abs(colour.b - 0.5f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, componentMulti)
{
	RGBColour colour(0.2f, 0.4f, 0.1f);
	RGBColour c2(0.5f, 0.5f, 0.5f);

	RGBColour c3 = colour * c2;
	int count = 0;
	if (abs(c3.r - 0.1f) < 0.0005)
		count++;
	if (abs(c3.g - 0.2f) < 0.0005)
		count++;
	if (abs(c3.b - 0.05f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, equalOperator)
{
	RGBColour colour(0.2f, 0.4f, 0.1f);
	RGBColour c2(0.1f, 0.4f, 0.2f);

	bool answer = colour == c2;
	EXPECT_EQ(answer, false);
}

TEST(colourFunc, power)
{
	RGBColour colour(0.2f, 0.4f, 0.1f);
	RGBColour c2 = colour.powc(2.0f);

	int count = 0;
	if (abs(c2.r - 0.04f) < 0.0005)
		count++;
	if (abs(c2.g - 0.16f) < 0.0005)
		count++;
	if (abs(c2.b - 0.01f) < 0.0005)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(colourFunc, average)
{
	RGBColour colour(0.2f, 0.4f, 0.1f);

	float test = colour.average();
	bool answer = false;
	if (test - 0.2333f < 0.0005)
		answer = true;

	EXPECT_EQ(answer, true);
}

/*testing Point3D.h*/

TEST(pointFunc, constructor)
{
	Point3D p;
	
	int count = 0;
	if (abs(p.x) < 0.0005f)
		count++;
	if (abs(p.y) < 0.0005f)
		count++;
	if (abs(p.z) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, singleConstruct)
{
	Point3D p(2.0f);

	int count = 0;
	if (abs(p.x - 2.0f) < 0.0005f)
		count++;
	if (abs(p.y - 2.0f) < 0.0005f)
		count++;
	if (abs(p.z - 2.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, multiConstruct)
{
	Point3D p(2.0f, 1.0f, 4.0f);

	int count = 0;
	if (abs(p.x - 2.0f) < 0.0005f)
		count++;
	if (abs(p.y - 1.0f) < 0.0005f)
		count++;
	if (abs(p.z - 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, copyConstruct)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2(p);

	int count = 0;
	if (abs(p2.x - 2.0f) < 0.0005f)
		count++;
	if (abs(p2.y - 1.0f) < 0.0005f)
		count++;
	if (abs(p2.z - 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, assignmentOperator)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2;

	p2 = p;
	int count = 0;
	if (abs(p2.x - 2.0f) < 0.0005f)
		count++;
	if (abs(p2.y - 1.0f) < 0.0005f)
		count++;
	if (abs(p2.z - 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, minusOperator)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2 = -p;

	int count = 0;
	if (abs(p2.x + 2.0f) < 0.0005f)
		count++;
	if (abs(p2.y + 1.0f) < 0.0005f)
		count++;
	if (abs(p2.z + 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, vectorBetween)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2(5.0f, 2.0f, 1.0f);
	Vector3D v = p2 - p;

	int count = 0;
	if (abs(v.x - 3.0f) < 0.0005f)
		count++;
	if (abs(v.y - 1.0f) < 0.0005f)
		count++;
	if (abs(v.z + 3.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, vectorAddition)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Vector3D v(1.0f, 2.0f, -1.0f);

	Point3D p2 = p + v;
	int count = 0;
	if (abs(p2.x - 3.0f) < 0.0005f)
		count++;
	if (abs(p2.y - 3.0f) < 0.0005f)
		count++;
	if (abs(p2.z - 3.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, vectorSubtract)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Vector3D v(1.0f, 2.0f, -1.0f);

	Point3D p2 = p - v;
	int count = 0;
	if (abs(p2.x - 1.0f) < 0.0005f)
		count++;
	if (abs(p2.y + 1.0f) < 0.0005f)
		count++;
	if (abs(p2.z - 5.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, multiply)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2 = p * 2.0f;

	int count = 0;
	if (abs(p2.x - 4.0f) < 0.0005f)
		count++;
	if (abs(p2.y - 2.0f) < 0.0005f)
		count++;
	if (abs(p2.z - 8.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(pointFunc, dSquared)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2(5.0f, 2.0f, 1.0f);

	double test = p.dSquared(p2);
	bool answer = false;
	if (abs(test - 19.0f) < 0.0005f)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(pointFunc, distance)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Point3D p2(5.0f, 2.0f, 1.0f);

	double test = p.distance(p2);
	bool answer = false;
	if (abs(test - 4.3589f) < 0.0005f)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(pointFunc, matrixMulti)
{
	Point3D p(2.0f, 1.0f, 4.0f);
	Matrix m;
	m.m[0][0] = 2.0f;
	m.m[1][1] = 2.0f;
	m.m[2][2] = 2.0f;

	Point3D p2 = m * p;
	int count = 0;
	if (abs(p2.x - 4.0f) < 0.0005f)
		count++;
	if (abs(p2.y - 2.0f) < 0.0005f)
		count++;
	if (abs(p2.z - 8.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

/*testing Vector3D.h*/

TEST(vectorFunc, construct)
{
	Vector3D v;

	int count = 0;
	if (abs(v.x) < 0.0005f)
		count++;
	if (abs(v.y) < 0.0005f)
		count++;
	if (abs(v.z) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, singleConstruct)
{
	Vector3D v(3.0f);

	int count = 0;
	if (abs(v.x - 3.0f) < 0.0005f)
		count++;
	if (abs(v.y - 3.0f) < 0.0005f)
		count++;
	if (abs(v.z - 3.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, multiConstruct)
{
	Vector3D v(2.0f, 1.0f, 4.0f);

	int count = 0;
	if (abs(v.x - 2.0f) < 0.0005f)
		count++;
	if (abs(v.y - 1.0f) < 0.0005f)
		count++;
	if (abs(v.z - 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, vectorConstruct)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2(v);

	int count = 0;
	if (abs(v2.x - 2.0f) < 0.0005f)
		count++;
	if (abs(v2.y - 1.0f) < 0.0005f)
		count++;
	if (abs(v2.z - 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, normalConstruct)
{
	Normal n(-0.3f, 0.7f, 0.1f);
	Vector3D v(n);

	int count = 0;
	if (abs(v.x + 0.3f) < 0.0005f)
		count++;
	if (abs(v.y - 0.7f) < 0.0005f)
		count++;
	if (abs(v.z - 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, pointConstruct)
{
	Point3D p(7.0f, 5.0f, -2.0f);
	Vector3D v(p);

	int count = 0;
	if (abs(v.x - 7.0f) < 0.0005f)
		count++;
	if (abs(v.y - 5.0f) < 0.0005f)
		count++;
	if (abs(v.z + 2.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, vectorAssignment)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = v;

	int count = 0;
	if (abs(v2.x - 2.0f) < 0.0005f)
		count++;
	if (abs(v2.y - 1.0f) < 0.0005f)
		count++;
	if (abs(v2.z - 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, normalAssignment)
{
	Normal n(-0.3f, 0.7f, 0.1f);
	Vector3D v = n;

	int count = 0;
	if (abs(v.x + 0.3f) < 0.0005f)
		count++;
	if (abs(v.y - 0.7f) < 0.0005f)
		count++;
	if (abs(v.z - 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, pointAssignment)
{
	Point3D p(7.0f, 5.0f, -2.0f);
	Vector3D v = p;

	int count = 0;
	if (abs(v.x - 7.0f) < 0.0005f)
		count++;
	if (abs(v.y - 5.0f) < 0.0005f)
		count++;
	if (abs(v.z + 2.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, minusVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = -v;

	int count = 0;
	if (abs(v2.x + 2.0f) < 0.0005f)
		count++;
	if (abs(v2.y + 1.0f) < 0.0005f)
		count++;
	if (abs(v2.z + 4.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, length)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	double test = v.length();

	bool answer = false;
	if (abs(test - 4.5826f) < 0.0005f)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(vectorFunc, lengthSquared)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	double test = v.lengthSquared();

	bool answer = false;
	if (abs(test - 21.0f) < 0.0005f)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(vectorFunc, mulitplyVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = v * 2.0f;

	int count = 0;
	if (abs(v2.x - 4.0f) < 0.0005f)
		count++;
	if (abs(v2.y - 2.0f) < 0.0005f)
		count++;
	if (abs(v2.z - 8.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, divideVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = v / 2.0f;

	int count = 0;
	if (abs(v2.x - 1.0f) < 0.0005f)
		count++;
	if (abs(v2.y - 0.5f) < 0.0005f)
		count++;
	if (abs(v2.z - 2.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, addVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2(7.0f, 5.0f, -2.0f);
	Vector3D v3 = v + v2;

	int count = 0;
	if (abs(v3.x - 9.0f) < 0.0005f)
		count++;
	if (abs(v3.y - 6.0f) < 0.0005f)
		count++;
	if (abs(v3.z - 2.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, compundAddVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2(7.0f, 5.0f, -2.0f);
	v += v2;

	int count = 0;
	if (abs(v.x - 9.0f) < 0.0005f)
		count++;
	if (abs(v.y - 6.0f) < 0.0005f)
		count++;
	if (abs(v.z - 2.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, subtractVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2(7.0f, 5.0f, -2.0f);
	Vector3D v3 = v - v2;

	int count = 0;
	if (abs(v3.x + 5.0f) < 0.0005f)
		count++;
	if (abs(v3.y + 4.0f) < 0.0005f)
		count++;
	if (abs(v3.z - 6.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, dotProduct)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2(7.0f, 5.0f, -2.0f);
	double dot = v * v2;

	bool answer = false;
	if (abs(dot - 11.0f) < 0.0005f)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(vectorFunc, crossProduct)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2(7.0f, 5.0f, -2.0f);
	Vector3D cross = v ^ v2;

	int count = 0;
	if (abs(cross.x + 22.0f) < 0.0005f)
		count++;
	if (abs(cross.y - 32.0f) < 0.0005f)
		count++;
	if (abs(cross.z - 3.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, normalise)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	v.normalise();

	int count = 0;
	if (abs(v.x - 0.4364f) < 0.0005f)
		count++;
	if (abs(v.y - 0.2182f) < 0.0005f)
		count++;
	if (abs(v.z - 0.8729f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, hat)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = v.hat();

	int count = 0;
	if (abs(v2.x - 0.4364f) < 0.0005f)
		count++;
	if (abs(v2.y - 0.2182f) < 0.0005f)
		count++;
	if (abs(v2.z - 0.8729f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, doubleByVector)
{
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = 2.0f * v;

	int count = 0;
	if (abs(v2.x - 4.0f) < 0.0005f)
		count++;
	if (abs(v2.y - 2.0f) < 0.0005f)
		count++;
	if (abs(v2.z - 8.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(vectorFunc, matrixByVector)
{
	Matrix m;
	m.m[0][0] = 2.0f;
	m.m[1][1] = 2.0f;
	m.m[2][2] = 2.0f;
	Vector3D v(2.0f, 1.0f, 4.0f);
	Vector3D v2 = m * v;

	int count = 0;
	if (abs(v2.x - 4.0f) < 0.0005f)
		count++;
	if (abs(v2.y - 2.0f) < 0.0005f)
		count++;
	if (abs(v2.z - 8.0f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

/*testing Normal.h*/

TEST(normalFunc, construct)
{
	Normal n;

	int count = 0;
	if (abs(n.x) < 0.0005f)
		count++;
	if (abs(n.y) < 0.0005f)
		count++;
	if (abs(n.z) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, singleConstruct)
{
	Normal n(0.2f);

	int count = 0;
	if (abs(n.x - 0.2f) < 0.0005f)
		count++;
	if (abs(n.y - 0.2f) < 0.0005f)
		count++;
	if (abs(n.z - 0.2f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, tripleConstruct)
{
	Normal n(0.7f, -0.3f, -0.1f);

	int count = 0;
	if (abs(n.x - 0.7f) < 0.0005f)
		count++;
	if (abs(n.y + 0.3f) < 0.0005f)
		count++;
	if (abs(n.z + 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, copyConstruct)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2(n);

	int count = 0;
	if (abs(n2.x - 0.7f) < 0.0005f)
		count++;
	if (abs(n2.y + 0.3f) < 0.0005f)
		count++;
	if (abs(n2.z + 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, vectorConstruct)
{
	Vector3D v(0.7f, -0.3f, -0.1f);
	Normal n(v);

	int count = 0;
	if (abs(n.x - 0.7f) < 0.0005f)
		count++;
	if (abs(n.y + 0.3f) < 0.0005f)
		count++;
	if (abs(n.z + 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, normalAssignment)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2 = n;

	int count = 0;
	if (abs(n.x - 0.7f) < 0.0005f)
		count++;
	if (abs(n.y + 0.3f) < 0.0005f)
		count++;
	if (abs(n.z + 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, vectorAssignment)
{
	Vector3D v(0.7f, -0.3f, -0.1f);
	Normal n = v;

	int count = 0;
	if (abs(n.x - 0.7f) < 0.0005f)
		count++;
	if (abs(n.y + 0.3f) < 0.0005f)
		count++;
	if (abs(n.z + 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, pointAssignment)
{
	Point3D p(0.7f, -0.3f, -0.1f);
	Normal n = p;

	int count = 0;
	if (abs(n.x - 0.7f) < 0.0005f)
		count++;
	if (abs(n.y + 0.3f) < 0.0005f)
		count++;
	if (abs(n.z + 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, negative)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2 = -n;

	int count = 0;
	if (abs(n2.x + 0.7f) < 0.0005f)
		count++;
	if (abs(n2.y - 0.3f) < 0.0005f)
		count++;
	if (abs(n2.z - 0.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, normalAddition)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2(-0.4f, -0.2f, 0.6f);
	Normal n3 = n + n2;

	int count = 0;
	if (abs(n3.x - 0.3f) < 0.0005f)
		count++;
	if (abs(n3.y + 0.5f) < 0.0005f)
		count++;
	if (abs(n3.z - 0.5f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, compundNormalAddition)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2(-0.4f, -0.2f, 0.6f);
	n2 += n;

	int count = 0;
	if (abs(n2.x - 0.3f) < 0.0005f)
		count++;
	if (abs(n2.y + 0.5f) < 0.0005f)
		count++;
	if (abs(n2.z - 0.5f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, normalByVector)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Vector3D v(2.0f, 1.0f, 4.0f);
	double test = n * v;

	bool answer = false;
	if (abs(test - 0.7f) < 0.0005f)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(normalFunc, normalByDouble)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2 = n * 0.8f;

	int count = 0;
	if (abs(n2.x - 0.56f) < 0.0005f)
		count++;
	if (abs(n2.y + 0.24f) < 0.0005f)
		count++;
	if (abs(n2.z + 0.08f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, normalise)
{
	Normal n(7.0f, -3.0f, -1.0f);
	n.normalise();

	int count = 0;
	if (abs(n.x - 0.9113f) < 0.0005f)
		count++;
	if (abs(n.y + 0.3906f) < 0.0005f)
		count++;
	if (abs(n.z + 0.1302f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, doubleByNormal)
{
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2 = 0.8f * n;

	int count = 0;
	if (abs(n2.x - 0.56f) < 0.0005f)
		count++;
	if (abs(n2.y + 0.24f) < 0.0005f)
		count++;
	if (abs(n2.z + 0.08f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, vectorAndNormal)
{
	Vector3D v(2.0f, 4.0f, 1.0f);
	Normal n(0.7f, -0.3f, -0.1f);
	Vector3D v2 = v + n;

	int count = 0;
	if (abs(v2.x - 2.7f) < 0.0005f)
		count++;
	if (abs(v2.y - 3.7f) < 0.0005f)
		count++;
	if (abs(v2.z - 0.9f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, vectorFromNormal)
{
	Vector3D v(2.0f, 4.0f, 1.0f);
	Normal n(0.7f, -0.3f, -0.1f);
	Vector3D v2 = v - n;

	int count = 0;
	if (abs(v2.x - 1.3f) < 0.0005f)
		count++;
	if (abs(v2.y - 4.3f) < 0.0005f)
		count++;
	if (abs(v2.z - 1.1f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

TEST(normalFunc, vectorByNormal)
{
	Vector3D v(2.0f, 4.0f, 1.0f);
	Normal n(0.7f, -0.3f, -0.1f);
	double test = v * n;

	bool answer = false;
	if (abs(test - 0.1f) < 0.0005)
		answer = true;

	EXPECT_EQ(answer, true);
}

TEST(normalFunc, matrixByNormal)
{
	Matrix m;
	m.m[0][0] = 2.0f;
	m.m[1][1] = 2.0f;
	m.m[2][2] = 2.0f;
	Normal n(0.7f, -0.3f, -0.1f);
	Normal n2 = m * n;

	int count = 0;
	if (abs(n2.x - 1.4f) < 0.0005f)
		count++;
	if (abs(n2.y + 0.6f) < 0.0005f)
		count++;
	if (abs(n2.z + 0.2f) < 0.0005f)
		count++;

	EXPECT_EQ(count, 3);
}

/*testing Ray.h*/

TEST(rayFunc, compundConstruct)
{
	Ray ray;
	ray.o = Point3D(0.0, 0.0, 0.0);
	ray.d = Vector3D(0.0, 1.0, 0.0);
	Ray ray2(ray);

	EXPECT_EQ(ray2.o.x, ray.o.x);
	EXPECT_EQ(ray2.d.y, ray.d.y);
}

TEST(rayFunc, componentConstruct)
{
	Ray ray;
	ray.o = Point3D(0.0, 0.0, 0.0);
	ray.d = Vector3D(0.0, 1.0, 0.0);
	Ray ray2(ray.o, ray.d);

	EXPECT_EQ(ray2.o.x, ray.o.x);
	EXPECT_EQ(ray2.d.y, ray.d.y);
}

TEST(rayFunc, assignmentOperator)
{
	Ray ray;
	ray.o = Point3D(0.0, 0.0, 0.0);
	ray.d = Vector3D(0.0, 1.0, 0.0);
	Ray ray2 = ray;

	EXPECT_EQ(ray2.o.x, ray.o.x);
	EXPECT_EQ(ray2.d.y, ray.d.y);
}

/*testing ShaderRec.h*/

TEST(shaderFunc, copyConstruct)
{
	World scene;
	ShadeRec shade(scene);
	ShadeRec shade2(shade);

	EXPECT_EQ(shade.hitObject, shade2.hitObject);
}

/*testing Sphere.h*/

TEST(sphereFunc, clone)
{
	Sphere sphere;
	sphere.setColour(1.0, 0.0, 0.0);
	Sphere* sphere2 = sphere.clone();

	EXPECT_EQ(sphere.getColour(), sphere2->getColour());
}

TEST(sphereFunc, assignmentOperator)
{
	Sphere sphere;
	sphere.setColour(1.0, 0.0, 0.0);
	Sphere sphere2 = sphere;

	EXPECT_EQ(sphere.getColour(), sphere2.getColour());
}

TEST(sphereFunc, setColourObject)
{
	RGBColour red(1.0, 0.0, 0.0);
	Sphere sphere;
	sphere.setColour(red);

	EXPECT_EQ(sphere.getColour(), red);
}

TEST(sphereFunc, setColourCoords)
{
	Sphere sphere;
	sphere.setColour(1.0, 0.0, 0.0);

	EXPECT_EQ(sphere.getColour().r, 1.0);
}

TEST(sphereFunc, rayCollision)
{
	World scene;
	double t;
	ShadeRec shade(scene);
	Sphere sphere(Point3D(0, 0, 0), 50);
	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	EXPECT_EQ(sphere.hit(ray, t, shade), true);
}

/*testing Plane.h*/

TEST(planeFunc, clone)
{
	Plane plane;
	plane.setColour(1.0, 0.0, 0.0);
	Plane* plane2 = plane.clone();

	EXPECT_EQ(plane2->getColour().r, 1.0);
}

TEST(planeFunc, assignmentOperator)
{
	Plane plane;
	plane.setColour(1.0, 0.0, 0.0);
	Plane plane2 = plane;

	EXPECT_EQ(plane2.getColour().r, 1.0);
}

TEST(planeFunc, setColourObject)
{
	Plane plane;
	RGBColour red(1.0, 0.0, 0.0);
	plane.setColour(red);

	EXPECT_EQ(plane.getColour().r, 1.0);
}

TEST(planeFunc, setColourCoords)
{
	Plane plane;
	RGBColour red(1.0, 0.0, 0.0);
	plane.setColour(red);

	EXPECT_EQ(plane.getColour().r, 1.0);
}

TEST(planeFunc, rayCollision)
{
	World scene;
	double t;
	ShadeRec shade(scene);
	Plane plane(Point3D(0.0, 0.0, -5.0), Normal(0.0, 0.0, 1.0));
	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	EXPECT_EQ(plane.hit(ray, t, shade), true);
}

//testing the tracer objects is difficult at the moment
//because the tracer type is declared in the 'build' function of the World object
//i'm holding off on testing this until a later iteration
//when a unified tracing object has been introduced

/*testing World.h*/

TEST(worldFunc, sphereCreate) //will have to rework once I have a unified tracer
{
	World scene;
	scene.sphere.setCenter(0, 0, 0);
	scene.sphere.setColour(1.0, 0.0, 0.0);
	Sphere test = scene.sphere;
	
	EXPECT_EQ(test.getColour().r, scene.sphere.getColour().r);
}

TEST(worldFunc, addObject)
{
	World scene;
	Sphere* sphere = new Sphere();
	sphere->setColour(1.0, 1.0, 0.0);
	sphere->setCenter(0, 0, 0);
	sphere->setRadius(50);
	scene.addObject(sphere);

	EXPECT_EQ(scene.objects[0]->getColour().r, 1.0);
	EXPECT_EQ(scene.objects[0]->getColour().g, 1.0);
	EXPECT_EQ(scene.objects[0]->getColour().b, 0.0);
}

TEST(worldFunc, backgroundColour)
{
	World scene;
	
	EXPECT_EQ(scene.backgroundColor.r, 0.0);
	EXPECT_EQ(scene.backgroundColor.g, 0.0);
	EXPECT_EQ(scene.backgroundColor.b, 0.0);
}

TEST(worldFunc, build)
{
	World scene;
	scene.build();
	Ray ray(Point3D(0, 0, 0), Vector3D(0, 0, -1));

	EXPECT_EQ(scene.tracerPtr->traceRay(ray).r, 1.0);
	EXPECT_EQ(scene.tracerPtr->traceRay(ray).g, 0.0);
	EXPECT_EQ(scene.tracerPtr->traceRay(ray).b, 0.0);
}

/*testing GraphicsWindow.h*/

TEST(graphicsFunc, copyConstructor)
{
	GraphicsWindow viewplane;
	GraphicsWindow viewCopy(viewplane);

	EXPECT_EQ(viewplane.gamma, viewCopy.gamma);
	EXPECT_EQ(viewplane.invGamma, viewCopy.invGamma);
	EXPECT_EQ(viewplane.ifOutOfGamut, viewCopy.ifOutOfGamut);
}

TEST(graphicsFunc, assignmentOperator)
{
	GraphicsWindow viewplane;
	GraphicsWindow viewCopy = viewplane;

	EXPECT_EQ(viewplane.gamma, viewCopy.gamma);
	EXPECT_EQ(viewplane.invGamma, viewCopy.invGamma);
	EXPECT_EQ(viewplane.ifOutOfGamut, viewCopy.ifOutOfGamut);
}

TEST(graphicsFunc, gamma)
{
	GraphicsWindow viewplane;
	viewplane.setGamma(0.5);

	EXPECT_EQ(viewplane.gamma, 0.5);
	EXPECT_EQ(viewplane.invGamma, 2.0);
}

TEST(graphicsFunc, gamut)
{
	GraphicsWindow viewplane;
	viewplane.setGamutDisplay(true);

	EXPECT_EQ(viewplane.ifOutOfGamut, true);
}

TEST(graphicsFunc, max)
{
	GraphicsWindow viewplane;
	RGBColour colour(1.2, 0.5, 0.8);

	EXPECT_EQ(viewplane.maxToOne(colour).r, 1.0);
	EXPECT_NEAR(viewplane.maxToOne(colour).g, 0.416667, 0.001);
	EXPECT_NEAR(viewplane.maxToOne(colour).b, 0.666667, 0.001);
}

TEST(graphicsFunc, clamp)
{
	GraphicsWindow viewplane;
	RGBColour colour(1.2, 1.1, 1.4);

	EXPECT_EQ(viewplane.clampToColour(colour).r, 1.0);
	EXPECT_EQ(viewplane.clampToColour(colour).g, 0.0);
	EXPECT_EQ(viewplane.clampToColour(colour).b, 0.0);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}

