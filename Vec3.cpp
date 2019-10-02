#include "Vec3.h"
#include <cmath>

Vec3::Vec3(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vec3 Vec3::operator=(const Vec3 &v) {
  this->x = v.x;
  this->y = v.y;
  this->z = v.z;
  return v;
}

Vec3 Vec3::operator+(const Vec3 &v) const {
  return Vec3(
    this->x + v.x,
    this->y + v.y,
    this->z + v.z
  );
}
Vec3 Vec3::operator-(const Vec3 &v) const {
  return Vec3(
    this->x - v.x,
    this->y - v.y,
    this->z - v.z
  );
}
Vec3 Vec3::operator*(const double &n) const {
  return Vec3(
    this->x*n,
    this->y*n,
    this->z*n
  );
}

double Vec3::length() const {
  return sqrt((this->x*this->x) + (this->y*this->y) + (this->z*this->z));
}
