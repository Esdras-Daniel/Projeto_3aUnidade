#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "interpretador.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

// seleciona o arquivo a ser interpretado
interpretador::interpretador(){

    }

vector<figurageometrica*> interpretador::parse(string endereco_arquivo){
    vector<figurageometrica*> figs;

    ifstream entrada;
    string s, token;
    stringstream ss;

    entrada.open(endereco_arquivo.c_str());

    while(entrada.good()){
        getline(entrada,s);

        if(entrada.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if (token.compare("dim") == 0){
                    ss >> x >> y >> z;
                }
                else if(token.compare("putvoxel")==0){
                    int x_,y_,z_;
                    float r,g,b,a;
                    ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
                    figs.push_back(new putVoxel(x_, y_, z_, r, g, b, a));
                }
                else if(token.compare("cutvoxel")==0){
                    int x_,y_,z_;
                    ss >> x_ >> y_ >> z_;
                    figs.push_back(new cutVoxel(x_, y_, z_));
                }
                else if(token.compare("putbox")==0){
                    int x0_, x1_, y0_, y1_, z0_, z1_;
                    float r, g, b, a;
                    ss >> x0_ >> x1_ >> y0_ >> y1_ >> z0_ >> z1_ >> r >> g >> b >> a;
                    figs.push_back(new putBox(x0_, x1_, y0_, y1_, z0_, z1_, r, g, b, a));
                }
                else if(token.compare("cutbox")==0){
                    int x0_, x1_, y0_, y1_, z0_, z1_;
                    ss >> x0_ >> x1_ >> y0_ >> y1_ >> z0_ >> z1_;
                    figs.push_back(new cutBox(x0_, x1_, y0_, y1_, z0_, z1_));
                }
                else if(token.compare("putsphere")==0){
                    int x, y, z, radius;
                    float r, g, b, a;
                    ss >> x >> y >> z >> radius >> r >> g >> b >> a;
                    figs.push_back(new putSphere(x, y, z, radius, r, g, b, a));
                }
                else if(token.compare("cutsphere")==0){
                    int x, y, z, radius;
                    ss >> x >> y >> z >> radius;
                    figs.push_back(new cutSphere(x, y, z, radius));
                }
                else if(token.compare("putellipsoid")==0){
                    int x, xr, y, yr, z, zr;
                    float r, g, b, a;
                    ss >> x >> xr >> y >> yr >> z >> zr >> r >> g >> b >> a;
                    figs.push_back(new putEllipsoid(x, xr, y, yr, z, zr, r, g, b, a));
                }
                else if(token.compare("cutellipsoid")==0){
                    int x, xr, y, yr, z, zr;
                    ss >> x >> xr >> y >> yr >> z >> zr;
                    figs.push_back(new cutEllipsoid(x, xr, y, yr, z, zr));
                }
            }
        }
    }
    return (figs);
};

int interpretador::getZ(){
    return z;
};

int interpretador::getY(){
    return y;
};

int interpretador::getX(){
    return x;
};
