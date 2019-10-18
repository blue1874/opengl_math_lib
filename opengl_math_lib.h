#ifndef OPENGL_MATH_LIB_H
#define OPENGL_MATH_LIB_H

#include <cstdio>
#include <cmath>

/************************************
 *            type                  *
 ***********************************/
/*typedef struct
{
	float x;
	float y;
	float z;
}Vec3;*/

class Vector4f
{
private:
	float x;
	float y;
	float z;
	float w;

public:
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

class Mat4f
{
private:
	float m[4][4];
public:
	Mat4f(/* args */);
	Mat4f mat_add(Mat, Mat);
	void mat_mult_mat(Mat, Mat);
	void mat_print(Mat);
	~Mat4f();
};

Mat4f::Mat4f(/* args */)
{
}

Mat4f::~Mat4f()
{
}

typedef struct
{
	float x;
	float y;
	float z;
	float w;
} Vec;

typedef struct
{
	Vec row1;
	Vec row2;
	Vec row3;
	Vec row4;
	Vec col1;
	Vec col2;
	Vec col3;
	Vec col4;
} Mat;

typedef Mat Tr;
typedef Mat Cam;

/************************************
 *            utils                 *
 ***********************************/

float to_radian(float);

/************************************
 *           vector                 *
 ***********************************/

Vec vec_new(float, float, float, float);
float vec_mod(Vec);
void vec_copy(Vec, Vec);
void vec_add(Vec, Vec);
void vec_scale(Vec, float);
float vec_dot(Vec, Vec);
void vec_cross(Vec, Vec);
void vec_normalize(Vec);
void vec_delete(Vec);

/************************************
 *           matrix                 *
 ***********************************/

Mat mat_new();
void mat_copy(Mat, Mat);
void mat_add(Mat, Mat);
void mat_mult_mat(Mat, Mat);
void mat_print(Mat);
void mat_delete(Mat);

/************************************
 *           transform              *
 ***********************************/

Tr tr_new();
void tr_trans(Tr, float, float, float);
void tr_rotate(Tr, float, float, float);
void tr_scale(Tr, float, float, float);
void tr_delete(Tr);

/************************************
 *           projection             *
 ***********************************/

Mat ortho_proj(float, float, float, float, float, float);
Mat persp_proj(float, float, float, float);

/************************************
 *            camera                *
 ***********************************/

Cam look_at(Vec, Vec, Vec);

#endif