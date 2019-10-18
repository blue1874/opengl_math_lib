#ifndef OPENGL_MATH_LIB_H
#define OPENGL_MATH_LIB_H

#include <cstdio>
#include <cmath>

/************************************
 *            type                  *
 ***********************************/


/************************************
 *           vector                 *
 ***********************************/
class Vector4f
{
public:
	float x, y, z, w;
	Vector4f(float, float, float, float);
	Vector4f(const Vector4f &);
	Vector4f operator+(const Vector4f &);
	float mod(const Vector4f &);
	void scale(float);
	float dot(const Vector4f &);
	Vector4f cross(const Vector4f &);
	Vector4f normalize(const Vector4f &);
	~Vector4f();
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
	void print(const Mat4f &);
	~Mat4f();
};


/************************************
 *            utils                 *
 ***********************************/

float to_radian(float);
/************************************
 *           transform              *
 ***********************************/


/************************************
 *           projection             *
 ***********************************/


/************************************
 *            camera                *
 ***********************************/


#endif