#include"interpretador.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include"figurageometrica.h"
#include"putvoxel.h"

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
                        cout<<x_<<" "<<y_<<" "<<z_<<" "<<r<<" "<<g<<" "<<b<<" "<<a << endl;
                        figs.push_back(new putVoxel(x_, y_, z_, r, g, b, a));
                    }
                    /*else if(token.compare("cutvoxel")==0){
                        int x_,y_,z_;
                        ss >> x_ >> y_ >> z_;
                        cout<<x_<<" "<<y_<<" "<<z_<< endl;
                        figs.push_back(new cutVoxel(x_, y_, z_));
                    }*/
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



/*
int interpretador::getY(){

return y;
};

int interpretador::getX(){

return x ;
};






entrada.close();
}

};*/
