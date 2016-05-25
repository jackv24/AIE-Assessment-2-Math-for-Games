#pragma once

class Vector3
{
public:
	//Constructors
	Vector3();
	Vector3(float xVal, float yVal, float zVal);
	//Deconstructor
	~Vector3();

	//Operator overloads
	Vector3 operator + (const Vector3& other);
	Vector3 operator - (const Vector3& other);
	Vector3 operator * (const float& other);
	operator float*();

	//Public variables
	float x = 0;
	float y = 0;
	float z = 0;
};

//Operator overload outside class at it takes the class
Vector3 operator * (const float& lhs, const Vector3& rhs);