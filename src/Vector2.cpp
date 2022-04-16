#include <Vector2.hpp>

#include <cmath>

Vector2::Vector2(double x, double y) : X(x), Y(y)
{
}

Vector2::Vector2() : X(0), Y(0)
{
}

Vector2::Vector2(Vector2 const& ref) : X(ref.X), Y(ref.Y)
{
}

Vector2 Vector2::Normalize() const
{
	double magn = Magnitude();
	if (magn == 0)
		throw InvalidNormalizeException();
	return *this / magn;
}

// Returns this Vector2 reflected on normal.
// Formula: r = v - 2(vn)n
Vector2 Vector2::Reflect(Vector2 const& normal) const
{
	return *this - (( (*this * normal) * 2)  * normal);
}

// Returns the length of the Vector2.
// Formula: √(xx + yy)
double Vector2::Magnitude() const
{
	return sqrt(pow(X, 2) + pow (Y, 2));
}

// Returns the dot product of this Vector2 with rhs.
// Formula: |a| * |b|
double Vector2::Dot(Vector2 const& rhs) const
{
	return (X * rhs.X) + (Y * rhs.Y);
}

bool operator==(Vector2 const& lhs, Vector2 const& rhs)
{
	return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

bool operator!=(Vector2 const& lhs, Vector2 const& rhs)
{
	return !(lhs == rhs);
}

Vector2 operator*(Vector2 const& lhs, Vector2 const& rhs)
{
	return Vector2(lhs.X * rhs.X, lhs.Y * rhs.Y);
}

Vector2 operator/(Vector2 const& lhs, Vector2 const& rhs)
{
	return Vector2(lhs.X / rhs.X, lhs.Y / rhs.Y);
}

Vector2 operator+(Vector2 const& lhs, Vector2 const& rhs)
{
	return Vector2(lhs.X + rhs.X, lhs.Y + rhs.Y);
}

Vector2 operator-(Vector2 const& lhs, Vector2 const& rhs)
{
	return Vector2(lhs.X - rhs.X, lhs.Y - rhs.Y);
}

Vector2 operator/(Vector2 const& lhs, double n)
{
	return Vector2(lhs.X / n, lhs.Y / n);
}

Vector2 operator*(Vector2 const& lhs, double n)
{
	return Vector2(lhs.X * n, lhs.Y * n);
}

Vector2 operator+(Vector2 const& lhs, double n)
{
	return Vector2(lhs.X + n, lhs.Y + n);
}

Vector2 operator-(Vector2 const& lhs, double n)
{
	return Vector2(lhs.X - n, lhs.Y - n);
}

std::ostream& operator<<(std::ostream& os, Vector2 const& ref)
{
	os << ref.X << ", " << ref.Y;
	return os;
}
