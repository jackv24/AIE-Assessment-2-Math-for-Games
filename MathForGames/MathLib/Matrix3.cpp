#include "Matrix3.h"

Matrix3::Matrix3()
{
}

Matrix3::~Matrix3()
{
}

Matrix3::operator float*()
{
	return *m_array;
}