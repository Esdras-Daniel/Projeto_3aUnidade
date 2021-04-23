#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "scuptor.h"
#include "figurageometrica.h"

class putEllipsoid : public figurageometrica{
    int x, xr, y, yr, z, zr;
    public:

    putEllipsoid(int x, int xr, int y, int yr, int z, int zr, float r, float g, float b, float a);
    void draw(scuptor &asd);
};

#endif // PUTELLIPSOID_H
