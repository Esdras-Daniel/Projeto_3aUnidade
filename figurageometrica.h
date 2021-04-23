#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "scuptor.h"
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include"scuptor.h"

class figurageometrica{
  protected:
  float r,g,b,a;
  public:
  virtual ~figurageometrica(){};
  virtual void draw(scuptor &asd)=0;
};

#endif // FIGURAGEOMETRICA_H
