#include "LightSource.h"

LightSource::LightSource(double x, double y, double z, Color c) {
  this->o.x = x;
  this->o.y = y;
  this->o.z = z;
  this->color = c;
}

LightSource::LightSource(Vec3 v, Color c) {
  this->o = v;
  this->color = c;
}
