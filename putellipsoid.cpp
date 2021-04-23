#include "scuptor.h"
#include "figurageometrica.h"
#include "putellipsoid.h"

putEllipsoid::putEllipsoid(int x, int xr, int y, int yr, int z, int zr, float r, float g, float b, float a){
    this->x=x; this->xr=xr; this->y=y; this->yr=yr; this->z=z; this->zr=zr;
    this->r=r; this->g=g; this->b=b; this->a=a;
};

void putEllipsoid::draw(scuptor &asd){
    asd.setColor(r, g, b);
    asd.putEllipsoid(x, xr, y, yr, z, zr);
};
