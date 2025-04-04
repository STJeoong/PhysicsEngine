#pragma once

class Matrix22;
class Vector2D
{
public:
	static float dot(const Vector2D& a, const Vector2D& b);
	static float cross(const Vector2D& a, const Vector2D& b);
	static Vector2D cross(const Vector2D& v, float z);
	static Vector2D cross(float z, const Vector2D& v);

	Vector2D() = default;
	Vector2D(float x, float y);
	float len() const;
	// for performance
	float squaredLen() const;
	// normalize this vector.
	void normalize();
	// get normarlized vector.
	Vector2D normalized() const;
	void rotate(const Vector2D& origin, float radian);
	void rotate(const Vector2D& origin, const Matrix22& mat);
	Vector2D operator*(float val) const;
	Vector2D& operator*=(float val);
	Vector2D operator+(const Vector2D& obj) const;
	Vector2D operator-(const Vector2D& obj) const;
	Vector2D& operator+=(const Vector2D& obj);
	Vector2D& operator-=(const Vector2D& obj);
	bool operator==(const Vector2D& obj) const;
	float x() const { return _x; }
	float y() const { return _y; }
	void x(float val) { _x = val; }
	void y(float val) { _y = val; }
private:
	float _x = 0.0f;
	float _y = 0.0f;
};

Vector2D operator*(float val, const Vector2D& v);
using Point2D = Vector2D;