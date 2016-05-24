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
	x += other.x;
	y += other.y;
}

Vector2 Vector2::operator - (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
}

Vector2 Vector2::operator * (const float& other)
{
	x *= other;
	y *= other;
}

Vector2::operator float*()
{
	float* array2 = new float[2];

	array2[0] = x;
	array2[1] = y;

	return array2;
}
