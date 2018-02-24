// 2017-18 Samuel Mounter
// All rights reserved

#pragma once
#include "RGBColour.h"
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

class GraphicsWindow
{
public:
	float* colourBuffer;

public:
	GraphicsWindow();
	GraphicsWindow(const GraphicsWindow& vp);
	~GraphicsWindow();

	GraphicsWindow& operator=(const GraphicsWindow& rhs);
	void displayPixel(const int row, const int column, const RGBColour & pixel_color);
	RGBColour maxToOne(const RGBColour & c);
	void drawPixel(int x, int y, const RGBColour &c);
	void render();
	void clear();
};