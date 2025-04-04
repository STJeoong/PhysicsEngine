#pragma once
#include "Vector2D.h"
#include "Matrix22.h"
class Transform
{
public:
	Transform() {}
	Transform(const Point2D& p, float radian) : _pos(p), _rot(radian) {}
	void set(const Point2D& p, float radian) { _pos = p; _rot.set(radian); }
	const Point2D& position() const { return _pos; }
	// equals to position(). use this when you want to interpret _pos as displacement.
	const Vector2D& displacement() const { return _pos; }
	const Matrix22& rotation() const { return _rot; }
	void position(const Point2D& pos) { _pos = pos; }
	void displacement(const Vector2D& vec) { _pos = vec; }
	void rotation(const Matrix22& mat) { _rot = mat; }
	void move(const Vector2D& v) { _pos += v; }
	void rotate(float radian) { Matrix22 mat{ radian }; _rot *= mat; }
	void rotate(const Matrix22& mat) { _rot *= mat; }
	Transform& operator+=(const Transform& obj) { _pos += obj._pos; _rot *= obj._rot; return *this; }
	Transform operator-(const Transform& obj) { return {_pos - obj._pos, _rot.radian() - obj._rot.radian()}; }
private:

	Point2D _pos;
	Matrix22 _rot;
};

using Motion = Transform; // for express motion. if you want to express object's state, you can just use Transform.