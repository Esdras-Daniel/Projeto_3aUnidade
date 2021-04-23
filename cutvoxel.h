#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "scuptor.h"
#include "figurageometrica.h"

class cutVoxel : public figurageometrica{
    int x,y,z;

    public:
    cutVoxel(int x, int y, int z);
    void draw(scuptor &asd);
};

#endif // CUTVOXEL_H
