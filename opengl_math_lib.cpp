#include "opengl_math_lib.h"

/************************************
 *           vector                 *
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
                 m[0][0] = x0; m[0][0] = y0; m[0][0] = z0; m[0][0] = w0; 
                 m[0][0] = x1; m[0][0] = y1; m[0][0] = z1; m[0][0] = w1; 
                 m[0][0] = x2; m[0][0] = y2; m[0][0] = z2; m[0][0] = w2; 
                 m[0][0] = x3; m[0][0] = y3; m[0][0] = z3; m[0][0] = w3;
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

void Mat4f::print(const Mat4f &x)
{
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f\t", x.m[i][j]);
        }
        printf("\n");
    }    
}

Mat4f::~Mat4f()
{}