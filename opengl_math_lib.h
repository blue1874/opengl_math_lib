#include <stdlib.h>
#include <math.h>

/************************************
 *            type                  *
 ***********************************/
/*typedef struct
{
	float x;
	float y;
	float z;
}Vec3;*/

typedef struct
{
	float x;
	float y;
	float z;
	float w;
}Vec;

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
}Mat;

typedef Mat Tr;
typedef Mat Cam;

/************************************
 *            utils                 *
 ***********************************/

float to_radian(float);

/************************************
 *           vector                 *
 ***********************************/

Vec vec_new();
float vec_mod(Vec);
void vec_copy(Vec, Vec);
void vec_add(Vec, Vec);
void vec_scale(Vec, float);
void vec_dot(Vec, Vec);
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
