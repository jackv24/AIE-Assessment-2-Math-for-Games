#include "Vector2.h"

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
