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

double dot(const Vec3 &a, const Vec3 &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
double cos(const Vec3 &a, const Vec3 &b) {
  return dot(a, b) / (a.length() * b.length());
}

/* Color */
Color::Color(double x, double y, double z) {
  this->x = x / 255;
  this->y = y / 255;
  this->z = z / 255;
}

int Color::r() {
  return (int)(this->x * 255);
}
int Color::g() {
  return (int)(this->y * 255);
}
int Color::b() {
  return (int)(this->z * 255);
}
