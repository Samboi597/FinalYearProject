// 2017-18 Samuel Mounter
// All rights reserved

#pragma once

inline double
max(double x0, double x1);

inline double
max(double x0, double x1)
{
	if (x0 > x1)
		return x0;
	else
		return x1;
}

inline double
min(double x0, double x1);

inline double
min(double x0, double x1)
{
	if (x0 < x1)
		return x0;
	else
		return x1;
}
