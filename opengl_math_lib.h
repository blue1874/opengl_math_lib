#include <stdlib.h>
#include <math.h>

/************************************
 *            type                  *
 ***********************************/
typedef struct
{
	float x;
	float y;
	float z;
}Vec3;

typedef struct
{
	float x;
	float y;
	float z;
	float w;
}Vec4;

typedef struct
{
	vec4 row1;
	vec4 row2;
	vec4 row3;
	vec4 row4;
	vec4 col1;
	vec4 col2;
	vec4 col3;
	vec4 col4;
}Mat4;

typedef Mat4 Tr;
typedef Mat4 Cam;

/************************************
 *            utils                 *
 ***********************************/

float to_radian(float);

/************************************
 *           vector                 *
 ***********************************/

Vec3 vec3_new();
float vec3_mod(Vec3);
void vec3_copy(Vec3, Vec3);
void vec3_add(Vec3, Vec3);
void vec3_scale(Vec3, float);
void vec3_dot(Vec3, Vec3);
void vec3_cross(Vec3, Vec3);
void vec3_normalize(Vec3);
void vec3_delete(Vec3);

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

Cam look_at(Vec3, Vec3, Vec3);
