#include "Matrix4.h"

Matrix4::Matrix4()
{
}

Matrix4::~Matrix4()
{
}

Matrix4::operator float*()
{
	return *m_array;
}