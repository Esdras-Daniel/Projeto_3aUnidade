#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "scuptor.h"
#include "figurageometrica.h"

class putSphere : public figurageometrica{
    int x, y, z, radius;
    public:

    putSphere(int x, int y, int z, int radius, float r, float g, float b, float a);

    void draw(scuptor &asd);
};

#endif // PUTSPHERE_H
