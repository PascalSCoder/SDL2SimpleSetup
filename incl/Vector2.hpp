#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2();
	Vector2(Vector2 const& ref);
	Vector2(double x, double y);

	double X;
	double Y;

public:
	Vector2 Cross(Vector2 const& rhs) const;
	Vector2 Normalize() const;
	Vector2 Reflect(Vector2 const& normal) const;
	double Magnitude() const;
	double Dot(Vector2 const& rhs) const;

	class InvalidNormalizeException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Exception: Zero vector cannot be normalized.";
		}
	};

};


bool operator==(Vector2 const& lhs, Vector2 const& rhs);
bool operator!=(Vector2 const& lhs, Vector2 const& rhs);

Vector2 operator*(Vector2 const& lhs, Vector2 const& rhs);
Vector2 operator/(Vector2 const& lhs, Vector2 const& rhs);
Vector2 operator+(Vector2 const& lhs, Vector2 const& rhs);
Vector2 operator-(Vector2 const& lhs, Vector2 const& rhs);

Vector2 operator/(Vector2 const& lhs, double n);
Vector2 operator*(Vector2 const& lhs, double n);
Vector2 operator+(Vector2 const& lhs, double n);
Vector2 operator-(Vector2 const& lhs, double n);

std::ostream& operator<<(std::ostream& os, Vector2 const& ref);