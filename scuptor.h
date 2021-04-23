#ifndef SCUPTOR_H
#define SCUPTOR_H

struct ponto{
    float xp,yp,zp;
};

struct face{
    float a,p0,p1,p2,p3;
};

struct voxel{
    float r,g,b;
    float a ;
};

struct voxel_final{
    struct ponto vertice[8];
    struct face plano[6];
    struct voxel cubo;
};


class scuptor{
    private:

    voxel_final *** t;
    float r,g,b;
    int X,Y,Z;

    public:
        scuptor(int x_,int y_,int z_ );
        void writeOFF();
        void putVoxel(int x, int y, int z);
        void setColor(float r_, float g_, float b_);
        void cutVoxel(int x, int y, int z);
        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void putSphere(int xcenter, int ycenter, int zcenter, int radius);
        void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
        void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
};

#endif // SCUPTOR_H
