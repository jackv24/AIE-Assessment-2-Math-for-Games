#pragma once

#include "Vector3.h"

#define ORDER 3

class Matrix3
{
public:
	Matrix3();
	Matrix3(float c1r1, float c1r2, float c1r3,
		float c2r1, float c2r2, float c2r3,
		float c3r1, float c3r2, float c3r3);
	~Matrix3();

	operator float*();
	Matrix3 operator + (const Matrix3& other);
	Matrix3 operator - (const Matrix3& other);
	Matrix3 operator * (const Matrix3& other);
	Vector3 operator * (const Vector3& other);

	static Matrix3 CreateIdentity();
	Matrix3 GetTranspose();
	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

private:
	float m_array[ORDER][ORDER];
};

