#include <iostream>
using namespace std;

class area{
        double dim1, dim2; // dimensions of figure
    public:
        void set_area(double d1, double d2){
            dim1 = d1;
            dim2 = d2;
        }

        void get_dim(double &d1, double &d2){
            d1 = dim1;
            d2 = dim2;
        }

        virtual double get_area() = 0; // pure virtual function -> doesn't have any implementation in base class
};

class rectangle : public area{
    public:
        double get_area(){
            double d1, d2;
            get_dim(d1, d2);
            return d1 * d2;
        }
};

class triangle : public area{
    public:
        double get_area(){
            double d1, d2;
            get_dim(d1, d2);
            return 0.5 * d1 * d2;
        }
};

int main(){
    area *p;
    rectangle *r;
    triangle t;

    r.set_area(3.3, 4.5);
    t.set_area(4.0, 5.0);
    
    p = &r;
    cout << "Rectangle has area : " << p->get_area() << endl;
    
    p = &t;
    cout << "Triangle has area : " << p->get_area() << endl;
    
return 0;
}