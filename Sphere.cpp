#include "Sphere.h"
#include <cmath>

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

Vec3 crossing (Sphere &sphere, Vec3 &vec) {
  double k1 = dot(vec, vec),
         k2 = dot(vec, sphere.o),
         k3 = dot(sphere.o, sphere.o);

  double D = k2*k2 + k1*(sphere.r*sphere.r - k3);

  if (D < 0) return Vec3(0, 0, 0);
  D = sqrt(D);

  double ans1 = (k2 - D) / k1,
         ans2 = (k2 + D) / k1;

  if (ans1 >= 1) return (vec * ans1);
  if (ans2 >= 1) return (vec * ans2);

  return Vec3(0, 0, 0);
}
