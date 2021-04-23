#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include "scuptor.h"
#include "interpretador.h"
#include <vector>
#include "figurageometrica.h"
#include "putvoxel.h"

using namespace std; 

int main (){
    //seleciona o arquivo a ser interpretado
    interpretador d;

    scuptor *s1;
  
    vector<figurageometrica*>figs;

    figs = d.parse("C:\\Users\\Esdras Daniel\\Desktop\\entrada.txt");

    s1 = new scuptor(d.getX(),d.getY(),d.getZ());

    for(size_t i = 0; i < figs.size(); i++){
        figs[i]->draw(*s1);
    }

    s1->writeOFF();

    for(size_t i = 0; i < figs.size(); i++){
        delete figs[i];
    }

    delete s1;

    return 0;
}
 
