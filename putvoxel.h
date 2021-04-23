#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "scuptor.h"
#include "figurageometrica.h"

class putVoxel : public figurageometrica{
    int x, y, z;
    public:

    putVoxel(int x, int y, int z, float r, float g, float b, float a);
    void draw(scuptor &asd);
};

#endif // PUTVOXEL_H
