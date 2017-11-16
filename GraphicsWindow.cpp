#include "GraphicsWindow.h"
#include "World.h"
#include "Maths.h"
#include "glut.h"
World scene;

void winReshapeFunc(GLint w, GLint h);

GraphicsWindow::GraphicsWindow() : gamma(1.0), invGamma(1.0), ifOutOfGamut(false)
{
	int totalCount = SCREEN_WIDTH * SCREEN_HEIGHT * 3;

	colourBuffer = new float[totalCount];

	for (int i = 0; i < totalCount; i++)
	{
		colourBuffer[i] = 0;
	}
}

GraphicsWindow::GraphicsWindow(const GraphicsWindow& vp) : gamma(vp.gamma), invGamma(vp.invGamma), ifOutOfGamut(vp.ifOutOfGamut)
{
	int totalCount = SCREEN_WIDTH * SCREEN_HEIGHT * 3;

	colourBuffer = new float[totalCount];

	for (int i = 0; i < totalCount; i++)
	{
		colourBuffer[i] = 0;
	}
}

GraphicsWindow::~GraphicsWindow()
{
	delete[] colourBuffer;
}

GraphicsWindow & GraphicsWindow::operator=(const GraphicsWindow & rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}

	gamma = rhs.gamma;
	invGamma = rhs.invGamma;
	ifOutOfGamut = rhs.ifOutOfGamut;
	return (*this);
}

void GraphicsWindow::displayPixel(const int row, const int column, const RGBColour & pixel_color)
{
	RGBColour mappedColour;

	if (ifOutOfGamut)
		mappedColour = clampToColour(pixel_color);
	else
		mappedColour = maxToOne(pixel_color);

	if (gamma != 1.0)
		mappedColour = mappedColour.powc(invGamma);

	//have to start from max y coordinate to convert to screen coordinates
	int x = column;
	int y = row;

	drawPixel(x, y, mappedColour);
}

RGBColour GraphicsWindow::maxToOne(const RGBColour & c)
{
	float maxValue = max(c.r, max(c.g, c.b));

	if (maxValue > 1.0)
		return c / maxValue;
	else
		return c;
}

RGBColour GraphicsWindow::clampToColour(const RGBColour & _c)
{
	RGBColour c(_c);
	if (_c.r > 1.0 || _c.g > 1.0 || _c.b > 1.0)
	{
		c.r = 1.0; c.g = 0.0; c.b = 0.0;
	}

	return (c);
}

void GraphicsWindow::drawPixel(int x, int y, const RGBColour & c)
{
	int start, end;

	start = -(1 / 2);
	end = (int)((1 / 2.0f) + 0.5);

	for (int i = start; i < end; i++)
	{
		for (int j = start; j < end; j++)
		{
			if ((x + j < 0) || (x + j >= SCREEN_WIDTH))
				continue;

			if ((y + i < 0) || (y + i >= SCREEN_HEIGHT))
				continue;

			colourBuffer[(((y + i)*SCREEN_WIDTH + (x + j)) * 3) + 0] = c.r;
			colourBuffer[(((y + i)*SCREEN_WIDTH + (x + j)) * 3) + 1] = c.g;
			colourBuffer[(((y + i)*SCREEN_WIDTH + (x + j)) * 3) + 2] = c.b;
		}
	}
}

void GraphicsWindow::render()
{
	// clear the back buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw the pixels onscreen
	glDrawPixels(SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_FLOAT, colourBuffer);

	// swap the buffers of the current window
	glutSwapBuffers();

	// clear out the buffer
	clear();
}

void GraphicsWindow::clear()
{
	memset(colourBuffer, 0, sizeof(float)*SCREEN_WIDTH*SCREEN_HEIGHT * 3);
}
