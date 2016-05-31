#pragma once

class Matrix4
{
public:
	Matrix4();
	~Matrix4();

	operator float*();

private:
	float m_array[4][4];
};

