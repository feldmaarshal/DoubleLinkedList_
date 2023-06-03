#include <cstdio>
#include "Point.hpp"
#include <iostream>

class Circle{
private:
    int radius;
    Point center;
public:
    Circle();
    Circle(const Circle& other);
    Circle(int radius, int x, int y);
    
    int Get_radius() { return radius; }
    void Set_radius(int x){this->radius = x;}
    Point Get_center() {return center;}
    
    void WhereAmI(){ printf("Now I am in class Circle\n"); }
    void Inflate(int);
    
    bool operator==(Circle* other);
    Circle& operator=(Circle other);
    bool operator>(Circle other);
    
    ~Circle() { /*printf("Now I am in Circle's destructor!\n" );*/ }
};
