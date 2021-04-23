#include "scuptor.h"
#include "figurageometrica.h"
#include "cutsphere.h"

cutSphere::cutSphere(int x, int y, int z, int radius){
    this->x=x; this->y=y; this->z=z; this->radius=radius;
};

void cutSphere::draw(scuptor &asd){
    asd.cutSphere(x, y, z, radius);
};
