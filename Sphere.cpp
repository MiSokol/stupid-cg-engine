#include "Sphere.h"

Sphere::Sphere(double x, double y, double z, double r, Color c) {
  this->o.x = x;
  this->o.y = y;
  this->o.z = z;
  this->r = r;
  this->color = c;
}
Sphere::Sphere(Vec3 v, double r, Color c) {
  this->o = v;
  this->r = r;
  this->color = c;
}
