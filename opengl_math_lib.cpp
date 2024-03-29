#include "opengl_math_lib.h"

/************************************
 *             utils                *
 ***********************************/

float to_radian(float ang)
{
	return ang*3.1415926535/180.f;
}

/************************************
 *           matrix                 *
 ***********************************/

Mat4f::Mat4f()
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = 0.0;
        }
        
    }
}

Mat4f::Mat4f(float x)
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = i == j ? x : 0;
        }
    }    
}

Mat4f::Mat4f(float x0, float y0, float z0, float w0, 
			 float x1, float y1, float z1, float w1, 
			 float x2, float y2, float z2, float w2, 
			 float x3, float y3, float z3, float w3)
             {
                 m[0][0] = x0; m[0][1] = y0; m[0][2] = z0; m[0][3] = w0; 
                 m[1][0] = x1; m[1][1] = y1; m[1][2] = z1; m[1][3] = w1; 
                 m[2][0] = x2; m[2][1] = y2; m[2][2] = z2; m[2][3] = w2; 
                 m[3][0] = x3; m[3][1] = y3; m[3][2] = z3; m[3][3] = w3;
             }
             
Mat4f::Mat4f(const Mat4f &x)
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = x.m[i][j];
        }
    }        
}

Mat4f Mat4f::operator+(const Mat4f &x)
{
    Mat4f y(0);
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            y.m[i][j] = m[i][j] + x.m[i][j];
        }
    }
    return y;     
}

Mat4f Mat4f::operator*(const Mat4f &x)
{
    Mat4f y(0);
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                y.m[i][j] += m[i][k] * x.m[k][j];
            }            
        }
    }
    return y;    
}

Vector4f Mat4f::operator*(const Vector4f &x)
{
    Vector4f y;
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            y.m[i] += m[i][j] * x.m[j];           
        }
    }
    return y;     
}

void Mat4f::print()
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");    
}

Mat4f::~Mat4f()
{}


/************************************
 *           vector3f               *
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
	(result.m)[0] = m[0] + (vec.m)[0];
	(result.m)[1] = m[1] + (vec.m)[1];
	(result.m)[2] = m[2] + (vec.m)[2];
	return result;
}
float Vector3f::mod() const
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
Vector3f Vector3f::normalize()
{
	float sq_and = this->mod();
	Vector3f result(m[0]/sq_and, m[1]/sq_and, m[2]/sq_and);
	return result;
}

void Vector3f::print()
{
    printf("%f %f %f\n", m[0], m[1], m[2]);
    printf("\n");
}


/************************************
 *           vector4f               *
 ***********************************/

Vector4f::Vector4f()
{
	m[0]=0.0;
	m[1]=0.0;
	m[2]=0.0;
    m[3]=0.0;
}
Vector4f::Vector4f(float _x, float _y, float _z, float _w)
{
	m[0] = _x;
	m[1] = _y;
	m[2] = _z;
    m[3] = _w;
}
Vector4f::Vector4f(const Vector4f & vec)
{
	m[0] = (vec.m)[0];
	m[1] = (vec.m)[1];
	m[2] = (vec.m)[2];
    m[3] = (vec.m)[3];
}
Vector4f Vector4f::operator+(const Vector4f &vec)
{
	Vector4f result;
	(result.m)[0] = m[0] + (vec.m)[0];
	(result.m)[1] = m[1] + (vec.m)[1];
	(result.m)[2] = m[2] + (vec.m)[2];
    (result.m)[3] = m[3] + (vec.m)[3];
	return result;
}
float Vector4f::mod() const
{
	return sqrt(m[0]*m[0]+m[1]*m[1]+m[2]*m[2]+m[3]*m[3]);
}
void Vector4f::print()
{
    printf("%f %f %f %f\n", m[0], m[1], m[2], m[3]);
    printf("\n");
}

/************************************
 *           tranform               *
 ***********************************/

Mat4f tr_translate(const Mat4f &mat, const Vector3f &vec)
{
	Mat4f result(mat);
	result.m[3][0]+=vec.m[0];
	result.m[3][1]+=vec.m[1];
	result.m[3][2]+=vec.m[2];
	return result;
}

Mat4f tr_rotate(const Mat4f &mat, float theta, const Vector3f &vec)
{
	float c=cos(to_radian(theta));
	float s=sin(to_radian(theta));
	
	float rx=vec.m[0];
	float ry=vec.m[1];
	float rz=vec.m[2];

	Mat4f tmp;

	tmp.m[0][0]=c+rx*rx*(1.0f-c);
	tmp.m[1][0]=rx*ry*(1.0f-c)+rz*s;
	tmp.m[2][0]=rz*rx*(1.0f-c)-ry*s;
	tmp.m[0][1]=rx*ry*(1.0f-c)-rz*s;
	tmp.m[1][1]=c+ry*ry*(1.0f-c);
	tmp.m[2][1]=rz*ry*(1.0f-c)+rx*s;
	tmp.m[0][2]=rx*rz*(1.0f-c)+ry*s;
	tmp.m[1][2]=ry*rz*(1.0f-c)-rx*s;
	tmp.m[2][2]=c+rz*rz*(1.0f-c);
	
	Mat4f result;

	result = tmp * mat;
	result.m[0][3]=mat.m[0][3];
	result.m[1][3]=mat.m[1][3];
	result.m[2][3]=mat.m[2][3];
	result.m[3][3]=1.0;

	return result;
}

Mat4f tr_scale(const Mat4f &mat, const Vector3f &vec)
{
	Mat4f result(mat);
	result.m[0][0]*=vec.m[0];
	result.m[1][1]*=vec.m[1];
	result.m[2][2]*=vec.m[2];
	return result;
}

/************************************
 *           projection             *
 ***********************************/

Mat4f proj_ortho(float left, float right, float bottom, float top, float near, float far)
{
	Mat4f result;

	result.m[0][0]=2.0f/(right-left);
	result.m[1][1]=2.0f/(top-bottom);
	result.m[2][2]=2.0f/(far-near);

	result.m[0][3]=-(right+left)/(right-left);
	result.m[1][3]=-(top+bottom)/(top-bottom);
	result.m[2][3]=(far+near)/(far-near);

	result.m[3][3]=1.0f;

	return result;
}

Mat4f proj_persp(float fov, float aspect, float near, float far)
{
	Mat4f result;
	
	float t = tan(to_radian(fov)*0.5);

	result.m[0][0]=1.0/(t*aspect);
	result.m[1][1]=1.0/t;
	result.m[2][2]=(far+near)/(near-far);
	result.m[2][3]=(2.0f*far*near)/(near-far);
	result.m[3][2]=-1.0f;

	return result;
}
