#include "Matrix2.h"

Matrix2::Matrix2()
{
}

Matrix2::~Matrix2()
{
}

Matrix2::operator float*()
{
	return *m_array;
}