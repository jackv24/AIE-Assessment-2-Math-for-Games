#include "Matrix3.h"
#include <math.h>

Matrix3::Matrix3()
{
	for (int c = 0; c < ORDER; c++)
		for (int r = 0; r < ORDER; r++)
			m_array[c][r] = 0;
}
Matrix3::Matrix3(float c1r1, float c1r2, float c1r3,
	float c2r1, float c2r2, float c2r3,
	float c3r1, float c3r2, float c3r3)
{
	//Matrix is column-major
	m_array[0][0] = c1r1;
	m_array[0][1] = c1r2;
	m_array[0][2] = c1r3;
	m_array[1][0] = c2r1;
	m_array[1][1] = c2r2;
	m_array[1][2] = c2r3;
	m_array[2][0] = c3r1;
	m_array[2][1] = c3r2;
	m_array[2][2] = c3r3;
}
Matrix3::~Matrix3()
{
}

Matrix3::operator float*()
{
	return *m_array;
}
Matrix3 Matrix3::operator + (const Matrix3& other)
{
	Matrix3 newMatrix;

	//Iterate through and add each value
	for (int c = 0; c < ORDER; c++)
		for (int r = 0; r < ORDER; r++)
			newMatrix.m_array[c][r] = m_array[c][r] + other.m_array[c][r];

	return newMatrix;
}
Matrix3 Matrix3::operator - (const Matrix3& other)
{
	Matrix3 newMatrix;

	//Iterate through and subtract each value
	for (int c = 0; c < ORDER; c++)
		for (int r = 0; r < ORDER; r++)
			newMatrix.m_array[c][r] = m_array[c][r] - other.m_array[c][r];

	return newMatrix;
}
Matrix3 Matrix3::operator * (const Matrix3& other)
{
	Matrix3 newMatrix;

	//Iterate through rows and columns
	for (int r = 0; r < ORDER; r++)
		for (int c = 0; c < ORDER; c++)		
			//For each row on left, go through columns on right
			for (int i = 0; i < ORDER; i++)
				newMatrix.m_array[c][r] += m_array[i][r] * other.m_array[c][i];

	return newMatrix;
}
Vector3 Matrix3::operator * (const Vector3& other)
{
	//turn vectors into arrays for matrix operations
	float vector[3] = { other.x, other.y, other.z };
	float newVector[3] = { 0, 0, 0 };

	//Iterate through rows and columns
	for (int c = 0; c < ORDER; c++)
		for (int r = 0; r < ORDER; r++)
			newVector[r] += m_array[c][r] * vector[c];

	//Return matrix vector as actual Vector
	return Vector3(newVector[0], newVector[1], newVector[2]);
}

Matrix3 Matrix3::CreateIdentity()
{
	Matrix3 identity(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1);

	return identity;
}
Matrix3 Matrix3::GetTranspose()
{
	Matrix3 transpose;

	//Swap rows and columns
	for (int c = 0; c < ORDER; c++)
		for (int r = 0; r < ORDER; r++)
			transpose.m_array[c][r] = m_array[r][c];

	return transpose;
}
void Matrix3::setRotateX(float angle)
{
	m_array[0][0] = 1;
	m_array[0][1] = 0;
	m_array[0][2] = 0;
	m_array[1][0] = 0;
	m_array[1][1] = cosf(angle);
	m_array[1][2] = sinf(angle);
	m_array[2][0] = 0;
	m_array[2][1] = -sinf(angle);
	m_array[2][2] = cosf(angle);
}
void Matrix3::setRotateY(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = 0;
	m_array[0][2] = -sinf(angle);
	m_array[1][0] = 0;
	m_array[1][1] = 1;
	m_array[1][2] = 0;
	m_array[2][0] = sinf(angle);
	m_array[2][1] = 0;
	m_array[2][2] = cosf(angle);
}
void Matrix3::setRotateZ(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = sinf(angle);
	m_array[0][2] = 0;
	m_array[1][0] = -sinf(angle);
	m_array[1][1] = cosf(angle);
	m_array[1][2] = 0;
	m_array[2][0] = 0;
	m_array[2][1] = 0;
	m_array[2][2] = 1;
}