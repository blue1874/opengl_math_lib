#ifndef OPENGL_MATH_LIB_H
#define OPENGL_MATH_LIB_H

#include <cstdio>
#include <cmath>

/************************************
 *            type                  *
 ***********************************/

class Vector3f
{
public:
	float m[3];
	Vector3f();
	Vector3f(float, float, float);
	Vector3f(const Vector3f &);
	Vector3f operator+(const Vector3f &);
	float mod() const;
	void scale(float);
	float dot(const Vector3f &);
	Vector3f cross(const Vector3f &);
	Vector3f normalize();
	void print();
};

class Vector4f
{
public:
	float m[4];
	Vector4f();
	Vector4f(float, float, float, float);
	Vector4f(const Vector4f &);
	Vector4f operator+(const Vector4f &);
	float mod() const;
	void print();
};

/************************************
 *           matrix                 *
 ***********************************/

class Mat4f
{
public:
	float m[4][4];
	Mat4f();
	Mat4f(float);
	Mat4f(float, float, float, float, 
			float, float, float, float, 
			float, float, float, float, 
			float, float, float, float);
	Mat4f(const Mat4f &);
	Mat4f operator+(const Mat4f &);
	Mat4f operator*(const Mat4f &);
	Vector4f operator*(const Vector4f &);
	void print();
	~Mat4f();
};


/************************************
 *            utils                 *
 ***********************************/

float to_radian(float);

/************************************
 *           transform              *
 ***********************************/

Mat4f tr_translate(const Mat4f &, const Vector3f &);
Mat4f tr_rotate(const Mat4f &, float, const Vector3f &);
Mat4f tr_scale(const Mat4f &, const Vector3f &);

/************************************
 *           projection             *
 ***********************************/


/************************************
 *            camera                *
 ***********************************/


#endif
