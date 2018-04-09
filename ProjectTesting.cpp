// ProjectTesting.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "gtest/gtest.h"
#include "Matrix.h"
#include "RGBColour.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "Lambert.h"
#include "Directional.h"
#include "GeometricObject.h"
#include "Sphere.h"
#include "Disk.h"
#include "World.h"
#include "Plane.h"
#include "Tracer.h"
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

/*testing Tracer.h*/

TEST(tracerFunc, defaultConstruct)
{
	Tracer trace;

	EXPECT_EQ(trace.hitObject, false);
	EXPECT_EQ(trace.pixelColour, black);
}

TEST(tracerFunc, assignConstruct)
{
	Tracer trace;
	trace.pixelColour = RGBColour(1.0, 0.0, 0.0);
	trace.hitPoint = Point3D(0.0, 0.0, 0.0);

	Tracer trace2(trace);
	EXPECT_EQ(trace2.hitObject, false);
	EXPECT_EQ(trace2.pixelColour.r, 1.0);
	EXPECT_EQ(trace2.pixelColour.g, 0.0);
	EXPECT_EQ(trace2.pixelColour.b, 0.0);

	EXPECT_EQ(trace2.hitPoint.x, 0.0);
	EXPECT_EQ(trace2.hitPoint.y, 0.0);
	EXPECT_EQ(trace2.hitPoint.z, 0.0);
}

/*testing Lambert.h*/

TEST(lambertFunc, defaultConstruct)
{
	Lambert testShader;

	EXPECT_EQ(testShader.getAlbedo(), 0.18);
	EXPECT_EQ(testShader.getColour().r, 0.0);
	EXPECT_EQ(testShader.getColour().g, 0.0);
	EXPECT_EQ(testShader.getColour().b, 0.0);
}

TEST(lambertFunc, assignConstruct)
{
	Lambert testShader(1.0, 0.0, 0.0, 0.18);

	EXPECT_EQ(testShader.getAlbedo(), 0.18);
	EXPECT_EQ(testShader.getColour().r, 1.0);
	EXPECT_EQ(testShader.getColour().g, 0.0);
	EXPECT_EQ(testShader.getColour().b, 0.0);
}

TEST(lambertFunc, copyConstruct)
{
	Lambert testShader(1.0, 0.0, 0.0, 0.18);
	Lambert testShader2(testShader);

	EXPECT_EQ(testShader2.getAlbedo(), 0.18);
	EXPECT_EQ(testShader2.getColour().r, 1.0);
	EXPECT_EQ(testShader2.getColour().g, 0.0);
	EXPECT_EQ(testShader2.getColour().b, 0.0);
}

TEST(lambertFunc, compoundConstruct)
{
	RGBColour green(0.0, 1.0, 0.0);
	Lambert testShader(green, 0.18);

	EXPECT_EQ(testShader.getAlbedo(), 0.18);
	EXPECT_EQ(testShader.getColour().r, 0.0);
	EXPECT_EQ(testShader.getColour().g, 1.0);
	EXPECT_EQ(testShader.getColour().b, 0.0);
}

TEST(lambertFunc, reflectedColour)
{
	Tracer trace;
	Lambert testShader;
	testShader.setColour(0.0, 0.0, 1.0);
	testShader.setAlbedo(0.18);
	trace.pixelColour = testShader.getReflectedColour(trace);

	EXPECT_EQ(trace.pixelColour.r, 0.0);
	EXPECT_EQ(trace.pixelColour.g, 0.0);
	EXPECT_NEAR(trace.pixelColour.b, 0.18, 0.000001);
}

/*testing Sphere.h*/

TEST(sphereFunc, clone)
{
	Sphere sphere;
	sphere.shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	Sphere* sphere2 = sphere.clone();

	EXPECT_EQ(sphere2->shader->getAlbedo(), 0.18);
	EXPECT_EQ(sphere2->shader->getColour().r, 1.0);
	EXPECT_EQ(sphere2->shader->getColour().g, 0.0);
	EXPECT_EQ(sphere2->shader->getColour().b, 0.0);
}

TEST(sphereFunc, assignmentOperator)
{
	Sphere sphere;
	sphere.shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	Sphere* sphere2 = &sphere;

	EXPECT_EQ(sphere2->shader->getAlbedo(), 0.18);
	EXPECT_EQ(sphere2->shader->getColour().r, 1.0);
	EXPECT_EQ(sphere2->shader->getColour().g, 0.0);
	EXPECT_EQ(sphere2->shader->getColour().b, 0.0);
}

TEST(sphereFunc, rayCollision)
{
	double t;
	Tracer trace;
	Sphere sphere(Point3D(0, 0, 0), 50);
	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	EXPECT_EQ(sphere.hit(ray, t, trace), true);
}

TEST(sphereFunc, maxCoords)
{
	Sphere sphere(Point3D(0.0, 0.0, 0.0), 10.0);
	Point3D maxCoords = sphere.maxBoundCoords();
	
	EXPECT_EQ(maxCoords.x, 10.0);
	EXPECT_EQ(maxCoords.y, 10.0);
	EXPECT_EQ(maxCoords.z, 10.0);
}

TEST(sphereFunc, minCoords)
{
	Sphere sphere(Point3D(0.0, 0.0, 0.0), 10.0);
	Point3D minCoords = sphere.minBoundCoords();

	EXPECT_EQ(minCoords.x, -10.0);
	EXPECT_EQ(minCoords.y, -10.0);
	EXPECT_EQ(minCoords.z, -10.0);
}

/*testing Plane.h*/

TEST(planeFunc, clone)
{
	Plane plane;
	plane.shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	Plane* plane2 = plane.clone();

	EXPECT_EQ(plane2->shader->getAlbedo(), 0.18);
	EXPECT_EQ(plane2->shader->getColour().r, 1.0);
	EXPECT_EQ(plane2->shader->getColour().g, 0.0);
	EXPECT_EQ(plane2->shader->getColour().b, 0.0);
}

TEST(planeFunc, assignmentOperator)
{
	Plane plane;
	plane.shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	Plane* plane2 = &plane;

	EXPECT_EQ(plane2->shader->getAlbedo(), 0.18);
	EXPECT_EQ(plane2->shader->getColour().r, 1.0);
	EXPECT_EQ(plane2->shader->getColour().g, 0.0);
	EXPECT_EQ(plane2->shader->getColour().b, 0.0);
}

TEST(planeFunc, rayCollision)
{
	double t;
	Tracer trace;
	Plane plane(Point3D(0.0, 0.0, -1.0), Normal(0.0, 0.0, 1.0));
	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	EXPECT_EQ(plane.hit(ray, t, trace), true);
}

TEST(planeFunc, maxCoords)
{
	Plane plane;
	Point3D maxCoords = plane.maxBoundCoords();

	EXPECT_EQ(maxCoords.x, 250);
	EXPECT_EQ(maxCoords.y, 250);
	EXPECT_EQ(maxCoords.z, 100);
}

TEST(planeFunc, minCoords)
{
	Plane plane;
	Point3D minCoords = plane.minBoundCoords();

	EXPECT_EQ(minCoords.x, -250);
	EXPECT_EQ(minCoords.y, -250);
	EXPECT_EQ(minCoords.z, -100);
}

/*testing Disk.h*/

TEST(diskFunc, clone)
{
	Disk disk;
	disk.shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	Disk* disk2 = disk.clone();

	EXPECT_EQ(disk2->shader->getAlbedo(), 0.18);
	EXPECT_EQ(disk2->shader->getColour().r, 1.0);
	EXPECT_EQ(disk2->shader->getColour().g, 0.0);
	EXPECT_EQ(disk2->shader->getColour().b, 0.0);
}

TEST(diskFunc, assignmentOperator)
{
	Disk disk;
	disk.shader = new Lambert(1.0, 0.0, 0.0, 0.18);
	Disk* disk2 = &disk;

	EXPECT_EQ(disk2->shader->getAlbedo(), 0.18);
	EXPECT_EQ(disk2->shader->getColour().r, 1.0);
	EXPECT_EQ(disk2->shader->getColour().g, 0.0);
	EXPECT_EQ(disk2->shader->getColour().b, 0.0);
}

TEST(diskFunc, rayCollision)
{
	double t;
	Tracer trace;
	Disk disk(Point3D(0.0, 0.0, -1.0), Normal(0.0, 0.0, 1.0), 50);
	Ray ray(Point3D(20.0, 20.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	EXPECT_EQ(disk.hit(ray, t, trace), true);
}

TEST(diskFunc, maxCoords)
{
	Disk disk(Point3D(0, 0, 0), Normal(1.0, -1.0, 1.0), 100);
	Point3D maxCoords = disk.maxBoundCoords();

	EXPECT_NEAR(maxCoords.x, 81.67, 1);
	EXPECT_NEAR(maxCoords.y, 81.67, 1);
	EXPECT_NEAR(maxCoords.z, 81.67, 1);
}

TEST(diskFunc, minCoords)
{
	Disk disk(Point3D(0, 0, 0), Normal(1.0, -1.0, 1.0), 100);
	Point3D minCoords = disk.minBoundCoords();

	EXPECT_NEAR(minCoords.x, -81.67, 1);
	EXPECT_NEAR(minCoords.y, -81.67, 1);
	EXPECT_NEAR(minCoords.z, -81.67, 1);
}

/*testing Polygon.h*/

TEST(polygonFunc, minCoords)
{
	Polygon test(Point3D(0.0, 0.0, 0.0), Point3D(100.0, 0.0, 0.0), Point3D(100.0, 100.0, 0.0), 
		Normal(0.0, 0.0, 1.0), Normal(0.0, 0.0, 1.0), Normal(0.0, 0.0, 1.0));

	Point3D max = test.maxBoundCoords();
	EXPECT_NEAR(max.x, 100.0, 1.0);
	EXPECT_NEAR(max.y, 100.0, 1.0);
	EXPECT_NEAR(max.z, 0.0, 1.0);
}

TEST(polygonFunc, maxCoords)
{
	Polygon test(Point3D(0.0, 0.0, 0.0), Point3D(100.0, 0.0, 0.0), Point3D(100.0, 100.0, 0.0),
		Normal(0.0, 0.0, 1.0), Normal(0.0, 0.0, 1.0), Normal(0.0, 0.0, 1.0));

	Point3D min = test.minBoundCoords();
	EXPECT_NEAR(min.x, 0.0, 1.0);
	EXPECT_NEAR(min.y, 0.0, 1.0);
	EXPECT_NEAR(min.z, 0.0, 1.0);
}

/*testing Directional.h*/

TEST(directionalFunc, getLighting)
{
	Directional light(RGBColour(1.0, 1.0, 1.0), 3.0, Vector3D(0.0, -1.0, 0.0));
	Tracer trace;
	trace.hitPoint = Point3D(0.0, 0.0, 0.0);
	trace.normal = Normal(0.0, 1.0, 1.0);
	trace.normal.normalise();

	trace.pixelColour = light.getLightInfo(trace);
	EXPECT_NEAR(trace.pixelColour.r, 2.121, 0.001);
	EXPECT_NEAR(trace.pixelColour.g, 2.121, 0.001);
	EXPECT_NEAR(trace.pixelColour.b, 2.121, 0.001);
}

/*testing AccelerationStructure.h*/

TEST(structureFunc, search)
{
	AccelerationStructure hierarchy;
	vector<GeometricObject*> objects;

	Sphere* sphere2 = new Sphere(Point3D(0, 0, 0), 100);
	sphere2->shader = new Lambert(0.0, 1.0, 0.0, 0.18);
	objects.push_back(sphere2);

	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	hierarchy.build(objects);
	hierarchy.search(ray);

	EXPECT_EQ(hierarchy.tr.hitObject, true);

	EXPECT_NEAR(hierarchy.tr.hitPoint.x, 0.0, 0.001);
	EXPECT_NEAR(hierarchy.tr.hitPoint.y, 0.0, 0.001);
	EXPECT_NEAR(hierarchy.tr.hitPoint.z, -100.0, 0.001);

	EXPECT_NEAR(hierarchy.tr.normal.x, 0.0, 0.001);
	EXPECT_NEAR(hierarchy.tr.normal.y, 0.0, 0.001);
	EXPECT_NEAR(hierarchy.tr.normal.z, -1.0, 0.001);

	EXPECT_NEAR(hierarchy.tr.pixelColour.r, 0.0, 0.001);
	EXPECT_NEAR(hierarchy.tr.pixelColour.g, 0.18, 0.001);
	EXPECT_NEAR(hierarchy.tr.pixelColour.b, 0.0, 0.001);
}

TEST(structureFunc, collisionsNum)
{
	AccelerationStructure hierarchy;
	vector<GeometricObject*> objects;

	Sphere* sphere2 = new Sphere(Point3D(0, 0, 0), 100);
	sphere2->shader = new Lambert(0.0, 1.0, 0.0, 0.18);
	objects.push_back(sphere2);

	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -1.0));

	hierarchy.build(objects);
	hierarchy.search(ray);

	EXPECT_EQ(hierarchy.totalCol, 1);
	EXPECT_EQ(hierarchy.successCol, 1);
}

/*testing ObjLoader.h*/

TEST(loaderFunc, loadObj)
{
	ObjLoader loader;

	EXPECT_EQ(loader.loadObj("sphere.obj"), 0);
	EXPECT_EQ(loader.polygons.size(), 224);
}

/*testing World.h*/

TEST(worldFunc, addObject)
{
	World scene;
	Sphere* sphere = new Sphere();
	sphere->shader = new Lambert(1.0, 1.0, 0.0, 0.18);
	scene.addObject(sphere);

	EXPECT_EQ(scene.objects[0]->shader->getColour().r, 1.0);
	EXPECT_EQ(scene.objects[0]->shader->getColour().g, 1.0);
	EXPECT_EQ(scene.objects[0]->shader->getColour().b, 0.0);
}

TEST(worldFunc, addLight)
{
	World scene;
	Directional* light = new Directional();
	scene.addLight(light);

	EXPECT_EQ(scene.lights.size(), 1);
}

TEST(worldFunc, backgroundColour)
{
	World scene;
	
	EXPECT_EQ(scene.backgroundColour.r, 0.0);
	EXPECT_EQ(scene.backgroundColour.g, 0.0);
	EXPECT_EQ(scene.backgroundColour.b, 0.0);
}

TEST(worldFunc, build)
{
	World scene;
	scene.build();

	EXPECT_EQ(scene.objects.size(), 0);
	EXPECT_EQ(scene.lights.size(), 2);
}

TEST(worldFunc, collision)
{
	World scene;
	scene.build();
	Ray ray(Point3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, -100.0));
	RGBColour pixel = scene.objCollision(ray);

	EXPECT_NEAR(pixel.r, 0.0, 0.001);
	EXPECT_NEAR(pixel.g, 0.0, 0.001);
	EXPECT_NEAR(pixel.b, 0.0, 0.001);
}

/*testing GraphicsWindow.h*/

TEST(graphicsFunc, max)
{
	GraphicsWindow viewplane;
	RGBColour colour(1.2, 0.5, 0.8);

	EXPECT_EQ(viewplane.maxToOne(colour).r, 1.0);
	EXPECT_NEAR(viewplane.maxToOne(colour).g, 0.416667, 0.001);
	EXPECT_NEAR(viewplane.maxToOne(colour).b, 0.666667, 0.001);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}

