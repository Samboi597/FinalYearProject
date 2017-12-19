#pragma once
class ViewPlane
{
public:
	ViewPlane();
	ViewPlane(const ViewPlane& vp);
	~ViewPlane();

	int hres; //horizontal image resolution
	int vres; //vertical image resolution
	float s; //pixel size
	float gamma; //gamma correction
	float invGamma; //inverse of gamma
	bool ifOutOfGamut;

	ViewPlane& operator=(const ViewPlane& rhs);
	void set_hres(const int h_res);
	void set_vres(const int v_res);
	void set_pixel_size(const float size);
	void set_gamma(const float g);
	void set_gamut_display(const bool show);
};

inline void ViewPlane::set_hres(const int h_res) 
{
	hres = h_res;
}

inline void ViewPlane::set_vres(const int v_res) 
{
	vres = v_res;
}

inline void ViewPlane::set_pixel_size(const float size) 
{
	s = size;
}

inline void ViewPlane::set_gamma(const float g) 
{
	gamma = g;
	invGamma = 1.0 / gamma;
}

inline void ViewPlane::set_gamut_display(const bool show) 
{
	ifOutOfGamut = show;
}
