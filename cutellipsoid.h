#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "scuptor.h"
#include "figurageometrica.h"

class cutEllipsoid : public figurageometrica{
    int x, xr, y, yr, z, zr;
    public:

    cutEllipsoid(int x, int xr, int y, int yr, int z, int zr);
    void draw(scuptor &asd);
};


#endif // CUTELLIPSOID_H
