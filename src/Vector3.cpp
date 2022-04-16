#include <Vector3.hpp>
#include <cmath>

Vector3::Vector3(double x, double y, double z) : X(x), Y(y), Z(z)
{
}

Vector3::Vector3() : X(0), Y(0), Z(0)
{
}

Vector3::Vector3(Vector3 const& ref) : X(ref.X), Y(ref.Y), Z(ref.Z)
{
}

// Returns the cross product of this Vector3 and rhs.
Vector3 Vector3::Cross(Vector3 const& rhs) const
{
	return Vector3((Y * rhs.Z) - (Z * rhs.Y),
				-((X * rhs.Z) - (Z * rhs.X)),
				  (X * rhs.Y) - (Y * rhs.X));
}

Vector3 Vector3::Normalize() const
{
	double magn = Magnitude();
	if (magn == 0)
		throw InvalidNormalizeException();
	return *this / magn;
}

// Returns this Vector3 reflected on normal.
// Formula: r = v - 2(vn)n
Vector3 Vector3::Reflect(Vector3 const& normal) const
{
	return *this - (( (*this * normal) * 2)  * normal);
}

// Returns the length of the Vector3.
// Formula: √(xx + yy + zz)
double Vector3::Magnitude() const
{
	return sqrt(pow(X, 2) + pow (Y, 2) + pow(Z, 2));
}

// Returns the dot product of this Vector3 with rhs.
// Formula: |a| * |b|
double Vector3::Dot(Vector3 const& rhs) const
{
	return (X * rhs.X) + (Y * rhs.Y) + (Z * rhs.Z);
}

bool operator==(Vector3 const& lhs, Vector3 const& rhs)
{
	return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

bool operator!=(Vector3 const& lhs, Vector3 const& rhs)
{
	return !(lhs == rhs);
}

Vector3 operator*(Vector3 const& lhs, Vector3 const& rhs)
{
	return Vector3(lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z);
}

Vector3 operator/(Vector3 const& lhs, Vector3 const& rhs)
{
	return Vector3(lhs.X / rhs.X, lhs.Y / rhs.Y, lhs.Z / rhs.Z);
}

Vector3 operator+(Vector3 const& lhs, Vector3 const& rhs)
{
	return Vector3(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
}

Vector3 operator-(Vector3 const& lhs, Vector3 const& rhs)
{
	return Vector3(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z);
}

Vector3 operator/(Vector3 const& lhs, double n)
{
	return Vector3(lhs.X / n, lhs.Y / n, lhs.Z / n);
}

Vector3 operator*(Vector3 const& lhs, double n)
{
	return Vector3(lhs.X * n, lhs.Y * n, lhs.Z * n);
}

Vector3 operator+(Vector3 const& lhs, double n)
{
	return Vector3(lhs.X + n, lhs.Y + n, lhs.Z + n);
}

Vector3 operator-(Vector3 const& lhs, double n)
{
	return Vector3(lhs.X - n, lhs.Y - n, lhs.Z - n);
}

std::ostream& operator<<(std::ostream& os, Vector3 const& ref)
{
	os << ref.X << ", " << ref.Y << ", " << ref.Z;
	return os;
}
