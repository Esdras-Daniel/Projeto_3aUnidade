#include"scuptor.h"
#include"figurageometrica.h"
#include "putvoxel.h"

putVoxel::putVoxel(int x,int y , int z, float r, float g, float b, float a){
  this->x=x;this->y=y;this->z=z;this->r=r;this->g=g;this->b=b;this->a=a;

};

void putVoxel::draw(scuptor &asd){

  asd.setColor(r, g, b);
  asd.putVoxel(x, y, z);

};
