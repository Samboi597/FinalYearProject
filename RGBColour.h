#pragma once
class RGBColour
{
public:
	RGBColour();
	RGBColour(float c);
	RGBColour(float _r, float _g, float _b);
	RGBColour(const RGBColour& c);
	~RGBColour();

	float r, g, b;
	RGBColour& operator= (const RGBColour& rhs);
	RGBColour operator+ (const RGBColour& c) const;
	RGBColour& operator+= (const RGBColour& c);
	RGBColour operator* (const float a) const;
	RGBColour& operator*= (const float a);
	RGBColour operator/ (const float a) const;
	RGBColour& operator/= (const float a);
	RGBColour operator* (const RGBColour& c) const;
	bool operator== (const RGBColour& c) const;
	RGBColour powc(double p) const;
	float average() const;
};

inline RGBColour RGBColour::operator+ (const RGBColour& c) const //add two colours
{
	return (RGBColour(r + c.r, g + c.g, b + c.b));
}

inline RGBColour& RGBColour::operator+= (const RGBColour& c) //compund addition
{
	r += c.r; g += c.g; b += c.b;
	return (*this);
}

inline RGBColour RGBColour::operator* (const float a) const //multiply by float on right
{
	return (RGBColour(r * a, g * a, b * a));
}

inline RGBColour& RGBColour::operator*= (const float a) //compund multiplication
{
	r *= a; g *= a; b *= a;
	return (*this);
}

inline RGBColour RGBColour::operator/ (const float a) const //division by float
{
	return (RGBColour(r / a, g / a, b / a));
}

inline RGBColour& RGBColour::operator/= (const float a) //compound division
{
	r /= a; g /= a; b /= a;
	return (*this);
}

inline RGBColour RGBColour::operator* (const RGBColour& c) const //component multiplication
{
	return (RGBColour(r * c.r, g * c.g, b * c.b));
}

inline bool RGBColour::operator== (const RGBColour& c) const //are they equal
{
	return (r == c.r && g == c.g && b == c.b);
}

inline float RGBColour::average(void) const //average of three components
{
	return (0.333333333333 * (r + g + b));
}

RGBColour operator* (const float a, const RGBColour& c);

inline RGBColour operator* (const float a, const RGBColour& c) //multiply by float on left
{
	return (RGBColour(a * c.r, a * c.g, a * c.b));
}

