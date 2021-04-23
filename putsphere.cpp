#include "scuptor.h"
#include "figurageometrica.h"
#include "putsphere.h"

putSphere::putSphere(int x, int y, int z, int radius, float r, float g, float b, float a){
    this->x=x; this->y=y; this->z=z; this->radius=radius;
    this->r=r; this->g=g; this->b=b; this->a=a;
};

void putSphere::draw(scuptor &asd){
    asd.setColor(r, g, b);
    asd.putSphere(x, y, z, radius);
};
