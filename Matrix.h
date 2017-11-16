#pragma once

class Matrix
{
public:
	Matrix();
	Matrix(const Matrix& mat); 
	~Matrix();

	double m[4][4];
	Matrix& operator= (const Matrix& rhs);
	Matrix operator* (const Matrix& mat) const;
	Matrix operator/ (const double d);
	void setIdentity();
};
