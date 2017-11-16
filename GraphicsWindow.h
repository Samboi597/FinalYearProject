#pragma once
#include "RGBColour.h"
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

class GraphicsWindow
{
public:
	float gamma; //gamma correction
	float invGamma; //inverse of gamma
	bool ifOutOfGamut;
	float* colourBuffer;

public:
	GraphicsWindow();
	GraphicsWindow(const GraphicsWindow& vp);
	~GraphicsWindow();

	GraphicsWindow& operator=(const GraphicsWindow& rhs);
	void setGamma(const float g);
	void setGamutDisplay(const bool show);
	void displayPixel(const int row, const int column, const RGBColour & pixel_color);
	RGBColour maxToOne(const RGBColour & c);
	RGBColour clampToColour(const RGBColour & _c);
	void drawPixel(int x, int y, const RGBColour &c);
	void render();
	void clear();
};

inline void GraphicsWindow::setGamma(const float g)
{
	gamma = g;
	invGamma = 1.0 / gamma;
}

inline void GraphicsWindow::setGamutDisplay(const bool show)
{
	ifOutOfGamut = show;
}