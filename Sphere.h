#ifndef GRRAPHIC_SPHERE_H
#define GRRAPHIC_SPHERE_H

#include "Vec3.h"

class Sphere {
public:
  Vec3 o;
  double r;
  Color color;

  Sphere (double x, double y, double z, double r, Color c);
  Sphere (Vec3 v, double r, Color c);
};

Vec3 crossing (Sphere &sphere, Vec3 &vec);

#endif
