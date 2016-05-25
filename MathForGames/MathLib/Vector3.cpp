#include "Vector3.h"

//Constructors
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float xVal, float yVal, float zVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
}
//Deconstructor
Vector3::~Vector3()
{

}


//Operator overloads
Vector3 Vector3::operator + (const Vector3& other)
{
	Vector3 newVector;

	newVector.x = x + other.x;
	newVector.y = y + other.y;
	newVector.z = z + other.z;

	return newVector;
}

Vector3 Vector3::operator - (const Vector3& other)
{
	Vector3 newVector;

	newVector.x = x - other.x;
	newVector.y = y - other.y;
	newVector.z = z - other.z;

	return newVector;
}

Vector3 Vector3::operator * (const float& other)
{
	Vector3 newVector;

	newVector.x = x * other;
	newVector.y = x * other;
	newVector.z = z * other;

	return newVector;
}

Vector3 operator * (const float& lhs, const Vector3& rhs)
{
	Vector3 newVector;

	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;
	newVector.z = lhs * rhs.z;

	return newVector;
}

Vector3::operator float*()
{
	//Return vector values as array
	float col[3] = { x, y, x };
	return col;
}
