#pragma once

#include <iostream>

class Vector3
{
public:
	Vector3();
	Vector3(Vector3 const& ref);
	Vector3(double x, double y, double z);

	double X;
	double Y;
	double Z;

public:
	Vector3 Cross(Vector3 const& rhs) const;
	Vector3 Normalize() const;
	Vector3 Reflect(Vector3 const& normal) const;
	double Magnitude() const;
	double Dot(Vector3 const& rhs) const;

	class InvalidNormalizeException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Exception: Zero Vector3 cannot be normalized.";
		}
	};

};


bool operator==(Vector3 const& lhs, Vector3 const& rhs);
bool operator!=(Vector3 const& lhs, Vector3 const& rhs);

Vector3 operator*(Vector3 const& lhs, Vector3 const& rhs);
Vector3 operator/(Vector3 const& lhs, Vector3 const& rhs);
Vector3 operator+(Vector3 const& lhs, Vector3 const& rhs);
Vector3 operator-(Vector3 const& lhs, Vector3 const& rhs);

Vector3 operator/(Vector3 const& lhs, double n);
Vector3 operator*(Vector3 const& lhs, double n);
Vector3 operator+(Vector3 const& lhs, double n);
Vector3 operator-(Vector3 const& lhs, double n);

std::ostream& operator<<(std::ostream& os, Vector3 const& ref);