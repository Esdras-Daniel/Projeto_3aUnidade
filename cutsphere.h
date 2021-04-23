#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "scuptor.h"
#include "figurageometrica.h"

class cutSphere : public figurageometrica{
    int x, y, z, radius;
    public:

    cutSphere(int x, int y, int z, int radius);
    void draw(scuptor &asd);
};

#endif // CUTSPHERE_H
