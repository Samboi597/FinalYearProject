// 2017-18 Samuel Mounter
// All rights reserved

#pragma once

class Matrix
{
public:
	Matrix();
	Matrix(const Matrix& mat); 
	~Matrix();

	double m[4][4];
	Matrix& operator= (const Matrix& rightSide);
	Matrix operator* (const Matrix& matrix) const;
	Matrix operator/ (const double d);
	void setIdentity();
};
