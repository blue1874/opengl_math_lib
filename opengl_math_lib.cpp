#include "opengl_math_lib.h"

/************************************
 *           vector                 *
 ***********************************/

Vec vec_new(float x = 0, float y = 0, float z = 0, float w = 0)
{
    Vec vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;
    return vec;
}

float vec_mod(Vec p)
{
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w);
}

void vec_copy(Vec &p1, Vec p2)
{
    p1.x = p2.x;
    p1.y = p2.y;
    p1.z = p2.z;
    p1.w = p2.w;
}

void vec_add(Vec &p1, Vec p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    p1.z += p2.z;
    p1.w += p2.w;
}

void vec_scale(Vec &p1, float scale)
{
    p1.x *= scale;
    p1.y *= scale;
    p1.z *= scale;
    p1.w *= scale;
}

float vec_dot(Vec p1, Vec p2)
{
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z + p1.w * p2.w;
}

void vec_cross(Vec &p1, Vec p2)
{
    
}

void vec_normalize(Vec &p)
{
    float mod = vec_mod(p);
    p.x /= mod;
    p.y /= mod;
    p.z /= mod;
    p.w /= mod;
}

void vec_delete(Vec);