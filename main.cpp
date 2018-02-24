// 2017-18 Samuel Mounter
// All rights reserved

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "GraphicsWindow.h"
#include "World.h"
#include "RGBColour.h"
#include "Ray.h"
#include "glut.h"

GraphicsWindow graphics;
World tracerScene;

void winReshapeFunc(GLint w, GLint h)
{
	// specify current matrix
	glMatrixMode(GL_PROJECTION);

	// load an identity matrix
	glLoadIdentity();

	// create a projection matrix... i.e. 2D projection onto xy plane
	glOrtho(-SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// set up the viewport
	glViewport
	(
		0,				// lower left x position
		0,				// lower left y position
		(GLsizei)SCREEN_WIDTH,	// viewport width
		(GLsizei)SCREEN_HEIGHT	// viewport height
	);
}

void renderScene()
{
	clock_t t = clock();
	RGBColour pixelColor;
	Ray	ray;
	float zw = 100.0;			// hardwired in

	ray.d = Vector3D(0, 0, -1);

	for (int r = 0; r < SCREEN_HEIGHT; r++) // up
		for (int c = 0; c <= SCREEN_WIDTH; c++) // across 	
		{
			ray.o = Point3D(1 * (c - SCREEN_WIDTH / 2.0 + 0.5), 1 * (r - SCREEN_HEIGHT / 2.0 + 0.5), zw);
			pixelColor = tracerScene.objCollision(ray);
			graphics.displayPixel(r, c, pixelColor);
		}

	graphics.render();
	t = clock() - t;
	printf("Scene rendering time: %f ms\n", (float)(t));
}

int main(int argc, char **argv)
{
	tracerScene.build();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Ray Tracing!");
	glutReshapeFunc(winReshapeFunc);
	glutDisplayFunc(renderScene);
	glutMainLoop();
	return 0;
}