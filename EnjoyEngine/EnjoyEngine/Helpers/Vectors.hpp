#pragma once
#include <math.h>

template <typename T>
struct Vector2D {
	T x;
	T y;

	Vector2D<T>& operator =(Vector2D<T> b) {
		x = b.x;
		y = b.y;
		return *this;
	};

	Vector2D<T> operator -(Vector2D<T> b) {
		Vector2D<T> temp = *this;
		temp.x -= b.x;
		temp.y -= b.y;
		return temp;
	};

	Vector2D<T> operator +(Vector2D<T> b) {
		Vector2D<T> temp = *this;
		temp.x += b.x;
		temp.y += b.y;
		return temp;
	};

	Vector2D<T> operator *(float a) {
		Vector2D<T> temp = *this;
		temp.x *= a;
		temp.y *= a;
		return temp;
	};

	float magnitude() {
		return sqrtf((x*x) + (y*y));
	};

	Vector2D<T>& normalize() {
		float magnitude = this->magnitude();
		x = x / magnitude;
		y = y / magnitude;
		return *this;
	};

	Vector2D<T>& setMagnitude(float mag) {
		this->normalize();
		x *= mag;
		y *= mag;
		return *this;
	};

	T dot(Vector2D<T> b) {
		T dotProduct = (x * b.x) + (y * b.y);
		return dotProduct;
	};
};

template <typename T>
struct Vector3D {
	T x;
	T y;
	T z;

	Vector3D<T>& operator =(Vector3D<T> b) {
		x = b.x;
		y = b.y;
		z = b.z;
		return *this;
	};

	Vector3D<T> operator -(Vector3D<T> b) {
		Vector3D<T> temp = *this;
		temp.x -= b.x;
		temp.y -= b.y;
		temp.z -= b.z;
		return temp;
	};

	Vector3D<T> operator +(Vector3D<T> b) {
		Vector3D<T> temp = *this;
		temp.x += b.x;
		temp.y += b.y;
		temp.z += b.z;
		return temp;
	};

	Vector3D<T> operator *(float a) {
		Vector3D<T> temp = *this;
		temp.x *= a;
		temp.y *= a;
		temp.z *= a;
		return temp;
	};

	float magnitude() {
		return sqrtf((x*x) + (y*y) + (z*z));
	};

	Vector3D<T>& normalize() {
		float magnitude = this->magnitude();
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
		return *this;
	};

	Vector3D<T>& setMagnitude(float mag) {
		this->normalize();
		x *= mag;
		y *= mag;
		z *= mag;
		return *this;
	};

	T dot(Vector3D<T> b) {
		T dotProduct = (x * b.x) + (y * b.y) + (z * b.z);
		return dotProduct;
	};
};