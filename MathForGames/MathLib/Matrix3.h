#pragma once

class Matrix3
{
public:
	Matrix3();
	~Matrix3();

	operator float*();

private:
	float m_array[3][3];
};

