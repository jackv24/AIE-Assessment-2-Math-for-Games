#pragma once

class Matrix2
{
public:
	Matrix2();
	~Matrix2();

	operator float*();

private:
	float m_array[2][2];
};

