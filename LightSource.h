#ifndef GRAPHIC_LIGHT_SOURCE_H
#define GRAPHIC_LIGHT_SOURCE_H

#include "Vec3.h"

class LightSource {
public:
  Vec3 o;
  Color color;

  LightSource() {};
  LightSource(double x, double y, double z, Color c);
  LightSource(Vec3 v, Color c);
};

#endif
