#include "opengl_math_lib.h"

/************************************
 *           vector                 *
 ***********************************/

Vector3f::Vector3f()
{
	m[0]=0.0;
	m[1]=0.0;
	m[2]=0.0;
}
Vector3f::Vector3f(float _x, float _y, float _z)
{
	m[0] = _x;
	m[1] = _y;
	m[2] = _z;
}
Vector3f::Vector3f(const Vector3f & vec)
{
	m[0] = (vec.m)[0];
	m[1] = (vec.m)[1];
	m[2] = (vec.m)[2];
}
Vector3f Vector3f::operator+(const Vector3f &vec)
{
	Vector3f result;
	(result.m).[0] = m[0] + (vec.m)[0];
	(result.m).[1] = m[1] + (vec.m)[1];
	(result.m).[2] = m[2] + (vec.m)[2];
	return result;
}
float Vector3f::mod()
{
	return sqrt(m[0]*m[0]+m[1]*m[1]+m[2]*m[2]);
}
void Vector3f::scale(float s)
{
	m[0]*=s;
	m[1]*=s;
	m[2]*=s;
}
float Vector3f::dot(const Vector3f &vec)
{
	return m[0]*(vec.m)[0]+m[1]*(vec.m)[1]+m[2]*(vec.m)[2];
}
Vector3f Vector3f::cross(const Vector3f &vec)
{
	Vector3f result;
	(result.m)[0] = m[1]*(vec.m)[2]-m[2]*(vec.m)[1];
	(result.m)[1] = m[2]*(vec.m)[0]-m[0]*(vec.m)[2];
	(result.m)[1] = m[0]*(vec.m)[1]-m[1]*(vec.m)[0];
	return result;
}
Vector3f Vector3f::normalize(const Vector3f &vec)
{
	float sq_and = vec.mod();
	Vector3f result((vec.m)[0]/sq_and, (vec.m)[1]/sq_and, (vec.m)[2]/sq_and);
	return result;
}
