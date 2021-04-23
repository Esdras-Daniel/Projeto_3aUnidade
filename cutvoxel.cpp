#include "scuptor.h"
#include "figurageometrica.h"
#include "cutvoxel.h"

cutVoxel::cutVoxel(int x,int y , int z){
    this->x=x; this->y=y; this->z=z;
};

void cutVoxel::draw(scuptor &asd){
    asd.cutVoxel(x, y, z);
}
