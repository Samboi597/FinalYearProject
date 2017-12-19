#include "Matrix.h"

Matrix::Matrix() //constructor
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++) 
		{
			if (x == y)
			{
				m[x][y] = 1.0;
			}
			else
			{
				m[x][y] = 0.0;
			}
		}
	}
}

Matrix::Matrix(const Matrix& mat) //copy constructor
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			m[x][y] = mat.m[x][y];
		}
	}
}

Matrix::~Matrix() {} //destructor

Matrix & Matrix::operator=(const Matrix & rightSide) //assignment operator
{
	if (this == &rightSide)
	{
		return (*this);
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			m[x][y] = rightSide.m[x][y];
		}
	}

	return (*this);
}

Matrix Matrix::operator*(const Matrix & matrix) const //multiplication operator
{
	Matrix product;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			double sum = 0.0;

			for (int j = 0; j < 4; j++)
			{
				sum += m[x][j] * matrix.m[j][y];
			}
			product.m[x][y] = sum;
		}
	}
	return (product);
}

Matrix Matrix::operator/(const double d) //division operator (by a double)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			m[x][y] /= d;
		}
	}
	return (*this);
}

void Matrix::setIdentity() //set to identity matrix
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (x == y)
			{
				m[x][y] = 1.0;
			}
			else
			{
				m[x][y] = 0.0;
			}
		}
	}
}
