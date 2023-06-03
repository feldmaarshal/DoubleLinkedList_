#include "Circle.hpp"

// Конструкторы

Circle::Circle() : center(){
    this->radius = 0;
    //printf("Конструктор по умолчанию класса Circle\n");
}

Circle::Circle(const Circle& other): center(other.center) {
    this->radius = other.radius;
    //printf("Конструтор копирования класса Circle(for Circle)\n");
}


Circle::Circle(int radius, int x, int y): center(x, y){
    this->radius = radius;
    //printf("Вызвался конструктор класса Circle\n");
}

// Методы

void Circle::Inflate(int value) {
    std::cout << "Circle inflated by " << value << std::endl;
}

// методы
bool Circle::operator==(Circle* other){
    if (this->radius == other->radius &&
        this->center.GetX() == other->center.GetX() &&
        this->center.GetY() == other->center.GetY()) {
        return true;
    }
    return false;
}

bool Circle::operator>(Circle other){
    if(this->radius > other.radius){
        return true;
    }
    return false;
}


Circle& Circle::operator=(Circle other){
    this->radius = other.radius;
    this->center.SetX(other.center.GetX());
    this->center.SetY(other.center.GetY());
    return *this;
}
