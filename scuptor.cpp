#include "scuptor.h"
#include"iostream"
#include<fstream>
#include<math.h>
using namespace std;

scuptor::scuptor( int x_,int y_,int z_){
    X = x_;   Y = y_;    Z = z_;

    t = new voxel_final**[X];

    for (int i = 0; i < X; i++){
        t[i] = new voxel_final*[Y];

        for (int j = 0; j < Y; j++)
            t[i][j] = new voxel_final[Z];
    }

    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                t[i][j][k].cubo.a = 0;
            }
        }
    }
}


void scuptor::writeOFF(){
    ofstream file;
    string copia;
    file.open("C:\\Users\\Esdras Daniel\\Desktop\\barad-dur.off"); //apaga o que tem no arquivo
    //file.open("C:\\Users\\estud\\Downloads\\tt.off",ios::app);

    file<<"OFF\n";
    int t_cubos = 0;
    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                if(t[i][j][k].cubo.a == 1){
                    t_cubos++;
                }
            }
        }
    }

    file<<8*t_cubos<<" "<<6*t_cubos<<" "<<0<<endl;

    // vertices
    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                if(t[i][j][k].cubo.a == 1){

                    // vertice 1
                    t[i][j][k].vertice[0].xp = -0.5+1*(i);
                    t[i][j][k].vertice[0].yp =  0.5+1*(j);
                    t[i][j][k].vertice[0].zp = -0.5+1*(k);

                    file<< t[i][j][k].vertice[0].xp<<" "<< t[i][j][k].vertice[0].yp<<" "<<t[i][j][k].vertice[0].zp<<"\n";

                    //vertice 2
                    t[i][j][k].vertice[1].xp = -0.5+1*(i);
                    t[i][j][k].vertice[1].yp = -0.5+1*(j);
                    t[i][j][k].vertice[1].zp = -0.5+1*(k);

                    file<< t[i][j][k].vertice[1].xp<<" "<< t[i][j][k].vertice[1].yp<<" "<<t[i][j][k].vertice[1].zp<<"\n";

                    //vertice 3

                    t[i][j][k].vertice[2].xp =  0.5+1*(i);
                    t[i][j][k].vertice[2].yp = -0.5+1*(j);
                    t[i][j][k].vertice[2].zp = -0.5+1*(k);

                    file<< t[i][j][k].vertice[2].xp<<" "<< t[i][j][k].vertice[2].yp<<" "<<t[i][j][k].vertice[2].zp<<"\n";

                    //vertice 4
                    t[i][j][k].vertice[3].xp =  0.5+1*(i);
                    t[i][j][k].vertice[3].yp =  0.5+1*(j);
                    t[i][j][k].vertice[3].zp = -0.5+1*(k);

                    file<< t[i][j][k].vertice[3].xp<<" "<< t[i][j][k].vertice[3].yp<<" "<<t[i][j][k].vertice[3].zp<<"\n";

                    // vertice 5
                    t[i][j][k].vertice[4].xp = -0.5+1*(i);
                    t[i][j][k].vertice[4].yp =  0.5+1*(j);
                    t[i][j][k].vertice[4].zp =  0.5+1*(k);

                    file<< t[i][j][k].vertice[4].xp<<" "<< t[i][j][k].vertice[4].yp<<" "<<t[i][j][k].vertice[4].zp<<"\n";

                    //vertice 6
                    t[i][j][k].vertice[5].xp = -0.5+1*(i);
                    t[i][j][k].vertice[5].yp = -0.5+1*(j);
                    t[i][j][k].vertice[5].zp =  0.5+1*(k);

                    file<< t[i][j][k].vertice[5].xp<<" "<< t[i][j][k].vertice[5].yp<<" "<<t[i][j][k].vertice[5].zp<<"\n";

                    //vertice 7
                    t[i][j][k].vertice[6].xp =  0.5+1*(i);
                    t[i][j][k].vertice[6].yp = -0.5+1*(j);
                    t[i][j][k].vertice[6].zp =  0.5+1*(k);

                    file<< t[i][j][k].vertice[6].xp<<" "<< t[i][j][k].vertice[6].yp<<" "<<t[i][j][k].vertice[6].zp<<"\n";

                    //vertice 8
                    t[i][j][k].vertice[7].xp =  0.5+1*(i);
                    t[i][j][k].vertice[7].yp =  0.5+1*(j);
                    t[i][j][k].vertice[7].zp =  0.5+1*(k);

                    file<< t[i][j][k].vertice[7].xp<<" "<< t[i][j][k].vertice[7].yp<<" "<<t[i][j][k].vertice[7].zp<<"\n";

                }
            }
        }
    }

    //planos
    int c= 0 ;
    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                if(t[i][j][k].cubo.a == 1){

                   t[i][j][k].plano[0].a = 4;
                   t[i][j][k].plano[0].p0 = 0+8*c;
                   t[i][j][k].plano[0].p1 = 3+8*c;
                   t[i][j][k].plano[0].p2 = 2+8*c;
                   t[i][j][k].plano[0].p3 = 1+8*c;

                   t[i][j][k].plano[1].a = 4;
                   t[i][j][k].plano[1].p0 = 4+8*c;
                   t[i][j][k].plano[1].p1 = 5+8*c;
                   t[i][j][k].plano[1].p2 = 6+8*c;
                   t[i][j][k].plano[1].p3 = 7+8*c;

                   t[i][j][k].plano[2].a = 4;
                   t[i][j][k].plano[2].p0 = 0+8*c;
                   t[i][j][k].plano[2].p1 = 1+8*c;
                   t[i][j][k].plano[2].p2 = 5+8*c;
                   t[i][j][k].plano[2].p3 = 4+8*c;

                   t[i][j][k].plano[3].a = 4;
                   t[i][j][k].plano[3].p0 = 0+8*c;
                   t[i][j][k].plano[3].p1 = 4+8*c;
                   t[i][j][k].plano[3].p2 = 7+8*c;
                   t[i][j][k].plano[3].p3 = 3+8*c;

                   t[i][j][k].plano[4].a = 4;
                   t[i][j][k].plano[4].p0 = 7+8*c;
                   t[i][j][k].plano[4].p1 = 6+8*c;
                   t[i][j][k].plano[4].p2 = 2+8*c;
                   t[i][j][k].plano[4].p3 = 3+8*c;

                   t[i][j][k].plano[5].a = 4;
                   t[i][j][k].plano[5].p0 = 1+8*c;
                   t[i][j][k].plano[5].p1 = 2+8*c;
                   t[i][j][k].plano[5].p2 = 6+8*c;
                   t[i][j][k].plano[5].p3 = 5+8*c;

                   c++;
                }
            }
        }
    }

    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                if(t[i][j][k].cubo.a == 1){
                    file<<t[i][j][k].plano[0].a<<" "<<t[i][j][k].plano[0].p0<<" "<<t[i][j][k].plano[0].p1<<" "<<t[i][j][k].plano[0].p2<<" "<<t[i][j][k].plano[0].p3<<" ";
                    file<<t[i][j][k].cubo.r<<" "<<t[i][j][k].cubo.g<<" "<<t[i][j][k].cubo.b<<" " <<1<<"\n";

                    file<<t[i][j][k].plano[1].a<<" "<<t[i][j][k].plano[1].p0<<" "<<t[i][j][k].plano[1].p1<<" "<<t[i][j][k].plano[1].p2<<" "<<t[i][j][k].plano[1].p3<<" ";
                    file<<t[i][j][k].cubo.r<<" "<<t[i][j][k].cubo.g<<" "<<t[i][j][k].cubo.b<<" " <<1<<"\n";

                    file<<t[i][j][k].plano[2].a<<" "<<t[i][j][k].plano[2].p0<<" "<<t[i][j][k].plano[2].p1<<" "<<t[i][j][k].plano[2].p2<<" "<<t[i][j][k].plano[2].p3<<" ";
                    file<<t[i][j][k].cubo.r<<" "<<t[i][j][k].cubo.g<<" "<<t[i][j][k].cubo.b<<" " <<1<<"\n";

                    file<<t[i][j][k].plano[3].a<<" "<<t[i][j][k].plano[3].p0<<" "<<t[i][j][k].plano[3].p1<<" "<<t[i][j][k].plano[3].p2<<" "<<t[i][j][k].plano[3].p3<<" ";
                    file<<t[i][j][k].cubo.r<<" "<<t[i][j][k].cubo.g<<" "<<t[i][j][k].cubo.b<<" " <<1<<"\n";

                    file<<t[i][j][k].plano[4].a<<" "<<t[i][j][k].plano[4].p0<<" "<<t[i][j][k].plano[4].p1<<" "<<t[i][j][k].plano[4].p2<<" "<<t[i][j][k].plano[4].p3<<" ";
                    file<<t[i][j][k].cubo.r<<" "<<t[i][j][k].cubo.g<<" "<<t[i][j][k].cubo.b<<" " <<1<<"\n";

                    file<<t[i][j][k].plano[5].a<<" "<<t[i][j][k].plano[5].p0<<" "<<t[i][j][k].plano[5].p1<<" "<<t[i][j][k].plano[5].p2<<" "<<t[i][j][k].plano[5].p3<<" ";
                    file<<t[i][j][k].cubo.r<<" "<<t[i][j][k].cubo.g<<" "<<t[i][j][k].cubo.b<<" " <<1<<"\n";
                }
            }
        }
    }
};

void scuptor::putVoxel(int i, int j, int k){
     t[i][j][k].cubo.a = 1;
     t[i][j][k].cubo.r = r;
     t[i][j][k].cubo.g = g;
     t[i][j][k].cubo.b = b;
};

void scuptor::setColor(float r_, float g_, float b_){
    r = r_; g = g_; b = b_;
};

void scuptor::cutVoxel(int x, int y, int z){
    t[x][y][z].cubo.a = 0;
};

void scuptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int  k = z0 ; k <= z1;k++){
        for(int j = y0 ; j <= y1;j++){
            for( int i = x0; i <= x1;i++){
                t[i][j][k].cubo.a = 1;
                t[i][j][k].cubo.r = r;
                t[i][j][k].cubo.g = g;
                t[i][j][k].cubo.b = b;
            }
        }
    }
};

void scuptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int  k = z0 ; k <= z1;k++){
        for(int j = y0 ; j <= y1;j++){
            for( int i = x0; i <= x1;i++){
                t[i][j][k].cubo.a = 0;
            }
        }
    }
};

void scuptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                if(sqrt(pow(i - xcenter,2)+pow(j - ycenter,2)+pow(k - zcenter,2))<= radius){
                    t[i][j][k].cubo.a = 1;
                    t[i][j][k].cubo.r = r;
                    t[i][j][k].cubo.g = g;
                    t[i][j][k].cubo.b = b;
                }
            }
        }
    }
};

void scuptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int k = 0; k < Z;k++){
        for(int j = 0; j < Y;j++){
            for(int i = 0; i < X;i++){
                if(sqrt(pow(i - xcenter,2)+pow(j - ycenter,2)+pow(k - zcenter,2))<= radius){
                    t[i][j][k].cubo.a = 0;
                }
            }
        }
    }
};

void scuptor::putEllipsoid(int xcenter, int rx, int ycenter, int ry, int zcenter, int rz){
    float dx, dy, dz;
    for(int k = 0; k < Z; k++){
        for(int j = 0; j < Y; j++){
            for(int i = 0; i < X; i++){
                dx = (float)(i - xcenter)* (float)(i - xcenter);
                dy = (float)(j - ycenter)* (float)(j - ycenter);
                dz = (float)(k - zcenter)* (float)(k - zcenter);
                if((dx/rx/rx) + (dy/ry/ry) + (dz/rz/rz) <= 1){
                    t[i][j][k].cubo.a = 1;
                    t[i][j][k].cubo.r = r;
                    t[i][j][k].cubo.g = g;
                    t[i][j][k].cubo.b = b;
                }
            }
        }
    }
};

void scuptor::cutEllipsoid(int xcenter, int rx, int ycenter, int ry, int zcenter, int rz){
    float dx, dy, dz;
    for(int k = 0; k < Z; k++){
        for(int j = 0; j < Y; j++){
            for(int i = 0; i < X; i++){
                dx = (float)(i - xcenter)* (float)(i - xcenter);
                dy = (float)(j - ycenter)* (float)(j - ycenter);
                dz = (float)(k - zcenter)* (float)(k - zcenter);
                if((dx/rx/rx) + (dy/ry/ry) + (dz/rz/rz) <= 1){
                    t[i][j][k].cubo.a = 0;
                }
            }
        }
    }
};
