#include "Vector2.h"

//Constructors
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float xVal, float yVal)
{
	x = xVal;
	y = yVal;
}
//Deconstructor
Vector2::~Vector2()
{
	
}


//Operator overloads
Vector2 Vector2::operator + (const Vector2& other)
{
	Vector2 newVector;

	newVector.x = x + other.x;
	newVector.y = y + other.y;

	return newVector;
}

Vector2 Vector2::operator - (const Vector2& other)
{
	Vector2 newVector;

	newVector.x = x - other.x;
	newVector.y = y - other.y;

	return newVector;
}

Vector2 Vector2::operator * (const float& other)
{
	Vector2 newVector;

	newVector.x = x * other;
	newVector.y = y * other;

	return newVector;
}

Vector2 operator * (const float& lhs, const Vector2& rhs)
{
	Vector2 newVector;

	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;

	return newVector;
}

Vector2::operator float*()
{
	//Return vector values as array
	float col[2] = { x, y };
	return col;
}
