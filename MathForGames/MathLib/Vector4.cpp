#include "Vector4.h"

//Constructors
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float xVal, float yVal, float zVal, float wVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
	w = wVal;
}
//Deconstructor
Vector4::~Vector4()
{

}


//Operator overloads
Vector4 Vector4::operator + (const Vector4& other)
{
	Vector4 newVector;

	newVector.x = x + other.x;
	newVector.y = y + other.y;
	newVector.z = z + other.z;
	newVector.w = w + other.w;

	return newVector;
}

Vector4 Vector4::operator - (const Vector4& other)
{
	Vector4 newVector;

	newVector.x = x - other.x;
	newVector.y = y - other.y;
	newVector.z = z - other.z;
	newVector.w = w - other.w;

	return newVector;
}

Vector4 Vector4::operator * (const float& other)
{
	Vector4 newVector;

	newVector.x = x * other;
	newVector.y = x * other;
	newVector.z = z * other;
	newVector.w = w * other;

	return newVector;
}

Vector4 operator * (const float& lhs, const Vector4& rhs)
{
	Vector4 newVector;

	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;
	newVector.z = lhs * rhs.z;
	newVector.w = lhs * rhs.w;

	return newVector;
}

Vector4::operator float*()
{
	//Return vector values as array
	float col[4] = { x, y, z, w };
	return col;
}
