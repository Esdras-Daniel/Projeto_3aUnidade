#ifndef CUTBOX_H
#define CUTBOX_H

#include "scuptor.h"
#include "figurageometrica.h"

class cutBox : public figurageometrica{
    int x0, x1, y0, y1, z0, z1;
    public:

    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void draw(scuptor &asd);
};

#endif // CUTBOX_H
