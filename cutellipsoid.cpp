#include "scuptor.h"
#include "figurageometrica.h"
#include "cutellipsoid.h"

cutEllipsoid::cutEllipsoid(int x, int xr, int y, int yr, int z, int zr){
    this->x=x; this->xr=xr; this->y=y; this->yr=yr; this->z=z; this->zr=zr;
};

void cutEllipsoid::draw(scuptor &asd){
    asd.cutEllipsoid(x, xr, y, yr, z, zr);
};
