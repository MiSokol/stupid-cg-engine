#ifndef GRAPHIC_VECTOR_H
#define GRAPHIC_VECTOR_H

class Vec3 {
public:
  double x, y, z;

  Vec3();
  Vec3(double x, double y, double z);

  Vec3 operator=(const Vec3 &v);

  Vec3 operator+(const Vec3 &v) const;
  Vec3 operator-(const Vec3 &v) const;
  Vec3 operator*(const double &n) const;

  double length() const;
};

double dot(const Vec3 &a, const Vec3 &b);
double cos(const Vec3 &a, const Vec3 &b);

#endif
