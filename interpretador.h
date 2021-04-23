#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include<vector>
#include<string>
#include<fstream>
#include"figurageometrica.h"

class interpretador{
  private:
  int x,y,z= 0;

  public:
  interpretador();
  std::vector<figurageometrica*> parse(std::string nome_arquivo);
  int getZ();
  int getY();
  int getX();

};

#endif // INTERPRETADOR_H
