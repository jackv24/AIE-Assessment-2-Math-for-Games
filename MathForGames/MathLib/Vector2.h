#pragma once
class Vector2
{
public:
	//Constructors
	Vector2();
	Vector2(float xVal, float yVal);
	~Vector2();

	//Operator overloads
	Vector2 operator + (const Vector2& other);
	Vector2 operator - (const Vector2& other);
	Vector2 operator * (const float& other);

	//Public variable
	float x = 0;
	float y = 0;
};

