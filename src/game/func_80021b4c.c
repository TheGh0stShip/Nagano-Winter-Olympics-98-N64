typedef struct Camera
{
  unsigned char mode;
  unsigned char pad1[7];
  float angle;
  float x;
  float y;
  float z;
  float ex;
  float ey;
  float ez;
  float ax;
  float ay;
  float az;
  float tx;
  float ty;
  float tz;
} Camera;
extern void func_8004E7E0(float mf[4][4], float a, float x, float y, float z);
extern void func_80059410(float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz);
extern void func_80022E64(Camera *cam);
extern double D_8007FA68;
void func_80021B4C(Camera *cam)
{
  int q;
  float p[3];
  float o[3];
  float sum;
  int z;
  unsigned short i;
  float m[4][4];
  p[0] = cam->x;
  p[1] = cam->y;
  p[2] = cam->z;
  func_8004E7E0(m, cam->angle, cam->ax, cam->ay, cam->az);
  func_80059410(m, p[0], p[1], p[2], &o[0], &o[1], &o[2]);
  sum = 0.0f;
  if (10 == cam->mode)
  {
    i = 0; do
    {
      sum += o[i]; i++;
    } while (i < 3);

    if (150.0f < sum)
    {
      for (i = 0; 3 > i; i++)
      {
        o[i] *= D_8007FA68;
      }

    }
  }
  cam->x = o[0];
  cam->y = o[1];
  cam->z = o[2];
  cam->ex = cam->tx + o[0];
  cam->ey = o[1] + cam->ty;
  cam->ez = cam->tz + o[2];
  func_80022E64(cam);
}
